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

	this->setMovable(false);

	buttonOne	= new QPushButton(this);
	buttonTwo	= new QPushButton(this);
	buttonThree = new QPushButton(this);

	buttonOne->setText("Project_ButtonOne");
	buttonTwo->setText("Project_ButtonTwo");
	buttonThree->setText("Project_ButtonThree");

	this->addWidget(buttonOne);
	this->addWidget(buttonTwo);
	this->addWidget(buttonThree);
}

/*
Destructor
*/
SH_ProjectViewToolBar::~SH_ProjectViewToolBar()
{
	delete buttonThree;
	delete buttonTwo;
	delete buttonOne;
}

/*
mainToolBarProjectViewPressed
*/
void SH_ProjectViewToolBar::mainToolBarProjectViewPressed()
{

}