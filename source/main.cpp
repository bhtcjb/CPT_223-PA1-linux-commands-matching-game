// Blake Turman
/*
Reflection: A benifit of using a linked list for this problem is that nodes can be cleanly and efficiently inserted or removed
            in the middle of the list. For some data structures, such as arrays, removing or inserting in the middle would require
            data to be shifted over or reordered which would be really inefficient. This is particularly important for the 
            Linux command matching game, since the user is allowed to delete any command they wish. A linked list makes this 
            operation seemless since we cannot guarantee remove of a command from an ideal position.

            A disadvantage of using a linked list for this problem is that we must iterate through the list before accessing data.
            With some other data structures, such as an array, data can be retrieved immediately (O(1)) via index or keys.
            However, with a linked list, only the head pointer is usually immediately accessable, and data must be found (O(n)). 
            This is a problem for the Linux command matching game since there is no limit on the number of commands the user is 
            allowed to add, meaning if the user adds a million commands, the game could get pretty slow.
*/


#include "LinuxMatchingGame.hpp"

int main() {

   LinuxMatchingGame game;

   game.runGame();

    return 0;
}
    