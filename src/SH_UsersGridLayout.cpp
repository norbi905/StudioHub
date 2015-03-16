/*
SH_UsersGridLayout.cpp
*/

#include "include\SH_UsersGridLayout.h"

/*
Constructor
*/
SH_UsersGridLayout::SH_UsersGridLayout(QWidget *parent)
	: QGridLayout(parent)
{

}

/*
Destructor
*/
SH_UsersGridLayout::~SH_UsersGridLayout()
{
	
}

/*
addWidget
*/
void SH_UsersGridLayout::addWidget(QWidget *parent)
{
	int currentRow = 0;
	int currentColumn = 0;

	while (itemAtPosition(currentRow, currentColumn) != 0)
	{
		if (currentColumn == (maxColumnCount - 1))
		{
			currentColumn = 0;
			++currentRow;
		}
		else
		{
			++currentColumn;
		}
	}
	QGridLayout::addWidget(parent, currentRow, currentColumn);
}

/*
deleteWidget
*/
void SH_UsersGridLayout::deleteWidget(QWidget *parent)
{
	delete parent;
}

/*
setMaxColumnCount
*/
void SH_UsersGridLayout::setMaxColumnCount(int count)
{
	maxColumnCount = count;
}