///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   Date: 12/12/2016
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_APP_CONSOLE_HELLO_MAIN_HPP
#define _STARA_APP_CONSOLE_HELLO_MAIN_HPP

#include "stara/console/getopt/Main.hpp"
#include "stara/app/console/hello/MainOpt.hpp"
#include "rete/network/ip/v6/Endpoint.hpp"
#include "rete/network/ip/v4/Endpoint.hpp"
#include "rete/network/ip/tcp/Transport.hpp"
#include "rete/network/os/Socket.hpp"
#include "rete/network/os/Sockets.hpp"
#include "rete/network/SocketStream.hpp"

namespace stara {
namespace app {
namespace console {
namespace hello {

typedef stara::console::getopt::MainImplements MainImplements;
typedef stara::console::getopt::Main MainExtends;
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
      m_port(8080),
      m_host("localhost"),
      m_request("GET / HTTP/1.0\n\n\n"),
      m_response("HTTP/1.0 200 OK\n\n\nHello\n") {
    }
    virtual ~Main() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char** argv, char** env) {
        int err = 0;
        if ((m_run)) {
            err = (this->*m_run)(argc, argv, env);
        } else {
            err = DefaultRun(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int IpTcpClientRun(int argc, char_t **argv, char_t **env) {
        int err = 0;
        rete::network::Sockets& sockets = this->Sockets(argc, argv, env);

        if ((sockets.Startup())) {
            rete::network::Endpoint& ep = this->Endpoint(argc, argv, env);

            if ((ep.AttachFirst(m_host, m_port))) {
                rete::network::Transport& tp = this->Transport(argc, argv, env);
                rete::network::Socket& sock = this->Socket(argc, argv, env);

                if ((sock.Open(tp))) {
                    if ((sock.Connect(ep))) {
                        ssize_t count = 0;
                        if (0 < (count = Send(sock, m_request))) {
                            Receive(sock);
                        }
                    }
                    sock.Close();
                }
                ep.Detach();
            }
            sockets.Cleanup();
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int IpTcpServerRun(int argc, char_t **argv, char_t **env) {
        int err = 0;
        rete::network::Sockets& sockets = this->Sockets(argc, argv, env);

        if ((sockets.Startup())) {
            rete::network::Endpoint& ep = this->Endpoint(argc, argv, env);

            if ((ep.Attach(m_port))) {
                rete::network::Transport& tp = this->Transport(argc, argv, env);
                rete::network::Socket& sock = this->Socket(argc, argv, env);

                if ((sock.Open(tp))) {
                    if ((sock.Listen(ep))) {
                        rete::network::Socket* accepted = 0;

                        if ((accepted = sock.Accept(ep))) {
                            Receive(*accepted);
                            Send(*accepted, m_response);
                            accepted->Close();
                        }
                    }
                    sock.Close();
                }
                ep.Detach();
            }
            sockets.Cleanup();
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int DefaultRun(int argc, char_t **argv, char_t **env) {
        int err = Usage(argc, argv, env);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Send(rete::network::Socket& sock, const String& string) {
        rete::network::SocketWriter writer(sock);
        ssize_t count = Write(writer, string);
        return count;
    }
    virtual ssize_t Write(rete::io::CharWriter& writer, const String& string) {
        ssize_t count = 0, amount = 0;
        size_t length = 0;
        const char* chars = 0;
        if ((chars = string.has_chars(length))) {
            do {
                length -= amount;
                if (0 < (amount = writer.Write(chars, length))) {
                    count += amount;
                    chars += amount;
                }
            } while ((0 < length) && (amount < length));
        }
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Receive(rete::network::Socket& sock) {
        rete::network::SocketReader reader(sock);
        ssize_t count = Read(reader);
        return count;
    }
    virtual ssize_t Read(rete::io::CharReader& reader) {
        ssize_t count = 0, amount = 0;
        do {
            if (0 < (amount = reader.Read(m_chars, sizeof(m_chars)))) {
                this->Out(m_chars, amount);
                count += amount;
            }
        } while (amount >= sizeof(m_chars));
        return count;
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
    IpTcpTransport(int argc, char_t **argv, char_t **env) {
        return m_tcp;
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
    virtual int OnClientOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        m_run = &Derives::IpTcpClientRun;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnServerOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        m_run = &Derives::IpTcpServerRun;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnHostOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            m_host.assign(optarg);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnPortOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            short port = 0;
            std::stringstream ss(optarg);
            if (0 < (ss >> port)) {
                m_port = port;
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnFamilyOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }

#include "stara/app/console/hello/MainOpt.cpp"
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef int (Derives::*MRun)(int argc, char_t **argv, char_t **env);
    typedef rete::network::Endpoint& (Derives::*MEndpoint)(int argc, char_t **argv, char_t **env);
    typedef rete::network::Transport& (Derives::*MTransport)(int argc, char_t **argv, char_t **env);

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    MRun m_run;
    MEndpoint m_endpoint;
    MTransport m_transport;
    short m_port;
    String m_host, m_request, m_response;
    rete::network::ip::v4::Endpoint m_ip4;
    rete::network::ip::v6::Endpoint m_ip6;
    rete::network::ip::tcp::Transport m_tcp;
    rete::network::os::Socket m_sock;
    rete::network::os::Sockets m_sockets;
    char m_chars[2049];
};

} // namespace hello 
} // namespace console 
} // namespace app 
} // namespace stara 

#endif // _STARA_APP_CONSOLE_HELLO_MAIN_HPP 
