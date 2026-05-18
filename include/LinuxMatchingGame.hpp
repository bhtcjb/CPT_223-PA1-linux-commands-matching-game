// Blake Turman
// Linux Command Matching Game wrapper

#ifndef LINUX_MATCHING_GAME_HPP
#define LINUX_MATCHING_GAME_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <random>
#include <filesystem>
#include <memory>

#include "LinkedList.hpp"
#include "CommandData.hpp"
#include "LeaderboardData.hpp"
#include "UserInputHandling.hpp"
#include "Console.hpp"

// Linux Commands Matching Game constants namepace
namespace LcmgParam {
    constexpr unsigned LB_SIZE = 3; // maximum leaderboard size
    constexpr unsigned NUM_ROUNDS = 20; // number of rounds per game, determines minimum commands required to play
    constexpr unsigned MAX_POINT = 5; // maximum points allowed per command
}

// wrapper class for the Linux Commands Matching game
class LinuxMatchingGame {
    public:
        LinuxMatchingGame(const std::string& commandFile = "data/commands.csv", const std::string& leaderboardFile = "data/leaderboard.csv")
            : commandFile(commandFile), leaderboardFile(leaderboardFile) {}
            
        ~LinuxMatchingGame();
        
        // runs application
        void runGame();

    private:
        std::string commandFile;
        std::string leaderboardFile;
        std::ifstream commandInFileStream;
        std::ifstream leaderboardInFileStream;
        std::ofstream commandOutFileStream;
        std::ofstream leaderboardOutFileStream;
        LinkedList<CommandData> commandList;
        LeaderboardData leaderboard[LcmgParam::LB_SIZE];

        // reads in commands and leaderboard files and stores data appropriately
        void readInFiles();

        // reads command file and populates command list
        // precond: command inFile stream is open
        //          file is formatted exactly correctly
        // format: command,"description",points
        void readInCommands();

        // reads leaderboard file and populates leaderboard array
        // precond: leaderboard inFile stream is open
        //          file is formatted exactly correctly
        // format: name,score
        void readInLeaderboard();

        // writes to command and leaderboard files from command and leaderboard lists
        // postcond: command and leaderboard files are overwritten
        void writeOutFiles();

        // writes entire commands list to file
        // precond: commands outFile stream is open
        // postcond: commands list is destroyed
        // format: command,"description",points
        void writeOutCommands();

        // writes leaderboard to file as far as array is populated
        // precond: leaderboard outFile stream is open
        // format: name,score
        void writeOutLeaderboard();

        // prompts user for menu selection, returns user selection
        unsigned menu();

        // prints menu options to screen
        void displayMenu();

        // prints game rules to screen
        void displayRules();

        // prompts user to enter their name, returns entered name
        std::string promptName();

        // updates and rolls leaderboard if input score is greater than or equal to another score
        // postcond: leaderboard array may be changed
        void updateLeaderboard(const std::string& name, const unsigned& score);

        // plays the main game
        // first prompts user to input name, then displays series of random unique commands
        // to which user responds with multiple choice answer, and lastly update 
        // leaderboard if player had a high enough score
        // precond: command list must have at least LcmgParam::NUM_ROUNDS elements
        void play();
        
        // prompts user to add command and corresponding description and points
        // if command is already in list, shows warning and exits
        // postcond: element may be added to command list
        void addCommand();

        // prompts user to remove a command in list, displays list
        // if list has LcmgParam::NUM_ROUNDS elements or less, shows warning and exits
        // if entered command is not found, shows warning and exits
        // postcond: element may be removed from command list
        void removeCommand();

        // prints all commands in list to screen
        void displayAllCommands();

        // prints leaderboard to screen
        void displayLeaderboards();
        
};



#endif