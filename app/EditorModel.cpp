// EditorModel.cpp
//
// ICS 45C Spring 2019
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"


EditorModel::EditorModel()
{
	currentCursorLine = 1;
	currentCursorColumn = 1;
	numLines = 1;
	editorText.push_back("");
	currentErrMsg.assign("");
}


int EditorModel::cursorLine() const
{
    return currentCursorLine;
}


int EditorModel::cursorColumn() const
{
    return currentCursorColumn;
}


int EditorModel::lineCount() const
{
    return numLines;
}


const std::string& EditorModel::line(int lineNumber) const
{
    static std::string removeThis = "BooEdit!";
    return removeThis;
}


const std::string& EditorModel::currentErrorMessage() const
{
    return currentErrMsg;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
	currentErrMsg.assign(errorMessage);
}


void EditorModel::clearErrorMessage()
{
	currentErrMsg.assign("");
}

void EditorModel::cursorLeft()
{
	if (currentCursorColumn == 1)
	{
		if (currentCursorLine == 1)
		{

		}
		else
		{

		}
	}
	else
	{
		EditorModel::clearErrorMessage();
	}
}

void EditorModel::cursorRight()
{
	if (currentCursorColumn > EditorModel::line(currentCursorLine).size())
	{
		if (currentCursorLine == numLines)
		{

		}
		else
		{

		}
	}
	else
	{
		EditorModel::clearErrorMessage();
	}
}
