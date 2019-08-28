#ifndef BOOST_UDP_PLAYER_STATS_HPP
#define BOOST_UDP_PLAYER_STATS_HPP

#include "nlohmann/json.hpp"

using nlohmann::json;

namespace andromeda {
    typedef struct player_stats {
        int _hp;
        int _mp;
        int _exp;
    } player_stats_t;

    inline void to_json(json &j, const player_stats_t &p) {
        j = json{{"hp", p._hp}, {"mp", p._mp}, {"exp", p._exp}};
    }

    inline void from_json(const json &j, player_stats_t &p) {
        j.at("hp").get_to(p._hp);
        j.at("mp").get_to(p._mp);
        j.at("exp").get_to(p._exp);
    }
} // namespace andromeda

#endif // BOOST_UDP_PLAYER_STATS_HPP
