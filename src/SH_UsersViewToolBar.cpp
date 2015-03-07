/*
SH_UsersViewToolBar
*/

#include "include\SH_UsersViewToolBar.h"

/*
Constructor
*/
SH_UsersViewToolBar::SH_UsersViewToolBar(SH_MainToolBar *mainToolBar, QWidget *parent)
	: QToolBar(parent)
{
	connect(mainToolBar, SIGNAL(usersViewPressed()), this, SLOT(mainToolBarUsersViewPressed()));

	this->setMovable(false);

	buttonOne = new QPushButton(this);
	buttonTwo = new QPushButton(this);
	buttonThree = new QPushButton(this);

	buttonOne->setText("Users_ButtonOne");
	buttonTwo->setText("Users_ButtonTwo");
	buttonThree->setText("Users_ButtonThree");

	this->addWidget(buttonOne);
	this->addWidget(buttonTwo);
	this->addWidget(buttonThree);
}

/*
Destructor
*/
SH_UsersViewToolBar::~SH_UsersViewToolBar()
{
	delete buttonThree;
	delete buttonTwo;
	delete buttonOne;
}

/*
mainToolBarProjectViewPressed
*/
void SH_UsersViewToolBar::mainToolBarUsersViewPressed()
{

}