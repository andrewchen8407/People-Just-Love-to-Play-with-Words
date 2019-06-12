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
    return editorText.at(lineNumber - 1);
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

void EditorModel::setCursorLine(int newCursorLine)
{
    currentCursorLine = newCursorLine;
}

void EditorModel::setCursorColumn(int newCursorColumn)
{
    currentCursorColumn = newCursorColumn;
}

void EditorModel::setNumLines(int newNumLines)
{
    numLines = newNumLines;
}

void EditorModel::insertCharacter(char ch)
{
    editorText.at(EditorModel::cursorLine() - 1).insert(EditorModel::cursorColumn() - 1, ch);
    EditorModel::setCursorColumn(EditorModel::cursorColumn() + 1);
}

void EditorModel::moveCursor(int option)
{
    if (option == 1)
    {
        if (EditorModel::cursorLine() > 1)
        {
            if (EditorModel::cursorColumn() > EditorModel::line(EditorModel::cursorLine() - 1).size() + 1)
            {
                EditorModel::setCursorColumn(EditorModel::line(EditorModel::cursorLine() - 1).size() + 1);
            }
            EditorModel::setCursorLine(EditorModel::cursorLine() - 1);
            EditorModel::clearErrorMessage();
        }
        else
        {
            std::string errMsg;
            errMsg.assign("Cursor Up failed: cursor is on the first line");
            EditorModel::setErrorMessage(errMsg);
            throw EditorException(errMsg);
        }
    }
    else if (option == 2)
    {
        if (EditorModel::cursorLine() < EditorModel::lineCount())
        {
            if (EditorModel::cursorColumn() > EditorModel::line(EditorModel::cursorLine() + 1).size() + 1)
            {
                EditorModel::setCursorColumn(EditorModel::line(EditorModel::cursorLine() + 1).size() + 1);
            }
            EditorModel::setCursorLine(EditorModel::cursorLine() + 1);
            EditorModel::clearErrorMessage();
        }
        else
        {
            std::string errMsg;
            errMsg.assign("Cursor Down failed: cursor is on the last line");
            EditorModel::setErrorMessage(errMsg);
            throw EditorException(errMsg);
        }
    }
    else if (option == 3)
    {
        if (EditorModel::cursorColumn() > 1)
        {
            EditorModel::setCursorColumn(EditorModel::cursorColumn() - 1);
            EditorModel::clearErrorMessage();
        }
        else
        {
            if (EditorModel::cursorLine() > 1)
            {
                EditorModel::setCursorLine(EditorModel::cursorLine() - 1);
                EditorModel::setCursorColumn(EditorModel::line(EditorModel::cursorLine()).size() + 1);
                EditorModel::clearErrorMessage();
            }
            else
            {
                std::string errMsg;
                errMsg.assign("Cursor Left failed: cursor is at the start of text file");
                EditorModel::setErrorMessage(errMsg);
                throw EditorException(errMsg);
            }
        }
    }
    else if (option == 4)
    {
        if (EditorModel::cursorColumn() > EditorModel::line(EditorModel::cursorLine()).size())
        {
            if (EditorModel::cursorLine() < EditorModel::lineCount())
            {
                EditorModel::setCursorLine(EditorModel::cursorLine() + 1);
                EditorModel::setCursorColumn(1);
                EditorModel::clearErrorMessage();
            }
            else
            {
                std::string errMsg;
                errMsg.assign("Cursor Right failed: cursor is at the end of text file");
                EditorModel::setErrorMessage(errMsg);
                throw EditorException(errMsg);
            }
        }
        else
        {
            EditorModel::setCursorColumn(EditorModel::cursorColumn() + 1);
            EditorModel::clearErrorMessage();
        }
    }
    else if (option == 5)
    {
        if (EditorModel::cursorColumn() > 1)
        {
            EditorModel::setCursorColumn(1);
            EditorModel::clearErrorMessage();
        }
        else
        {
            std::string errMsg;
            errMsg.assign("");
            EditorModel::setErrorMessage(errMsg);
            throw EditorException(errMsg);
        }
    }
    else if (option == 6)
    {
        if (EditorModel::cursorColumn() > EditorModel::line(EditorModel::cursorLine()).size())
        {
            std::string errMsg;
            errMsg.assign("");
            EditorModel::setErrorMessage(errMsg);
            throw EditorException(errMsg);
        }
        else
        {
            EditorModel::setCursorColumn(EditorModel::line(EditorModel::cursorLine()).size() + 1);
            EditorModel::clearErrorMessage();
        }
    }
}

void EditorModel::newLine()
{
    editorText.insert(editorText.begin() + EditorModel::cursorLine(), "");
    if (EditorModel::cursorColumn() - 1 < EditorModel::line(EditorModel::cursorLine()).size())
    {
        
    }
}

char EditorModel::backspace()
{
    if (EditorModel::cursorColumn() == 1)
    {
        if (EditorModel::cursorLine() == 1)
        {
            std::string errMsg;
            errMsg.assign("Backspace failed: cursor is at the start of text file");
            EditorModel::setErrorMessage(errMsg);
            throw EditorException(errMsg);
        }
        else
        {
            EditorModel::setCursorLine(EditorModel::cursorLine() - 1);
            EditorModel::setNumLines(EditorModel::lineCount() - 1);
            int lineIndex = EditorModel::cursorLine();
            editorText.at(lineIndex - 1).append(EditorModel::line(lineIndex + 1));
            editorText.erase(editorText.begin() + lineIndex);
            return '\0';
        }
    }
    else
    {
        char ch = EditorModel::line(EditorModel::cursorLine())[EditorModel::cursorColumn() - 2];
        editor.at(EditorModel::cursorLine() - 1).erase(EditorModel::cursorColumn() - 2, 1);
        EditorModel::setCursorColumn(EditorModel::cursorColumn() - 1);
        return ch;
    }
}

void EditorModel::deleteLine()
{
    
}
