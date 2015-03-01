/*
SH_MainToolBar.cpp
*/

#include "SH_MainToolBar.h"

/*
Constructor
*/
SH_MainToolBar::SH_MainToolBar(QWidget *parent)
	:QToolBar(parent)
{
	// Set-up toolbar properties
	this->setMovable(false);
	this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
	this->setGeometry(0, 0, 0, 0);
	this->setMinimumHeight(70);
	this->setLayoutDirection(Qt::RightToLeft);
	this->setIconSize(QSize(64, 64));

	createActions();
	createProfileButton();
	createSignals();

	// create loginDialog
	logInDialog = new SH_LogInDialog(parent);
}

/*
Destructor
*/
SH_MainToolBar::~SH_MainToolBar()
{
	delete logInDialog;
}

/*
createProfileButton
Creates the upper right hand side profile button, allows user to log in/off or quit application
*/
void SH_MainToolBar::createProfileButton()
{
	userProfileButton = new QToolButton(this);
	
	userProfileButton->setIcon(QIcon("../StudioHubIcons/DefaultProfilePic.png"));
	userProfileButton->addAction(logInAction);
	userProfileButton->addAction(logOffAction);
	userProfileButton->addAction(quitAction);
	userProfileButton->setPopupMode(QToolButton::InstantPopup);
	
	this->addWidget(userProfileButton);
}

/*
createActions
Creates menus for when the user press and holds the profile button.
*/
void SH_MainToolBar::createActions()
{
	logInAction = new QAction("LogIn", this);
	logOffAction = new QAction("Log Off", this);
	quitAction = new QAction("Quit", this);
}

/*
createSignals
Attach menu items to functions
*/
void SH_MainToolBar::createSignals()
{
	connect(logInAction, SIGNAL(triggered()), this, SLOT(displayLogInDialog()));
	connect(logOffAction, SIGNAL(triggered()), this, SLOT(logOff()));
	connect(quitAction, SIGNAL(triggered()), this, SLOT(quitApplication()));
}

/*
displayLogInDialog
*/
void SH_MainToolBar::displayLogInDialog()
{
	logInDialog->setModal(true);
	logInDialog->exec();
}

/*
logOff
*/
void SH_MainToolBar::logOff()
{

}

/*
quitApplication
Called when user selects quit application from menu
*/
void SH_MainToolBar::quitApplication()
{
	QApplication::quit();
}