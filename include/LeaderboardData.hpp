// Blake Turman
#ifndef LEADERBOARD_DATA_HPP
#define LEADERBOARD_DATA_HPP

#include <string>
#include <iostream>

// struct to encapsulate associated leaderboard data for the Linux Commands Matching Game
struct LeaderboardData
{
    std::string name; // name of player
    unsigned score; // player's total score

    LeaderboardData(std::string name = "", unsigned score = 0)
        : name(name), score(score) {}

    friend std::ostream& operator<<(std::ostream& lhs, const LeaderboardData& rhs) {
        lhs << rhs.name << " Score: " << rhs.score;

        return lhs;
    }
};

#endif