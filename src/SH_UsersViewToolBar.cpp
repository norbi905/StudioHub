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

	addUserIcon		= new QIcon("../StudioHubResources/ToolBarIcons/UserViewToolBar/AddUser.png");
	removeUserIcon	= new QIcon("../StudioHubResources/ToolBarIcons/UserViewToolBar/RemoveUser.png");

	addUser		= new QPushButton(*addUserIcon,"Add User", this);
	removeUser	= new QPushButton(*removeUserIcon, "Remove User", this);
	buttonThree = new QPushButton(this);

	buttonThree->setText("Users_ButtonThree");

	this->addWidget(addUser);
	this->addWidget(removeUser);
	this->addWidget(buttonThree);

	connect(addUser, SIGNAL(clicked()), this, SLOT(addUserClicked()));
	connect(removeUser, SIGNAL(clicked()), this, SLOT(removeUserClicked()));
}

/*
Destructor
*/
SH_UsersViewToolBar::~SH_UsersViewToolBar()
{
	delete buttonThree;
	delete removeUser;
	delete addUser;
}

/*
mainToolBarProjectViewPressed
*/
void SH_UsersViewToolBar::mainToolBarUsersViewPressed()
{

}

void SH_UsersViewToolBar::addUserClicked()
{
	emit userViewAddUserClicked();
}

void SH_UsersViewToolBar::removeUserClicked()
{
	emit userViewRemoveUserClicked();
}