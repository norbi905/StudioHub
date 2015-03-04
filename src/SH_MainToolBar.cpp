/*
SH_MainToolBar.cpp
*/

#include "include\SH_MainToolBar.h"

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

	createActionsAndSignals();
	createMenu();
}

/*
Destructor
*/
SH_MainToolBar::~SH_MainToolBar()
{
	delete logOffAction;
	delete quitAction;
	delete userProfileButton;
	delete usernameLabel;
}

/*
createMenu
Creates the upper right hand side profile button, allows user to log in/off or quit application
*/
void SH_MainToolBar::createMenu()
{
	// Profile button
	userProfileButton = new QToolButton(this);
	
	userProfileButton->setIcon(QIcon("../StudioHubIcons/DefaultProfilePic.png"));
	userProfileButton->addAction(logOffAction);
	userProfileButton->addAction(quitAction);
	userProfileButton->setPopupMode(QToolButton::InstantPopup);

	// username Label
	usernameLabel = new QLabel();
	usernameLabel->setAlignment(Qt::AlignBottom);
	usernameLabel->setPalette(QPalette(QPalette::WindowText, Qt::red));

	this->addWidget(userProfileButton);
	this->addWidget(usernameLabel);
}

/*
createActionsAndSignals
Creates menus for when the user press and holds the profile button.
*/
void SH_MainToolBar::createActionsAndSignals()
{
	// Actions
	logOffAction = new QAction("Log Off", this);
	quitAction = new QAction("Quit", this);

	// Signals
	connect(logOffAction, SIGNAL(triggered()), this, SLOT(userLogOffRequested()));
	connect(quitAction, SIGNAL(triggered()), this, SLOT(userQuitRequested()));
}

/*
userLogOffRequested()
*/
void SH_MainToolBar::userLogOffRequested()
{
	emit logOffRequested();
}

/*
quitRequested
*/
void SH_MainToolBar::userQuitRequested()
{
	emit quitRequested();
}