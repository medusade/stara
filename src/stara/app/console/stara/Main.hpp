///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2019 $organization$
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
///   Date: 1/1/2019
///////////////////////////////////////////////////////////////////////
#ifndef _STARA_APP_CONSOLE_STARA_MAIN_HPP
#define _STARA_APP_CONSOLE_STARA_MAIN_HPP

#include "stara/app/console/stara/MainOpt.hpp"
#include "stara/protocol/xttp/request/Message.hpp"
#include "stara/protocol/xttp/response/Message.hpp"
#include "rete/network/ip/v6/Endpoint.hpp"
#include "rete/network/ip/v4/Endpoint.hpp"
#include "rete/network/ip/v6/tcp/Transport.hpp"
#include "rete/network/ip/v4/tcp/Transport.hpp"
#include "rete/network/ip/v6/udp/Transport.hpp"
#include "rete/network/ip/v4/udp/Transport.hpp"
#include "rete/network/os/Socket.hpp"
#include "rete/network/os/Sockets.hpp"
#include "rete/network/SocketStream.hpp"

namespace stara {
namespace app {
namespace console {
namespace stara {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
enum ServerAction {
    ServerContinue,
    ServerDone,
    ServerRestart
};

typedef MainOpt::Implements Main_implements;
typedef MainOpt Main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main: virtual public Main_implements, public Main_extends {
public:
    typedef Main_implements Implements;
    typedef Main_extends Extends;
    typedef Main Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Main(): m_run(0), 
      m_endpoint(0), m_transport(0),
      m_ip4Transport(0), m_ip6Transport(0),
      m_port(8080), m_host("localhost"),
      m_request("GET / HTTP/1.0\r\n\r\n"), 
      m_response("HTTP/1.0 200 OK\r\n\r\nHello\r\n") {
    }
    virtual ~Main() {
    }
private:
    Main(const Main& copy) {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    int (Derives::*m_run)(int argc, char_t **argv, char_t **env);
    virtual int Run(int argc, char** argv, char** env) {
        int err = 0;
        if ((m_run)) {
            err = (this->*m_run)(argc, argv, env);
        } else {
            err = DefaultRun(argc, argv, env);
        }
        return err;
    }
    virtual int DefaultRun(int argc, char_t **argv, char_t **env) {
        int err = 0;
        if (!(err = Extends::Run(argc, argv, env))) {
            Usage(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    int (Derives::*m_socketsRun)(int argc, char_t **argv, char_t **env);
    virtual int SocketsRun(int argc, char** argv, char** env) {
        ::rete::network::Sockets& sockets = this->Sockets(argc, argv, env);        
        int err = 0;
        if ((sockets.Startup())) {
            if ((m_socketsRun)) {
                err = (this->*m_socketsRun)(argc, argv, env);
            } else {
                err = DefaultSocketsRun(argc, argv, env);
            }
            sockets.Cleanup();
        }
        return err;
    }
    virtual int DefaultSocketsRun(int argc, char_t **argv, char_t **env) {
        int err = IpTcpClientRun(argc, argv, env);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int IpTcpClientRun(int argc, char_t **argv, char_t **env) {
        int err = 0;
        rete::network::Endpoint& ep = this->Endpoint(argc, argv, env);

        if ((ep.AttachFirst(m_host, m_port))) {
            rete::network::Transport& tp = this->Transport(argc, argv, env);
            rete::network::Socket& sock = this->Socket(argc, argv, env);

            if ((sock.Open(tp))) {
                if ((sock.Connect(ep))) {
                    ssize_t count = 0;

                    if (0 < (count = Send(sock, m_requestMessage))) {
                        RecvResponse(sock);
                    }
                }
                sock.Close();
            }
            ep.Detach();
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int IpTcpServerRun(int argc, char_t **argv, char_t **env) {
        int err = 0;
        rete::network::Endpoint& ep = this->Endpoint(argc, argv, env);

        if ((ep.Attach(m_port))) {
            rete::network::Transport& tp = this->Transport(argc, argv, env);
            rete::network::Socket& sock = this->Socket(argc, argv, env);

            if ((sock.Open(tp))) {
                if ((sock.Listen(ep))) {
                    ServerAction action = ServerDone;
                    rete::network::Socket* accepted = 0;

                    do {
                        if ((accepted = sock.Accept(ep))) {
                            RecvRequest(action, *accepted);
                        }
                    } while (ServerContinue == action);
                }
                sock.Close();
            }
            ep.Detach();
        }
        return err;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool RecvRequest(ServerAction& action, ::rete::network::Socket& sock) {
        ::rete::network::SocketReader reader(sock);
        bool success = false;
        ssize_t count = 0;
        if ((ReadRequest(m_requestMessage, count, reader))) {
            const ::stara::lib::Version& version = ::stara::lib::stara::Version::Which();
            m_response.assign(m_responseMessage);
            m_response.append("Hello");
            m_response.append(" ");
            m_response.append(version.Name());
            m_response.append(" version = ");
            m_response.append(version.ToString());
            m_response.append("\r\n");
            Send(sock, m_response);
            if (!(m_requestMessage.Line().Parameters().compare("/hello/"))) {
                action = ServerContinue;
            } else {
                action = ServerDone;
            }
            success = true;
        }
        sock.Close();
        return success;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool RecvResponse(rete::network::Socket& sock) {
        ::rete::network::SocketReader reader(sock);
        bool success = false;
        ssize_t count = 0;
        if ((ReadResponse(m_responseMessage, count, reader))) {
            success = true;
        }
        return success;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Send(::rete::network::Socket& sock, const String& string) {
        ::rete::network::SocketWriter writer(sock);
        ssize_t count = 0;
        bool success = Write(count, writer, string);
        return success;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool ReadRequest
    (protocol::xttp::request::Message& message,
     ssize_t& count, ::rete::io::CharReader& reader) {
        bool success = false;
        const char* chars = 0;
        ssize_t amount = 0;
        size_t length = 0;
        char c = 0;
        if ((message.Read(amount, c, reader))) {
            count += amount;
            if ((chars = message.has_chars(length))) {
                this->Out(chars, length);
            }
            if (0 < (length = message.ContentLength())) {
                do {
                    if (0 < (amount = reader.Read(m_chars, sizeof(m_chars)))) {
                        this->Out(m_chars, amount);
                        count += amount;
                        length -= amount;
                    } else {
                        success = false;
                    }
                } while ((0 < length) && (amount >= sizeof(m_chars)));
            }
            success = true;
        }
        return success;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool ReadResponse
    (protocol::xttp::response::Message& message,
     ssize_t& count, rete::io::CharReader& reader) {
        bool success = false;
        ssize_t amount = 0;
        char c = 0;
        if ((message.Read(amount, c, reader))) {
            const char* chars = 0;
            size_t length = 0;
            count += amount;
            if ((chars = message.has_chars(length))) {
                this->Out(chars, length);
            }
            if (0 < (length = message.ContentLength())) {
                do {
                    if (0 < (amount = reader.Read(m_chars, sizeof(m_chars)))) {
                        this->Out(m_chars, amount);
                        count += amount;
                        length -= amount;
                    } else {
                        success = false;
                    }
                } while ((0 < length) && (amount >= sizeof(m_chars)));
            }
            success = true;
        }
        return success;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Write
    (ssize_t& count, ::rete::io::CharWriter& writer, const String& string) {
        bool success = true;
        ssize_t amount = 0;
        size_t length = 0;
        const char* chars = 0;
        if ((chars = string.has_chars(length))) {
            count = 0;
            do {
                length -= amount;
                if (0 < (amount = writer.Write(chars, length))) {
                    count += amount;
                    chars += amount;
                }
            } while ((0 < length) && (amount < length));
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ::rete::network::Endpoint& (Derives::*m_endpoint)(int argc, char_t **argv, char_t **env);
    ::rete::network::Endpoint& Endpoint(int argc, char_t **argv, char_t **env) {
        if ((m_endpoint)) {
            return (this->*m_endpoint)(argc, argv, env);
        }
        return DefaultEndpoint(argc, argv, env);
    }
    virtual rete::network::Endpoint& DefaultEndpoint(int argc, char_t **argv, char_t **env) {
        return Ip4Endpoint(argc, argv, env);
    }
    virtual rete::network::Endpoint& Ip4Endpoint(int argc, char_t **argv, char_t **env) {
        return m_ip4;
    }
    virtual rete::network::Endpoint& Ip6Endpoint(int argc, char_t **argv, char_t **env) {
        return m_ip6;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ::rete::network::Transport& (Derives::*m_transport)(int argc, char_t **argv, char_t **env);
    virtual rete::network::Transport& Transport(int argc, char_t **argv, char_t **env) {
        if ((m_transport)) {
            return (this->*m_transport)(argc, argv, env);
        }
        return DefaultTransport(argc, argv, env);
    }
    virtual rete::network::Transport& DefaultTransport(int argc, char_t **argv, char_t **env) {
        return Ip4Transport(argc, argv, env);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ::rete::network::Transport& (Derives::*m_ip4Transport)(int argc, char_t **argv, char_t **env);
    virtual rete::network::Transport& Ip4Transport(int argc, char_t **argv, char_t **env) {
        if ((m_ip4Transport)) {
            return (this->*m_ip4Transport)(argc, argv, env);
        }
        return DefaultIp4Transport(argc, argv, env);
    }
    virtual rete::network::Transport& DefaultIp4Transport(int argc, char_t **argv, char_t **env) {
        return Ip4TcpTransport(argc, argv, env);
    }
    virtual rete::network::Transport& Ip4TcpTransport(int argc, char_t **argv, char_t **env) {
        return m_tcp4;
    }
    virtual rete::network::Transport& Ip4UdpTransport(int argc, char_t **argv, char_t **env) {
        return m_udp4;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ::rete::network::Transport& (Derives::*m_ip6Transport)(int argc, char_t **argv, char_t **env);
    virtual rete::network::Transport& Ip6Transport(int argc, char_t **argv, char_t **env) {
        if ((m_ip6Transport)) {
            return (this->*m_ip6Transport)(argc, argv, env);
        }
        return DefaultIp6Transport(argc, argv, env);
    }
    virtual rete::network::Transport& DefaultIp6Transport(int argc, char_t **argv, char_t **env) {
        return Ip6TcpTransport(argc, argv, env);
    }
    virtual rete::network::Transport& Ip6TcpTransport(int argc, char_t **argv, char_t **env) {
        return m_tcp6;
    }
    virtual rete::network::Transport& Ip6UdpTransport(int argc, char_t **argv, char_t **env) {
        return m_udp6;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ::rete::network::Socket& Socket(int argc, char_t **argv, char_t **env) {
        return m_sock;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ::rete::network::Sockets& Sockets(int argc, char_t **argv, char_t **env) {
        return m_sockets;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnClientOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        m_run = &Derives::SocketsRun;
        m_socketsRun = &Derives::IpTcpClientRun;
        return err;
    }
    virtual int OnServerOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        m_run = &Derives::SocketsRun;
        m_socketsRun = &Derives::IpTcpServerRun;
        return err;
    }
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
    virtual int OnPortOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            short port = 0;
            std::stringstream ss(optarg);
            ss >> port;
            if (0 < (port)) {
                m_port = port;
            }
        }
        return err;
    }
    virtual int OnFamilyOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!((optarg[1]) || (optarg[0] != STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG_C_IPV6[0])) 
                 || !(chars_t::compare(optarg, STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG_IPV6))) {
                m_endpoint = &Derives::Ip6Endpoint;
                m_transport = &Derives::Ip6Transport;
            } else {
                if (!((optarg[1]) || (optarg[0] != STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG_C_IPV4[0])) 
                     || !(chars_t::compare(optarg, STARA_APP_CONSOLE_STARA_MAIN_FAMILY_OPTARG_IPV4))) {
                    m_endpoint = &Derives::Ip4Endpoint;
                    m_transport = &Derives::Ip4Transport;
                } else {
                    err = OnInvalidOptionArg(optval, optarg, optname, optind, argc, argv, env);
                }
            }
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    short m_port;
    String m_host, m_request, m_response;
    protocol::xttp::request::Message m_requestMessage;
    protocol::xttp::response::Message m_responseMessage;
    ::rete::network::ip::v4::Endpoint m_ip4;
    ::rete::network::ip::v6::Endpoint m_ip6;
    ::rete::network::ip::v4::tcp::Transport m_tcp4;
    ::rete::network::ip::v4::udp::Transport m_udp4;
    ::rete::network::ip::v6::tcp::Transport m_tcp6;
    ::rete::network::ip::v6::udp::Transport m_udp6;
    ::rete::network::os::Socket m_sock;
    ::rete::network::os::Sockets m_sockets;
    char m_chars[2049];
}; /// class _EXPORT_CLASS Main

} /// namespace stara
} /// namespace console
} /// namespace app
} /// namespace stara

#endif ///ndef _STARA_APP_CONSOLE_STARA_MAIN_HPP
