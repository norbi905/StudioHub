/*
	SH_MainWindow.cpp
*/

#include "include\sh_mainwindow.h"

/*
Constructor
*/
SH_MainWindow::SH_MainWindow(QWidget *parent)
	: QWidget(parent)
{
	/* Setup main window
	::FramelessWindowHint - We dont want any window frames
	*/
	setWindowFlags(Qt::FramelessWindowHint);

	setMinimumSize(1280, 1024);
	
	contextQuitAction	= NULL;

	mainToolBar			= new SH_MainToolBar(this);
	mainViewToolBar		= new SH_MainViewToolBar(mainToolBar, this);
	projectViewToolBar	= new SH_ProjectViewToolBar(mainToolBar, this);
	usersViewToolBar	= new SH_UsersViewToolBar(mainToolBar, this);
	calendarViewToolBar = new SH_CalendarViewToolBar(mainToolBar, this);

	logInDialogWindow	= new SH_LogInDialog(parent);
	mainUser			= new SH_User();
	mySqlConnector		= new SH_MySqlConnector();

	mainLayout			= new QVBoxLayout(this);
	stackedLayout		= new QStackedLayout(this);

	// create connectors
	connect(mainToolBar, SIGNAL(logOffRequested()), this, SLOT(userRequestedLogOff()));
	connect(mainToolBar, SIGNAL(quitRequested()), this, SLOT(quitApplication()));
	connect(mainToolBar, SIGNAL(mainViewPressed()), this, SLOT(mainToolBarMainViewPressed()));
	connect(mainToolBar, SIGNAL(projectViewPressed()), this, SLOT(mainToolBarProjectViewPressed()));
	connect(mainToolBar, SIGNAL(usersViewPressed()), this, SLOT(mainToolBarUsersViewPressed()));
	connect(mainToolBar, SIGNAL(calendarViewPressed()), this, SLOT(mainToolBarCalendarViewPressed()));

	connect(mainToolBar, SIGNAL(mainViewPressed()), stackedLayout, SLOT(mainToolBarMainViewPressed()));
	connect(mainToolBar, SIGNAL(projectViewPressed()), stackedLayout, SLOT(mainToolBarProjectViewPressed()));
	connect(mainToolBar, SIGNAL(usersViewPressed()), stackedLayout, SLOT(mainToolBarUsersViewPressed()));
	connect(mainToolBar, SIGNAL(calendarViewPressed()), stackedLayout, SLOT(mainToolBarCalendarViewPressed()));
	

	// create view
	projectListView = new SH_ProjectListView(this);
	projectListView->hide();
	mainView		= new SH_MainView(this);
	mainView->hide();
	usersView		= new SH_UsersView(this);
	usersView->hide();
	calendarView	= new SH_CalendarView(this);
	calendarView->hide();

	//ui.setupUi(this);
	//this->show();
	
	mainLayout->addWidget(mainToolBar);
	mainLayout->addWidget(mainViewToolBar);
	mainLayout->addWidget(projectViewToolBar);
	mainLayout->addWidget(usersViewToolBar);
	mainLayout->addWidget(calendarViewToolBar);

	stackedLayout->addWidget(mainView);
	stackedLayout->addWidget(projectListView);
	stackedLayout->addWidget(usersView);
	stackedLayout->addWidget(calendarView);

	mainLayout->addLayout(stackedLayout);

	setLayout(mainLayout);

	

	initiateLogIn(parent);
}

/*
Destructor
*/
SH_MainWindow::~SH_MainWindow()
{
	delete mySqlConnector;
	delete mainUser;
	delete logInDialogWindow;
	delete mainToolBar;
	delete mainViewToolBar;
	delete projectViewToolBar;
	delete usersViewToolBar;
	delete calendarViewToolBar;

	delete projectListView;
	delete mainView;

	delete contextQuitAction;
}

/*
MousePressEvent
*/
void SH_MainWindow::mousePressEvent(QMouseEvent *event)
{
	QWidget::mousePressEvent(event);

	mouseClick_X_Coord = event->x();
	mouseClick_Y_Coord = event->y();
}

/*
MouseMoveEvent
*/
void SH_MainWindow::mouseMoveEvent(QMouseEvent *event)
{
	QWidget::mouseMoveEvent(event);

	move(event->globalX() - mouseClick_X_Coord, event->globalY() - mouseClick_Y_Coord);
}

