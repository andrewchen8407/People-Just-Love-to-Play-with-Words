// KeypressInteractionReader.cpp
//
// ICS 45C Spring 2019
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include "Interaction.hpp"
#include "KeypressInteractionReader.hpp"

#include "CommandBackspace.hpp"
#include "CommandCursorDown.hpp"
#include "CommandCursorEnd.hpp"
#include "CommandCursorHome.hpp"
#include "CommandCursorLeft.hpp"
#include "CommandCursorRight.hpp"
#include "CommandCursorUp.hpp"
#include "CommandInsertCharacter.hpp"


// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

Interaction KeypressInteractionReader::nextInteraction()
{
    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

            switch (keypress.code())
            {
            case 'I':
            {
                Command* cmdptr = new CommandCursorUp;
                return Interaction::command(cmdptr);
            }
            case 'K':
            {
                Command* cmdptr = new CommandCursorDown;
                return Interaction::command(cmdptr);
            }
            case 'U':
            {
                Command* cmdptr = new CommandCursorLeft;
                return Interaction::command(cmdptr);
            }
            case 'O':
            {
                Command* cmdptr = new CommandCursorRight;
                return Interaction::command(cmdptr);
            }
            case 'Y':
            {
                Command* cmdptr = new CommandCursorHome;
                return Interaction::command(cmdptr);
            }
            case 'P':
            {
                Command* cmdptr = new CommandCursorEnd;
                return Interaction::command(cmdptr);
            }
            case 'J':
            {
                return Interaction::undo();//
            }
            case 'M':
            {
                return Interaction::undo();//
            }
            case 'H':
            {
                Command* cmdptr = new CommandBackspace;
                return Interaction::command(cmdptr);
            }
            case 'D':
            {
                return Interaction::undo();//
            }
            case 'Z':
            {
                return Interaction::undo();
            }
            case 'A':
            {
                return Interaction::redo();
            }
            {
            case 'X':
                return Interaction::quit();
            }
        }
        else
        {
            // The user pressed a normal key (e.g., 'h') without holding
            // down Ctrl; react accordingly
            Command* cmdptr = new CommandInsertCharacter(keypress.code());
            return Interaction::command(cmdptr);
        }
    }
}

