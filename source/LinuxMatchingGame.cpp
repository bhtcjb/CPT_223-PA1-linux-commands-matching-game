// Blake Turman
#include "LinuxMatchingGame.hpp"

// public

LinuxMatchingGame::~LinuxMatchingGame() {
    if (commandInFileStream.is_open()) {
        commandInFileStream.close();
    }
    if (commandOutFileStream.is_open()) {
        commandOutFileStream.close();
    }
    if (leaderboardInFileStream.is_open()) {
        leaderboardInFileStream.close();
    }
    if (leaderboardOutFileStream.is_open()) {
        leaderboardOutFileStream.close();
    }
};

void LinuxMatchingGame::runGame() {
    unsigned selection = 0;

    readInFiles();

    if (commandList.isEmpty()) {
        std::cerr << "Fatal Error: command list did not populate" << std::endl;
        selection = 7;
    }
    else if (commandList.getSize() < LcmgParam::NUM_ROUNDS) {
        std::cerr << "Fatal Error: not enough commands to play game" << std::endl;
        selection = 7;
    }

    while (selection != 7) {

        // prompt menu selection
        Console::clearScreen();
        selection = menu();
        Console::clearScreen();
        

        switch (selection) {
            case 1: displayRules();
                Console::pause();
                break;
            case 2: play();
                break;
            case 3: addCommand();
                break;
            case 4: removeCommand();
                break;
            case 5: displayAllCommands();
                Console::pause();
                break;
            case 6: displayLeaderboards();
                Console::pause();
                break;
            case 7: writeOutFiles();
                Console::clearScreen();
                std::cout << "Exiting ..." << std::endl << std::endl;
                break;
        }
    }
    

    
}

// private

void LinuxMatchingGame::readInFiles() {

    commandInFileStream.open(commandFile);
    if (commandInFileStream.is_open()) {
        readInCommands();
        commandInFileStream.close();
    }
    else {
        std::cerr << "Error: command file failed to open for reading" << std::endl;
    }
    leaderboardInFileStream.open(leaderboardFile);
    if (leaderboardInFileStream.is_open()) {
        readInLeaderboard();
        leaderboardInFileStream.close();
    }
    else {
        std::cerr << "Warning: leaderboard file failed to open for reading" << std::endl;
    }
    
}

void LinuxMatchingGame::readInCommands() {

    std::string command = "";
    std::string description = "";
    std::string points = "";

    // first operation in while condition, so stops immediately when reaching end of file
    while (getline(commandInFileStream, command, ',')) { 
           
        commandInFileStream.ignore(1); // ignore opening quote
        getline(commandInFileStream, description, '"');
        commandInFileStream.ignore(1); // ignore following comma

        getline(commandInFileStream, points);

        commandList.insert(CommandData{command, description, static_cast<unsigned>(std::stoul(points))});
    }

}

void LinuxMatchingGame::readInLeaderboard() {

    std::string score = "";

    for (size_t i = 0; i < LcmgParam::LB_SIZE && getline(leaderboardInFileStream, leaderboard[i].name, ','); ++i) {
        getline(leaderboardInFileStream, score);
        leaderboard[i].score = static_cast<unsigned>(std::stoul(score));
    }
    

}

