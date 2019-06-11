#include "CommandCursorLeft.hpp"


void CommandCursorLeft::execute(EditorModel& model)
{
    model.cursorLeft();
}

void CommandCursorLeft::undo(EditorModel& model)
{
    model.cursorRight();
}
