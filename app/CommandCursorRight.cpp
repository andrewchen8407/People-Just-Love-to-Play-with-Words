#include "CommandCursorRight.hpp"


void CommandCursorRight::execute(EditorModel& model)
{
    model.cursorRight();
}

void CommandCursorRight::undo(EditorModel& model)
{
    model.cursorLeft();
}