/*
createContextActions
*/
void SH_MainWindow::createContextActions()
{
	if (contextQuitAction == NULL)
	{
		contextQuitAction = new QAction(tr("&Quit"), this);
		contextQuitAction->setShortcut(QKeySequence::Quit);
		contextQuitAction->setStatusTip("Quit application");
		connect(contextQuitAction, SIGNAL(triggered()), this, SLOT(quitApplication()));
	}
}

/*
displayApplication
*/
void SH_MainWindow::displayApplication(QWidget *parent	)
{
	mainToolBar->usernameLabel->setText(mainUser->getUsername());
	
	projectViewToolBar->hide();
	usersViewToolBar->hide();
	calendarViewToolBar->hide();
	mainToolBar->show();
	mainViewToolBar->show();

	// we want the main view button to be selected
	mainToolBar->resetToolBarButtons();

	stackedLayout->setCurrentIndex(0);
}

/*
contextMenuEvent
This gets called when a user right clicks anywhere within the application space and a context menu pops up
*/
void SH_MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
	QMenu	contextMenu(this);
	contextMenu.addAction(contextQuitAction);
	contextMenu.exec(event->globalPos());
}

/*
quitApplication
This gets called when a user right clicks and selects quit from the context menu
*/
void SH_MainWindow::quitApplication()
{
	//QApplication::quit();
	exit(0);
}

/*
initiateLogIn
*/
void SH_MainWindow::initiateLogIn(QWidget *parent)
{
	int result = logInDialogWindow->exec();

	if (result == QDialog::Accepted)
	{
		QString	username = logInDialogWindow->getUsername();
		QString password = logInDialogWindow->getPassword();
		
		bool connected = mySqlConnector->connectToDatabase(username, password);
		if (connected)
		{
			//this->statusBar()->showMessage("Connected as: " + username);
			createContextActions();
			
			//set-up user
			mainUser->setUsername(username);
			mainUser->setAccess("S");

			mainUser->setLoggedIn(true);

			displayApplication(parent);

			
		}
		else
		{
			//this->statusBar()->showMessage(mySqlConnector->getDBError());
			initiateLogIn(parent);
		}
	}

	if (result == QDialog::Rejected)
	{
		exit(0);
	}	
}

/*
userRequestedLogOff
*/
void SH_MainWindow::userRequestedLogOff()
{
	mainToolBar->hide();
	mainViewToolBar->hide();
	projectViewToolBar->hide();
	usersViewToolBar->hide();
	calendarViewToolBar->hide();

	// get rid of all views
	projectListView->hide();
	mainView->hide();
	usersView->hide();
	calendarView->hide();

	initiateLogIn(this);
}

/*
mainToolBarMainViewPressed
*/
void SH_MainWindow::mainToolBarMainViewPressed()
{
	mainViewToolBar->show();
	projectViewToolBar->hide();
	usersViewToolBar->hide();
	calendarViewToolBar->hide();

	stackedLayout->setCurrentIndex(0);
	//mainView->show();
}

/*
mainToolBarProjectViewPressed
*/
void SH_MainWindow::mainToolBarProjectViewPressed()
{
	mainViewToolBar->hide();
	projectViewToolBar->show();
	usersViewToolBar->hide();
	calendarViewToolBar->hide();

	stackedLayout->setCurrentIndex(1);
	//projectListView->show();
	
	//mainView->hide();
}

/*
mainToolBarUsersViewPressed
*/
void SH_MainWindow::mainToolBarUsersViewPressed()
{
	mainViewToolBar->hide();
	projectViewToolBar->hide();
	usersViewToolBar->show();
	calendarViewToolBar->hide();

	stackedLayout->setCurrentIndex(2);
	//projectListView->hide();
	//mainView->hide();
}

/*
mainToolBarCalendarViewPressed
*/
void SH_MainWindow::mainToolBarCalendarViewPressed()
{
	mainViewToolBar->hide();
	projectViewToolBar->hide();
	usersViewToolBar ->hide();
	calendarViewToolBar->show();

	stackedLayout->setCurrentIndex(3);
	//projectListView->hide();
	//mainView->hide();
}