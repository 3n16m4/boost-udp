#ifndef BOOST_UDP_USER_INTERFACE_HPP
#define BOOST_UDP_USER_INTERFACE_HPP

#include "player_stats.hpp"

#include <boost/asio.hpp>

using namespace nlohmann;
using namespace boost::asio;

namespace andromeda {
    class user_interface final {
      public:
        explicit user_interface(boost::asio::io_service &io_service) : _socket(io_service) {
        }
        ~user_interface() {
            _socket.close();
        }

        void init(const std::string &ip, uint16_t port) {
            _socket.open(ip::udp::v4());
            _endpoint = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(ip), port);
        }

        std::size_t send_data(const std::string &data) {
            boost::system::error_code err;
            return _socket.send_to(boost::asio::buffer(data, data.size()), _endpoint, 0, err);
        }

        std::size_t send_player_stats(const andromeda::player_stats_t &ps) {
            json j = ps;
            std::stringstream ss;
            ss << j;
            return send_data(ss.str());
        }

      private:
        boost::asio::ip::udp::socket _socket;
        boost::asio::ip::udp::endpoint _endpoint;
    };
} // namespace andromeda

#endif // BOOST_UDP_USER_INTERFACE_HPP
