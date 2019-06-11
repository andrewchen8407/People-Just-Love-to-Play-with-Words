#ifndef COMMANDCURSORDOWN_HPP
#define COMMANDCURSORDOWN_HPP

#include <string>
#include "Command.hpp"



class CommandCursorDown: public Command
{
public:
    virtual void execute(EditorModel &model)
    {
		prevCol = model.cursorColumn();
	    model.moveCursor(2);
	}

    virtual void undo(EditorModel &model)
    {
		model.setCursorLine(model.cursorLine() - 1);
	    model.setCursorColumn(prevCol);
	}

    
private:
	int prevCol;
};



#endif

