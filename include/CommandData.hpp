// Blake Turman
#ifndef COMMAND_DATA_HPP
#define COMMAND_DATA_HPP

#include <iostream>
#include <string>

// struct to encapsulate associated command data for the Linux Commands Matching Game
struct CommandData
{
    std::string command; // command itself
    std::string description; // description of the command
    unsigned points; // points that the command is worth

    CommandData(const std::string& command = "", const std::string& description = "", const unsigned& points = 0)
        : command(command), description(description), points(points) {}

    friend std::ostream& operator<<(std::ostream& lhs, const CommandData& rhs) {
        lhs << rhs.command << " (" << rhs.points << " points): " << rhs.description;
        return lhs;
    }
};


#endif