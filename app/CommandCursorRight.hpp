#ifndef COMMANDCURSORRIGHT_HPP
#define COMMANDCURSORRIGHT_HPP

#include <string>
#include "Command.hpp"



class CommandCursorRight: public Command
{
public:
    virtual void execute(EditorModel &model) override;
    virtual void undo(EditorModel &model) override;
};



#endif

