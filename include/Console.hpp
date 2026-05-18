// Blake Turman

#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <iostream>

// Personal utilities for dealing with console display
namespace Console {
    inline void clearScreen() {
#ifdef _WIN32
        std::system("cls"); // Windows
#else
        std::system("clear"); // Linux
#endif
    }

    inline void pause() {
#ifdef _WIN32
        std::system("pause<nul"); // Windows - can press any button to continue
#else
        std::cin.get(); // Linux - has to wait for a newline unfortunately
#endif
    }
}


#endif