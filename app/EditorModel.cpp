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

void setCursorLine(int newCursorLine)
{
	currentCursorLine = newCursorLine;
}

void setCursorColumn(int newCursorColumn)
{
	currentCursorColumn = newCursorColumn;
}

void setNumLines(int newNumLines)
{
	numLines = newNumLines;
}

void EditorModel::moveCursor(int option)
{
	if (option == 1)
	{

	}
	else if (option == 2)
	{

	}
	else if (option == 3)
	{
		if (currentCursorColumn == 1)
		{
			if (currentCursorLine == 1)
			{
				EditorException error{"Cursor Left failed: " +
				"cursor is at the start of text file"};
				EditorModel::setErrorMessage(error.getReason());
				throw error;
			}
			else
			{
				currentCursorLine = currentCursorLine - 1;
				currentCursorColumn = EditorModel::line(currentCursorLine).size();
				currentCursorColumn = currentCursorColumn + 1;
				EditorModel::clearErrorMessage();
			}
		}
		else
		{
			currentCursorColumn = currentCursorColumn - 1;
			EditorModel::clearErrorMessage();
		}
	}
	else if (option == 4)
	{
		if (currentCursorColumn > EditorModel::line(currentCursorLine).size())
		{
			if (currentCursorLine == numLines)
			{
				EditorException error{"Cursor Right failed: " +
				"cursor is at the end of text file"};
				EditorModel::setErrorMessage(error.getReason());
				throw error;
			}
			else
			{
				currentCursorLine = currentCursorLine + 1;
				currentCursorColumn = 1;
				EditorModel::clearErrorMessage();
			}
		}
		else
		{
			currentCursorColumn = currentCursorColumn + 1;
			EditorModel::clearErrorMessage();
		}
	}
	
}
