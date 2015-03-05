/*
SH_SecondaryToolBar
*/

#include "include\SH_SecondaryToolBar.h"

/*
Constructor
*/
SH_SecondaryToolBar::SH_SecondaryToolBar(SH_MainToolBar *mainToolBar, QWidget *parent)
	: QToolBar(parent)
{
	setMovable(false);
	setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
	setGeometry(0, 80, 0, 0);
	setMinimumHeight(30);
	//setLayoutDirection(Qt::LeftToRight);

	//create all tool bar buttons
	firstButton = new QPushButton(this);
	secondButton = new QPushButton(this);
	thirdButton = new QPushButton(this);
	fourthButton= new QPushButton(this);
	fifthButton = new QPushButton(this);
	sixthButton = new QPushButton(this);
	seventhButton = new QPushButton(this);
	eighthButton = new QPushButton(this);
	ninethButton = new QPushButton(this);
	tenthButton = new QPushButton(this);

	firstButton->setText("first");
	secondButton->setText("second");
	thirdButton->setText("third");
	fourthButton->setText("fourth");
	fifthButton->setText("fifth");
	sixthButton->setText("sixth");
	seventhButton->setText("seventh");
	eighthButton->setText("eighth");
	ninethButton->setText("nineth");
	tenthButton->setText("tenth");

	createActions();

	addWidget(firstButton);
	addWidget(secondButton);
	addWidget(thirdButton);
	addWidget(fourthButton);
	addWidget(fifthButton);
	addWidget(sixthButton);
	addWidget(seventhButton);
	addWidget(eighthButton);
	addWidget(ninethButton);
	addWidget(tenthButton);

	connect(mainToolBar, SIGNAL(mainViewPressed()), this, SLOT(mainToolBarMainViewPressed()));
	connect(mainToolBar, SIGNAL(usersViewPressed()), this, SLOT(mainToolBarUsersViewPressed()));
	connect(mainToolBar, SIGNAL(projectViewPressed()), this, SLOT(mainToolBarProjectViewPressed()));
	connect(mainToolBar, SIGNAL(calendarViewPressed()), this, SLOT(mainToolBarCalendarViewPressed()));

	mainViewButtonList.insert(1, firstButton);
	mainViewButtonList.insert(2, secondButton);
	usersViewButtonList.insert(1, thirdButton);
	usersViewButtonList.insert(2, fourthButton);
	usersViewButtonList.insert(3, fifthButton);
	projectViewButtonList.insert(1, sixthButton);
	calendarViewButtonList.insert(1, seventhButton);
	calendarViewButtonList.insert(2, eighthButton);
	calendarViewButtonList.insert(3, ninethButton);
	calendarViewButtonList.insert(4, tenthButton);

	// set up initial tool bar views / set it to MAINVIEW
	setVisibleMainView(true);
	setVisibleUsersView(false);
	setVisibleProjectView(false);
	setVisibleCalendarView(false);

}

/*
Destructor
*/
SH_SecondaryToolBar::~SH_SecondaryToolBar()
{
	
}

/*
createActions
*/
void SH_SecondaryToolBar::createActions()
{

}

/*
mainToolBarMainViewPressed
*/
void SH_SecondaryToolBar::mainToolBarMainViewPressed()
{
	setVisibleMainView(true);
	setVisibleUsersView(false);
	setVisibleProjectView(false);
	setVisibleCalendarView(false);
}

/*
mainToolBarUsersViewPressed
*/
void SH_SecondaryToolBar::mainToolBarUsersViewPressed()
{
	setVisibleMainView(false);
	setVisibleUsersView(true);
	setVisibleProjectView(false);
	setVisibleCalendarView(false);
}

/*
mainToolBarProjectViewPressed
*/
void SH_SecondaryToolBar::mainToolBarProjectViewPressed()
{
	setVisibleMainView(false);
	setVisibleUsersView(false);
	setVisibleProjectView(true);
	setVisibleCalendarView(false);
}

/*
mainToolBarCalendarViewPressed
*/
void SH_SecondaryToolBar::mainToolBarCalendarViewPressed()
{
	setVisibleMainView(false);
	setVisibleUsersView(false);
	setVisibleProjectView(false);
	setVisibleCalendarView(true);
}


void SH_SecondaryToolBar::setVisibleMainView(bool visible)
{
	QListIterator<QPushButton*> iter(mainViewButtonList);
	while (iter.hasNext())
	{
		QPushButton *current = iter.next();
		current->setVisible(visible);
		
	}
}

void SH_SecondaryToolBar::setVisibleUsersView(bool visible)
{
	QListIterator<QPushButton*> iter(usersViewButtonList);
	while (iter.hasNext())
	{
		QPushButton *current = iter.next();
		current->setEnabled(visible);
	}
}

void SH_SecondaryToolBar::setVisibleProjectView(bool visible)
{
	QListIterator<QPushButton*> iter(projectViewButtonList);
	while (iter.hasNext())
	{
		QPushButton *current = iter.next();
		current->setEnabled(visible);
	}
}

void SH_SecondaryToolBar::setVisibleCalendarView(bool visible)
{
	QListIterator<QPushButton*> iter(calendarViewButtonList);
	while (iter.hasNext())
	{
		QPushButton *current = iter.next();
		current->setEnabled(visible);
	}
}