void LinuxMatchingGame::writeOutFiles() {

    commandOutFileStream.open(commandFile + "_temp");
    if (commandOutFileStream.is_open()) {
        writeOutCommands();
        commandOutFileStream.close();

        // writes to a temp file before deleting the original for safety
        try {
            std::filesystem::rename(commandFile, commandFile + "_backup");
            std::filesystem::rename(commandFile + "_temp", commandFile);

            if (std::filesystem::exists(commandFile + "_backup")) {
                std::filesystem::remove(commandFile + "_backup");
            }

        } catch (const std::exception& e) {
            std::cerr << "Error: failed to overwrite commands file" << std::endl;
        }
    }
    else {
        std::cerr << "Error: command file failed to open for writing" << std::endl;
    }
    leaderboardOutFileStream.open(leaderboardFile + "_temp");
    if (leaderboardOutFileStream.is_open()) {
        writeOutLeaderboard();
        leaderboardOutFileStream.close();

        // writes to a temp file before deleting the original for safety
        try {
            if (std::filesystem::exists(leaderboardFile)) { // leaderboard file is not expected to exist
                std::filesystem::rename(leaderboardFile, leaderboardFile + "_backup");
            }

            std::filesystem::rename(leaderboardFile + "_temp", leaderboardFile);

            if (std::filesystem::exists(leaderboardFile + "_backup")) {
                std::filesystem::remove(leaderboardFile + "_backup");
            }

            
        } catch (const std::exception& e) {
            std::cerr << "Error: failed to overwrite leaderboard file" << std::endl;
        }
    }
    else {
        std::cerr << "Error: leaderboard file failed to open for writing" << std::endl;
    }
}

void LinuxMatchingGame::writeOutCommands() {
    if (!commandList.isEmpty()) {
        CommandData nodeData;

        while (!commandList.isEmpty()) {
            nodeData = commandList.remove(); // data can be removed since only saved on exit
            
            commandOutFileStream << nodeData.command << ",\"";
            commandOutFileStream << nodeData.description << "\",";
            commandOutFileStream << nodeData.points << std::endl;
        }
    }
}

void LinuxMatchingGame::writeOutLeaderboard() {

    for (size_t i = 0; i < LcmgParam::LB_SIZE && leaderboard[i].name != ""; ++i) {
        
        leaderboardOutFileStream << leaderboard[i].name << ",";
        leaderboardOutFileStream << leaderboard[i].score << std::endl;
        
    }
}

unsigned LinuxMatchingGame::menu() {
    unsigned selection = 0;

    displayMenu();
    selection = static_cast<unsigned>(UserInputHandling::getInt(1, 7));

    return selection;
}

void LinuxMatchingGame::displayMenu() {
    std::cout << "*****Welcome to the Linux Commands Matching Game!*****" << std::endl;
    std::cout << "1. View rules" << std::endl;
    std::cout << "2. Play a new game" << std::endl;
    std::cout << "3. Add a command" << std::endl;
    std::cout << "4. Remove a command" << std::endl;
    std::cout << "5. Display all commands" << std::endl;
    std::cout << "6. Show leaderboard" << std::endl;
    std::cout << "7. Save and exit" << std::endl;
    std::cout << "Please select an option (1-7): ";
}

void LinuxMatchingGame::displayRules() {
    std::cout << "In this game you will be presented with a series of " << LcmgParam::NUM_ROUNDS << " linux commands!" << std::endl;
    std::cout << "It is your job to determine which of 3 descriptions matches that command!" << std::endl;
    std::cout << "Just type your answer and press enter!" << std::endl;
    std::cout << "You will be notified if you are correct or wrong!" << std::endl;
    std::cout << "If you are correct, you will be rewarded with points proportionate to the difficulty of the command!" << std::endl;
    std::cout << "If you score enough points, you might even get to see you're name on the leaderboard!" << std::endl;
    std::cout << "Have fun and best of luck! :D" << std::endl;
}

std::string LinuxMatchingGame::promptName() {
    const char invalidChars[1] = { ',' };

    std::cout << "Enter Name (no commas, max length 20): ";

    return UserInputHandling::getString(invalidChars, 1, 20);
}

void LinuxMatchingGame::updateLeaderboard(const std::string& name, const unsigned& score) {
    bool found = false;
    LeaderboardData temp{};

    for (size_t i = 0; i < LcmgParam::LB_SIZE; ++i) {
        if (!found && leaderboard[i].score <= score) {
            found = true;

            temp = leaderboard[i];

            leaderboard[i] = { name, score };
        }
        else if (found) { // once new score is added, shift rest of leaderboard down
            LeaderboardData next = leaderboard[i];
            leaderboard[i] = temp;
            temp = next;
        }
        
    }
}

