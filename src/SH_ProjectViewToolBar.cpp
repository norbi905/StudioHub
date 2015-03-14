/*
SH_ProjectViewToolBar
*/

#include "include\SH_ProjectViewToolBar.h"

/*
Constructor
*/
SH_ProjectViewToolBar::SH_ProjectViewToolBar(SH_MainToolBar *mainToolBar, QWidget *parent)
	: QToolBar(parent)
{
	connect(mainToolBar, SIGNAL(projectViewPressed()), this, SLOT(mainToolBarProjectViewPressed()));

	addProjectIcon		= new QIcon("../StudioHubResources/ToolBarIcons/UserViewToolBar/AddUser.png");
	deleteProjectIcon	= new QIcon("../StudioHubResources/ToolBarIcons/UserViewToolBar/RemoveUser.png");

	this->setMovable(false);

	addProjectButton	= new QPushButton(*addProjectIcon, "Add Project", this);
	deleteProjectButton	= new QPushButton(*deleteProjectIcon, "Delete Project", this);
	buttonThree = new QPushButton(this);

	this->addWidget(addProjectButton);
	this->addWidget(deleteProjectButton);
	this->addWidget(buttonThree);

	connect(addProjectButton, SIGNAL(clicked()), this, SLOT(addProjectClicked()));
	connect(deleteProjectButton, SIGNAL(clicked()), this, SLOT(deleteProjectClicked()));
}

/*
Destructor
*/
SH_ProjectViewToolBar::~SH_ProjectViewToolBar()
{
	delete buttonThree;
	delete deleteProjectButton;
	delete addProjectButton;
}

/*
mainToolBarProjectViewPressed
*/
void SH_ProjectViewToolBar::mainToolBarProjectViewPressed()
{

}

/*
addProjectClicked
*/
void SH_ProjectViewToolBar::addProjectClicked()
{
	emit projectViewAddProjectClicked();
}

/*
deleteProjectClicked
*/
void SH_ProjectViewToolBar::deleteProjectClicked()
{
	emit projectViewDeleteProjectClicked();
}