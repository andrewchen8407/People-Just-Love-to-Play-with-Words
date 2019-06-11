#ifndef COMMANDCURSORRIGHT_HPP
#define COMMANDCURSORRIGHT_HPP

#include <string>
#include "Command.hpp"



class CommandCursorRight: public Command
{
public:
    virtual void execute(EditorModel &model)
    {
	    model.moveCursor(4);
	}

    virtual void undo(EditorModel &model)
    {
	    model.moveCursor(3);
	}
};



#endif