void LinuxMatchingGame::play() {
    std::string name = promptName(); // prompt user for name
    size_t score = 0;
    size_t correct = 0;
    size_t listSize = commandList.getSize();
    std::unique_ptr<bool[]> visited = std::make_unique<bool[]>(listSize); // array to mark visited nodes, and make unique for safety
    std::mt19937 randomGenerator(std::random_device{}()); // set random seed
    std::uniform_int_distribution<size_t> range; // setup random number generation
    size_t randomNumber = 0; // random number to be generated
    size_t listIndex = 0; // index in list corresponding to randomNumber
    size_t falseIndex = 0; // index for the false descriptions
    std::string falseDescriptions[2] = { "", "" };
    CommandData currentCommand{}; // temp storage of command data

    for (size_t i = 0; i < LcmgParam::NUM_ROUNDS; ++i) {

        // generate random number for command
        range.param(std::uniform_int_distribution<size_t>::param_type(0, listSize - i - 1));
        randomNumber = range(randomGenerator);

        // iterate through visited list, skipping visited to find true index
        listIndex = 0;
        for (size_t j = 0;  j < randomNumber || visited[listIndex];) {
            if (!visited[listIndex]) {
                ++j;
            }
            ++listIndex;
        }

        // get command from index
        currentCommand = commandList.peek(listIndex);
        visited[listIndex] = true;

        // generate two false command descriptions
        for (size_t j = 0; j < 2; ++j) {

            // generate random number for false descriptions
            range.param(std::uniform_int_distribution<size_t>::param_type(0, listSize - 2 - j)); // -2 for no listIndex
            randomNumber = range(randomGenerator);                                               // -j for no false description 1

            // ensure no same command description
            if (randomNumber >= listIndex) {
                ++randomNumber;
            }
            if (j == 1 && randomNumber >= falseIndex) { // only runs on second iteration
                ++randomNumber;
            }

            // add false description
            falseIndex = randomNumber;
            falseDescriptions[j] = (commandList.peek(falseIndex)).description;
        }

        // generate placement for correct answer
        range.param(std::uniform_int_distribution<size_t>::param_type(1, 3));
        randomNumber = range(randomGenerator);

        // clear screen and metrics
        Console::clearScreen();
        std::cout << name << "'s Game"<< std::endl;
        std::cout << "Number of Rounds: " << LcmgParam::NUM_ROUNDS << std::endl;
        std::cout << "Total Correct: " << correct << std::endl;
        std::cout << "Total Points: " << score << std::endl << std::endl;

        // prompt description
        std::cout << "Round " << i + 1 << ':' << std::endl;
        std::cout << currentCommand.points << " points possible!"<< std::endl << std::endl;;
        std::cout << currentCommand.command << std::endl;
        // logic to place true descrption according to randomly generated number, and the false description in the other two spots
        std::cout << "1. " << (randomNumber == 1 ? currentCommand.description : falseDescriptions[0]) << std::endl;
        if (randomNumber == 1) std::cout << "2. " << falseDescriptions[0] << std::endl;
        else std::cout << "2. " << (randomNumber == 2 ? currentCommand.description : falseDescriptions[1]) << std::endl;
        std::cout << "3. " << (randomNumber == 3 ? currentCommand.description : falseDescriptions[1]) << std::endl << std::endl;

        std::cout << "Enter Answer (1-3): ";

        // get user input and display response
        if (static_cast<size_t>(UserInputHandling::getInt(1, 3)) == randomNumber) {
            score += currentCommand.points;
            ++correct;

            Console::clearScreen();
            std::cout << "Correct! The answer for \"" << currentCommand.command << "\" was" << std::endl;
            std::cout << randomNumber << ". " << currentCommand.description << std::endl;
            std::cout << "You earned " << currentCommand.points << " points this round!" << std::endl << std::endl;
            std::cout << "Total: " << score;

        }
        else {
            Console::clearScreen();
            std::cout << "Wrong! The correct answer for \"" << currentCommand.command << "\" was" << std::endl;
            std::cout << randomNumber << ". " << currentCommand.description << std::endl;
            std::cout << "You earned 0 points this round!" << std::endl << std::endl;
            std::cout << "Total: " << score;
        }

        // wait for user input
        std::cout << std::endl << std::endl << "Continue to Next Round ...";
        Console::pause();

    }

    // adjust leaderboard accordingly
    updateLeaderboard(name, score);

    // display final screen
    Console::clearScreen();
    std::cout << "Great Job!" << std::endl;
    std::cout << "Your Final Score was " << score << " Points!" << std::endl << std::endl;

    std::cout << std::endl << std::endl << "Continue Main Menu ...";
    Console::pause();

}

