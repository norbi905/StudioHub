/*
SH_ClientViewToolBar.cpp
*/

#include "include\SH_ClientViewToolBar.h"

/*
Constructor
*/
SH_ClientViewToolBar::SH_ClientViewToolBar(SH_MainToolBar *mainToolBar, QWidget *parent)
	: QToolBar(parent)
{
	this->setMovable(false);

	addClientIcon		= new QIcon("../StudioHubResources/ToolBarIcons/UserViewToolBar/AddUser.png");
	removeClientIcon	= new QIcon("../StudioHubResources/ToolBarIcons/UserViewToolBar/RemoveUser.png");

	addClientButton		= new QPushButton(*addClientIcon, "Add Client", this);
	removeClientButton	= new QPushButton(*removeClientIcon, "Delete Client", this);

	this->addWidget(addClientButton);
	this->addWidget(removeClientButton);
}

/*
Destructor
*/
SH_ClientViewToolBar::~SH_ClientViewToolBar()
{
	delete removeClientButton;
	delete addClientButton;
	delete removeClientIcon;
	delete addClientIcon;
}

/*
addClientClicked
*/
void SH_ClientViewToolBar::addClientClicked()
{
	emit clientViewAddClientClicked();
}

/*
removeClientClicked
*/
void SH_ClientViewToolBar::removeClientClicked()
{
	emit clientViewRemoveClientClicked();
}