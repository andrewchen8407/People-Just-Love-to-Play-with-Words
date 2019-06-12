#ifndef COMMANDINSERTCHARACTER_HPP
#define COMMANDINSERTCHARACTER_HPP

#include <string>
#include "Command.hpp"



class CommandInsertCharacter: public Command
{
public:
    CommandInsertCharacter(char ch)
    {
        this->ch = ch;
    }
    
    virtual void execute(EditorModel &model)
    {
        model.insertCharacter(&ch);
	}

    virtual void undo(EditorModel &model)
    {
        model.backspace();
	}

    
private:
	char ch;
};



#endif

