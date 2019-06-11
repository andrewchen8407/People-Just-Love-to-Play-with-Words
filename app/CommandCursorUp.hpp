#ifndef COMMANDCURSORUP_HPP
#define COMMANDCURSORUP_HPP

#include <string>
#include "Command.hpp"



class CommandCursorUp: public Command
{
public:
    virtual void execute(EditorModel &model)
    {
	    prevCol = model.cursorColumn();
	    model.moveCursor(1);
	}

    virtual void undo(EditorModel &model)
    {
	    model.setCursorLine(model.cursorLine() + 1);
	    model.setCursorColumn(prevCol);
	}

    
private:
	int prevCol;
};



#endif

