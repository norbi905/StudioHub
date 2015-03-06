/*
SH_CalendarViewToolBar
*/

#include "include\SH_CalendarViewToolBar.h"

/*
Constructor
*/
SH_CalendarViewToolBar::SH_CalendarViewToolBar(SH_MainToolBar *mainToolBar)
	: QToolBar()
{
	connect(mainToolBar, SIGNAL(calendarViewPressed()), this, SLOT(mainToolBarcalendarViewPressed()));

	this->setMovable(false);

	buttonOne = new QPushButton(this);
	buttonTwo = new QPushButton(this);
	buttonThree = new QPushButton(this);

	buttonOne->setText("Calendar_ButtonOne");
	buttonTwo->setText("Calendar_ButtonTwo");
	buttonThree->setText("Calendar_ButtonThree");

	this->addWidget(buttonOne);
	this->addWidget(buttonTwo);
	this->addWidget(buttonThree);
}

/*
Destructor
*/
SH_CalendarViewToolBar::~SH_CalendarViewToolBar()
{
	delete buttonThree;
	delete buttonTwo;
	delete buttonOne;
}

/*
mainToolBarCalendarViewPressed
*/
void SH_CalendarViewToolBar::mainToolBarCalendarViewPressed()
{

}