#ifndef COMMANDBACKSPACE_HPP
#define COMMANDBACKSPACE_HPP

#include <string>
#include "Command.hpp"



class CommandBackspace: public Command
{
public:
    virtual void execute(EditorModel &model)
    {
        ch = model.backspace();
	}

    virtual void undo(EditorModel &model)
    {
        if (ch)
        {
            model.insertCharacter(&ch);
        }
        else
        {
            model.newLine();
        }
	}

    
private:
	char ch;
};



#endif

