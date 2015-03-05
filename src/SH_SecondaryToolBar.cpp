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
	firstButton = new QToolButton(this);
	secondButton = new QToolButton(this);
	thirdButton = new QToolButton(this);
	fourthButton= new QToolButton(this);
	fifthButton = new QToolButton(this);
	sixthButton = new QToolButton(this);
	seventhButton = new QToolButton(this);
	eighthButton = new QToolButton(this);
	ninethButton = new QToolButton(this);
	tenthButton = new QToolButton(this);

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

void SH_SecondaryToolBar::mainToolBarMainViewPressed()
{
	firstButton->setDisabled(true);
	secondButton->setDisabled(true);
}

void SH_SecondaryToolBar::mainToolBarUsersViewPressed()
{
	thirdButton->setDisabled(true);
	fourthButton->setDisabled(true);
}

void SH_SecondaryToolBar::mainToolBarProjectViewPressed()
{
	fifthButton->setDisabled(true);
	sixthButton->setDisabled(true);
}

void SH_SecondaryToolBar::mainToolBarCalendarViewPressed()
{
	seventhButton->setDisabled(true);
	eighthButton->setDisabled(true);
	ninethButton->setDisabled(true);
	tenthButton->setDisabled(true);
}