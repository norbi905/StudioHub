/*
SH_MainViewToolBar
*/

#include "include\SH_MainViewToolBar.h"

/*
Constructor
*/
SH_MainViewToolBar::SH_MainViewToolBar(SH_MainToolBar *mainToolBar, QWidget *parent)
	: QToolBar(parent)
{
	connect(mainToolBar, SIGNAL(mainViewPressed()), this, SLOT(mainToolBarMainViewPressed()));

	this->setMovable(false);

	buttonOne = new QPushButton(this);
	buttonTwo = new QPushButton(this);

	buttonOne->setText("Main_ButtonOne");
	buttonTwo->setText("Main_ButtonTwo");

	this->addWidget(buttonOne);
	this->addWidget(buttonTwo);
}

/*
Destructor
*/
SH_MainViewToolBar::~SH_MainViewToolBar()
{
	delete buttonTwo;
	delete buttonOne;
}

/*
mainToolBarMainViewPressed
*/
void SH_MainViewToolBar::mainToolBarMainViewPressed()
{

}