void LinuxMatchingGame::addCommand() {

    const char invalidChars[2] = { ',', '"'};
    CommandData newCommand{};

    // prompt command
    std::cout << "Enter new command (or type \"back\" to cancel): ";
    newCommand.command = UserInputHandling::getString(invalidChars, 1); // excludes comma

    // check if command already exists
    if (commandList.search(&CommandData::command, newCommand.command) != static_cast<size_t>(-1)) {

        // warn user before exiting
        Console::clearScreen();
        std::cout << "This command already exists!" << std::endl;
        std::cout << "Cannot add duplicate commands!" << std::endl << std::endl;
        std::cout << std::endl << std::endl << "Continue ...";
        Console::pause();
    }
    else if (newCommand.command != "back") { // allow user to cancel. "back" is not a linux command as far as i know

        // prompt description
        Console::clearScreen();
        std::cout << "Enter command description (or type \"back\" to cancel): ";
        newCommand.description = UserInputHandling::getString(invalidChars + 1, 1); // excludes quotes

        if (newCommand.description != "back") { // allow user to cancel

            // prompt points
            Console::clearScreen();
            std::cout << "Enter points for command 1-" << LcmgParam::MAX_POINT << " (or type \"0\" to cancel): ";
            newCommand.points = UserInputHandling::getInt(0, LcmgParam::MAX_POINT);

            // insert new command into list
            if (newCommand.points != 0) { // allow user to cancel
                commandList.insert(newCommand);
                Console::clearScreen();
                std::cout << "Command Successfully Added!" << std::endl << std::endl;
                std::cout << std::endl << std::endl << "Continue Main Menu ...";
                Console::pause();
            }
        }
    }

};

void LinuxMatchingGame::removeCommand() {

    // check if there are enough commands to play game before removing
    if (commandList.getSize() > LcmgParam::NUM_ROUNDS) {
     
        std::string input = "";
        size_t index = 0;

        // show the commands for user's convinience
        displayAllCommands();

        // prompt user for command
        std::cout << std::endl << "Please enter command to remove: ";
        input = UserInputHandling::getString();

        // check if command is in the list
        index = commandList.search(&CommandData::command, input);

        Console::clearScreen();

        // remove command if exists, and inform user either way
        if (index != static_cast<size_t>(-1)) {
            commandList.remove(index);

            std::cout << input << " command successfully removed!" << std::endl << std::endl;

            std::cout << "Continue to Main Menu ...";
            Console::pause();
        }
        else {
            std::cout << "Command not found! Failed to remove!" << std::endl << std::endl;

            std::cout << "Continue to Main Menu ...";
            Console::pause();
        }

    }
    else {
        // warn user before exiting
        std::cout << "You cannot remove more than the minimum " << LcmgParam::NUM_ROUNDS << " rounds required to play!"<< std::endl<< std::endl;

        std::cout << "Continue to Main Menu ...";
        Console::pause();
    }
   

}

void LinuxMatchingGame::displayAllCommands() {
    std::cout << "Commands: " << std::endl;
    commandList.printList();
}

void LinuxMatchingGame::displayLeaderboards() {

    std::cout << "Leaderboard: " << std::endl;

    for (size_t i = 0; i < LcmgParam::LB_SIZE && leaderboard[i].name != ""; ++i) {
        std::cout << i + 1 << ". " << leaderboard[i] << std::endl;
    }

    
}