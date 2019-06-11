#ifndef COMMANDCURSORLEFT_HPP
#define COMMANDCURSORLEFT_HPP

#include <string>
#include "Command.hpp"



class CommandCursorLeft: public Command
{
public:
    virtual void execute(EditorModel &model) override;
    virtual void undo(EditorModel &model) override;
};



#endif

