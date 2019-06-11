#ifndef COMMANDCURSOREND_HPP
#define COMMANDCURSOREND_HPP

#include <string>
#include "Command.hpp"



class CommandCursorEnd: public Command
{
public:
    virtual void execute(EditorModel &model)
    {
		prevCol = model.cursorColumn();
	    model.moveCursor(6);
	}

    virtual void undo(EditorModel &model)
    {
	    model.setCursorColumn(prevCol);
	}

    
private:
	int prevCol;
};



#endif

