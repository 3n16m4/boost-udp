#include "user_interface.hpp"
#include "player_stats.hpp"

#include <iostream>

int main() {
    using namespace andromeda;
    io_service io_service;
    user_interface userInterface{io_service};
    userInterface.init("127.0.0.1", 31337);

    player_stats_t playerStats{100, 50, 30};

    for (std::size_t i = 0; i < 4; ++i)
        std::cout << "sending " << userInterface.send_player_stats(playerStats) << " bytes." << '\n';

    return 0;
}