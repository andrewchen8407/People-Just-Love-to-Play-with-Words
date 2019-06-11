#ifndef COMMANDCURSORLEFT_HPP
#define COMMANDCURSORLEFT_HPP

#include <string>
#include "Command.hpp"



class CommandCursorLeft: public Command
{
public:
    virtual void execute(EditorModel &model)
    {
	    model.moveCursor(3);
	}

    virtual void undo(EditorModel &model)
    {
	    model.moveCursor(4);
	}
};



#endif

