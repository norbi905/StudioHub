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
	//this->setMinimumHeight(70);
	this->setMaximumHeight(50);

	this->setLayoutDirection(Qt::RightToLeft);
	this->setIconSize(QSize(64, 64));
	this->setAllowedAreas(Qt::TopToolBarArea);

	toolBarSpacer	= new QWidget(this);
	mainView		= new QPushButton(this);
	usersView		= new QPushButton(this);
	projectView		= new QPushButton(this);
	calendarView	= new QPushButton(this);

	mainView->setText("MAIN");
	usersView->setText("USER");
	projectView->setText("PROJECT");
	calendarView->setText("CALENDAR");

	mainView->setCheckable(true);
	usersView->setCheckable(true);
	projectView->setCheckable(true);
	calendarView->setCheckable(true);

	mainView->setObjectName("mainViewButton");
	usersView->setObjectName("usersViewButton");
	projectView->setObjectName("projectViewButton");
	calendarView->setObjectName("calendarViewButton");

	// when the application starts, we want the mainView to be the first displayed therefore it's button to be highlighted
	mainView->setChecked(true);
	setActiveToolBarButton(mainView);

	createActionsAndSignals();
	createMenu();

	// setup push button list
	pushButtonList.insert(1, mainView);
	pushButtonList.insert(2, usersView);
	pushButtonList.insert(3, projectView);
	pushButtonList.insert(4, calendarView);
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

	delete calendarView;
	delete projectView;
	delete usersView;
	delete mainView;
	delete toolBarSpacer;
}

/*
createMenu
Creates the upper right hand side profile button, allows user to log in/off or quit application
*/
void SH_MainToolBar::createMenu()
{
	// Profile button
	userProfileButton = new QToolButton(this);
	
	userProfileButton->setIcon(QIcon("../StudioHubResources/ProfilePic/DefaultProfilePic.png"));
	userProfileButton->addAction(logOffAction);
	userProfileButton->addAction(quitAction);
	userProfileButton->setPopupMode(QToolButton::InstantPopup);

	toolBarSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	// username Label
	usernameLabel = new QLabel();
	usernameLabel->setAlignment(Qt::AlignBottom);
	usernameLabel->setPalette(QPalette(QPalette::WindowText, Qt::red));

	this->addWidget(userProfileButton);
	this->addWidget(usernameLabel);
	this->addWidget(toolBarSpacer);
	this->addWidget(calendarView);
	this->addWidget(usersView);
	this->addWidget(projectView);
	this->addWidget(mainView);
}

/*
createActionsAndSignals
Creates menus for when the user press and holds the profile button.
*/
void SH_MainToolBar::createActionsAndSignals()
{
	// Actions
	logOffAction			= new QAction("Log Off", this);
	quitAction				= new QAction("Quit", this);

	// Signals
	connect(logOffAction, SIGNAL(triggered()), this, SLOT(userLogOffRequested()));
	connect(quitAction, SIGNAL(triggered()), this, SLOT(userQuitRequested()));

	connect(mainView, SIGNAL(released()), this, SLOT(userMainViewRequested()));
	connect(usersView, SIGNAL(released()), this, SLOT(userUsersViewRequested()));
	connect(projectView, SIGNAL(released()), this, SLOT(userProjectViewRequested()));
	connect(calendarView, SIGNAL(released()), this, SLOT(userCalendarViewRequested()));
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

/*
userMainViewRequested
*/
void SH_MainToolBar::userMainViewRequested()
{
	setActiveToolBarButton(mainView);
	emit mainViewPressed();
}

/*
userUsersViewRequested
*/
void SH_MainToolBar::userUsersViewRequested()
{
	setActiveToolBarButton(usersView);
	emit usersViewPressed();
}

/*
userProjectViewRequested
*/
void SH_MainToolBar::userProjectViewRequested()
{
	setActiveToolBarButton(projectView);
	emit projectViewPressed();
}

/*
userCalendarViewRequested
*/
void SH_MainToolBar::userCalendarViewRequested()
{
	setActiveToolBarButton(calendarView);
	emit calendarViewPressed();
}

/*
setActiveToolBarButton
*/
void SH_MainToolBar::setActiveToolBarButton(QPushButton *activeButton)
{
	QListIterator<QPushButton*> iter(pushButtonList);
	while (iter.hasNext())
	{
		QPushButton *current = iter.next();

		if (current->objectName() == activeButton->objectName())
			activeButton->setChecked(true);
		else
			current->setChecked(false);
	}
}

/*
resetToolBarButtons
*/
void SH_MainToolBar::resetToolBarButtons()
{
	mainView->setChecked(true);
	usersView->setChecked(false);
	projectView->setChecked(false);
	calendarView->setChecked(false);
}