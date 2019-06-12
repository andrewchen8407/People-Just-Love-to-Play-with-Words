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
	    model.moveCursor(2);
	    model.setCursorColumn(prevCol);
	}

    
private:
	int prevCol;
};



#endif

