#ifndef COMMANDCURSORHOME_HPP
#define COMMANDCURSORHOME_HPP

#include <string>
#include "Command.hpp"



class CommandCursorHome: public Command
{
public:
    virtual void execute(EditorModel &model)
    {
		prevCol = model.cursorColumn();
	    model.moveCursor(5);
	}

    virtual void undo(EditorModel &model)
    {
	    model.setCursorColumn(prevCol);
	}

    
private:
	int prevCol;
};



#endif

