// InteractionProcessor.cpp
//
// ICS 45C Spring 2019
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"


// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.

void InteractionProcessor::run()
{
    std::vector<Command*> undoStack;
    std::vector<Command*> redoStack;
    
    view.refresh();

    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {
            for (Command* cmd : undoStack)
            {
                delete cmd;
            }
            for (Command* cmd : redoStack)
            {
                delete cmd;
            }
            break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
            if (undoStack.size())
            {
                undoStack.back()->undo(model);
                redoStack.push_back(undoStack.back());
                undoStack.pop_back();
                model.clearErrorMessage();
                view.refresh();
            }
        }
        else if (interaction.type() == InteractionType::redo)
        {
            if (redoStack.size())
            {
                redoStack.back()->execute(model);
                undoStack.push_back(redoStack.back());
                redoStack.pop_back();
                model.clearErrorMessage();
                view.refresh();
            }
        }
        else if (interaction.type() == InteractionType::command)
        {
            Command* command = interaction.command();

            try
            {
                command->execute(model);
                model.clearErrorMessage();
            }
            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
            }

            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore.
            delete command;
        }
    }
}

