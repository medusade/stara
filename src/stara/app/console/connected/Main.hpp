///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: Main.hpp
///
/// Author: $author$
///   Date: 12/31/2018
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_APP_CONSOLE_CONNECTED_MAIN_HPP
#define _STARA_APP_CONSOLE_CONNECTED_MAIN_HPP

#include "stara/app/console/connected/MainOpt.hpp"
#include "stara/app/console/Main.hpp"
#include "rete/network/ip/v6/Endpoint.hpp"
#include "rete/network/ip/v4/Endpoint.hpp"
#include "rete/network/ip/tcp/Transport.hpp"
#include "rete/network/ip/udp/Transport.hpp"
#include "rete/network/local/Endpoint.hpp"
#include "rete/network/local/stream/Transport.hpp"
#include "rete/network/local/dgram/Transport.hpp"
#include "rete/network/os/Socket.hpp"
#include "rete/network/os/Sockets.hpp"
#include "rete/network/SocketStream.hpp"
#include "stara/io/Stream.hpp"

namespace stara {
namespace app {
namespace console {
namespace connected {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum RunAction {
    RunContinue,
    RunDone,
    RunRestart
};

typedef stara::app::console::MainImplements MainImplements;
typedef stara::app::console::Main MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main: virtual public MainImplements, public MainExtends {
public:
    typedef MainImplements Implements;
    typedef MainExtends Extends;
    typedef Main Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Main()
    : m_run(0),
      m_endpoint(0),
      m_transport(0),
      m_acceptPort("8080"), m_acceptPortNo(8080),
      m_host("localhost"), m_port(m_acceptPort),
      m_portNo(m_acceptPortNo), m_localPath(m_host) {
    }
    virtual ~Main() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef int (Derives::*MRun)(int argc, char** argv, char** env);
    typedef rete::network::Endpoint& (Derives::*MEndpoint)(int argc, char_t **argv, char_t **env);
    typedef rete::network::Transport& (Derives::*MTransport)(int argc, char_t **argv, char_t **env);

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    MRun m_run;
    MEndpoint m_endpoint;
    MTransport m_transport;
    String m_acceptHost, m_acceptPort; unsigned m_acceptPortNo;
    String m_host, m_port; unsigned m_portNo;
    String m_localPath;
    rete::network::ip::v4::Endpoint m_ip4;
    rete::network::ip::v6::Endpoint m_ip6;
    rete::network::ip::tcp::Transport m_tcp;
    rete::network::ip::tcp::Transport m_udp;
    rete::network::local::Endpoint m_local;
    rete::network::local::stream::Transport m_stream;
    rete::network::local::dgram::Transport m_dgram;
    rete::network::os::Socket m_sock;
    rete::network::os::Sockets m_sockets;

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char** argv, char** env) {
        int err = 0;
        if ((m_run)) {
            rete::network::Sockets& sockets = this->Sockets(argc, argv, env);
            if ((sockets.Startup())) {
                err = (this->*m_run)(argc, argv, env);
                sockets.Cleanup();
            }
        } else {
            err = Usage(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int IpTcpClientRun(int argc, char_t **argv, char_t **env) {
        int err = 0;
        RunAction action = RunDone;
        do {
            rete::network::Endpoint& ep = this->Endpoint(argc, argv, env);

            if ((ep.AttachFirst(m_host, m_portNo))) {
                rete::network::Transport& tp = this->Transport(argc, argv, env);
                rete::network::Socket& sock = this->Socket(argc, argv, env);

                if ((sock.Open(tp))) {
                    if ((sock.Connect(ep))) {

                        if ((SendRequest(action, sock))) {
                            ReceiveResponse(action, sock);
                        }
                    }
                    sock.Close();
                }
                ep.Detach();
            }
        } while (RunRestart == action);
        return err;
    }
    virtual MRun DefaultClientRun() const {
        return &Derives::IpTcpClientRun;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int IpTcpServerRun(int argc, char_t **argv, char_t **env) {
        int err = 0;
        RunAction action = RunDone;
        do {
            rete::network::Endpoint& ep = this->Endpoint(argc, argv, env);

            if ((ep.Attach(m_portNo))) {
                rete::network::Transport& tp = this->Transport(argc, argv, env);
                rete::network::Socket& sock = this->Socket(argc, argv, env);

                if ((sock.Open(tp))) {
                    if ((sock.Listen(ep))) {
                        rete::network::Socket* accepted = 0;

                        do {
                            if ((accepted = sock.Accept(ep))) {

                                if ((ReceiveRequest(action, *accepted))) {
                                    SendResponse(action, *accepted);
                                }
                            }
                        } while (RunContinue == action);
                    }
                    sock.Close();
                }
                ep.Detach();
            }
        } while (RunRestart == action);
        return err;
    }
    virtual MRun DefaultServerRun() const {
        return &Derives::IpTcpServerRun;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SendRequest
    (RunAction& action, rete::network::Socket& sock) {
        rete::network::SocketStream stream(sock);
        bool success = false;
        return success;
    }
    virtual bool ReceiveResponse
    (RunAction& action, rete::network::Socket& sock) {
        rete::network::SocketStream stream(sock);
        bool success = false;
        return success;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool ReceiveRequest
    (RunAction& action, rete::network::Socket& sock) {
        rete::network::SocketStream stream(sock);
        bool success = false;
        if ((BeforeRreadRequest(action, stream))) {
            if ((RreadRequest(action, stream))) {
                success = AfterRreadRequest(action, stream);
            }
        }
        return success;
    }
    virtual bool SendResponse
    (RunAction& action, rete::network::Socket& sock) {
        rete::network::SocketStream stream(sock);
        bool success = false;
        if ((BeforeWriteResponse(action, stream))) {
            if ((WriteResponse(action, stream))) {
                success = AfterWriteResponse(action, stream);
            }
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool RreadRequest
    (RunAction& action, stara::io::CharStream& stream) {
        bool success = false;
        return success;
    }
    virtual bool BeforeRreadRequest
    (RunAction& action, stara::io::CharStream& stream) {
        bool success = true;
        return success;
    }
    virtual bool AfterRreadRequest
    (RunAction& action, stara::io::CharStream& stream) {
        bool success = true;
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool WriteResponse
    (RunAction& action, stara::io::CharStream& stream) {
        bool success = false;
        return success;
    }
    virtual bool BeforeWriteResponse
    (RunAction& action, stara::io::CharStream& stream) {
        bool success = true;
        return success;
    }
    virtual bool AfterWriteResponse
    (RunAction& action, stara::io::CharStream& stream) {
        bool success = true;
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual rete::network::Endpoint&
    Endpoint(int argc, char_t **argv, char_t **env) {
        if ((m_endpoint)) {
            return (this->*m_endpoint)(argc, argv, env);
        }
        return DefaultEndpoint(argc, argv, env);
    }
    virtual rete::network::Endpoint&
    LocalEndpoint(int argc, char_t **argv, char_t **env) {
        return m_local;
    }
    virtual rete::network::Endpoint&
    Ip4Endpoint(int argc, char_t **argv, char_t **env) {
        return m_ip4;
    }
    virtual rete::network::Endpoint&
    Ip6Endpoint(int argc, char_t **argv, char_t **env) {
        return m_ip6;
    }
    virtual rete::network::Endpoint&
    DefaultEndpoint(int argc, char_t **argv, char_t **env) {
        return Ip4Endpoint(argc, argv, env);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual rete::network::Transport&
    Transport(int argc, char_t **argv, char_t **env) {
        if ((m_transport)) {
            return (this->*m_transport)(argc, argv, env);
        }
        return DefaultTransport(argc, argv, env);
    }
    virtual rete::network::Transport&
    LocalStreamTransport(int argc, char_t **argv, char_t **env) {
        return m_stream;
    }
    virtual rete::network::Transport&
    LocalDgramTransport(int argc, char_t **argv, char_t **env) {
        return m_dgram;
    }
    virtual rete::network::Transport&
    IpTcpTransport(int argc, char_t **argv, char_t **env) {
        return m_tcp;
    }
    virtual rete::network::Transport&
    IpUdpTransport(int argc, char_t **argv, char_t **env) {
        return m_udp;
    }
    virtual rete::network::Transport&
    DefaultTransport(int argc, char_t **argv, char_t **env) {
        return IpTcpTransport(argc, argv, env);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual rete::network::Socket&
    Socket(int argc, char_t **argv, char_t **env) {
        return m_sock;
    }
    virtual rete::network::Sockets&
    Sockets(int argc, char_t **argv, char_t **env) {
        return m_sockets;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int SetClient() {
        m_run = DefaultClientRun();
        return 0;
    }
    virtual int SetServer() {
        m_run = DefaultServerRun();
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int SetHost(const String& host) {
        return 0;
    }
    virtual int SetPort(const String& port, unsigned number) {
        m_port = port;
        m_portNo = number;
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int SetLocal() {
        return 0;
    }
    virtual int SetIpv4() {
        return 0;
    }
    virtual int SetIpv6() {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int SetStream() {
        return 0;
    }
    virtual int SetDgram() {
        return 0;
    }

#include "stara/app/console/connected/MainOpt.cpp"
};

} // namespace connected 
} // namespace console 
} // namespace app 
} // namespace stara 

#endif // _STARA_APP_CONSOLE_CONNECTED_MAIN_HPP 
