/*
	SH_MainWindow.cpp
*/

#include "include\sh_mainwindow.h"

/*
Constructor
*/
SH_MainWindow::SH_MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	/* Setup main window
	::FramelessWindowHint - We dont want any window frames

	*/
	setWindowFlags(Qt::FramelessWindowHint);
	setMinimumSize(1280, 1024);
	
	/* Using default ::DefaultContextMenu for now
	This way, contextMenuEvent() handler is called instead of ours...might change this later
	setContextMenuPolicy(Qt::CustomContextMenu);
	*/

	contextQuitAction	= NULL;

	mainToolBar			= new SH_MainToolBar();
	mainViewToolBar		= new SH_MainViewToolBar(mainToolBar);
	projectViewToolBar	= new SH_ProjectViewToolBar(mainToolBar);
	usersViewToolBar	= new SH_UsersViewToolBar(mainToolBar);
	calendarViewToolBar = new SH_CalendarViewToolBar(mainToolBar);

	logInDialogWindow	= new SH_LogInDialog(parent);
	mainUser			= new SH_User();
	mySqlConnector		= new SH_MySqlConnector();

	// create connectors
	connect(mainToolBar, SIGNAL(logOffRequested()), this, SLOT(userRequestedLogOff()));
	connect(mainToolBar, SIGNAL(quitRequested()), this, SLOT(quitApplication()));
	connect(mainToolBar, SIGNAL(mainViewPressed()), this, SLOT(mainToolBarMainViewPressed()));
	connect(mainToolBar, SIGNAL(projectViewPressed()), this, SLOT(mainToolBarProjectViewPressed()));
	connect(mainToolBar, SIGNAL(usersViewPressed()), this, SLOT(mainToolBarUsersViewPressed()));
	connect(mainToolBar, SIGNAL(calendarViewPressed()), this, SLOT(mainToolBarCalendarViewPressed()));

	// create view
	projectListView = new SH_ProjectListView(this);
	projectListView->show();

	ui.setupUi(this);
	this->show();

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

	delete contextQuitAction;
}

/*
MousePressEvent
*/
void SH_MainWindow::mousePressEvent(QMouseEvent *event)
{
	QMainWindow::mousePressEvent(event);

	mouseClick_X_Coord = event->x();
	mouseClick_Y_Coord = event->y();
}

/*
MouseMoveEvent
*/
void SH_MainWindow::mouseMoveEvent(QMouseEvent *event)
{
	QMainWindow::mouseMoveEvent(event);

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
	addToolBar(mainToolBar);
	addToolBarBreak();
	addToolBar(mainViewToolBar);
	addToolBar(projectViewToolBar);
	addToolBar(usersViewToolBar);
	addToolBar(calendarViewToolBar);

	mainToolBar->show();
	mainViewToolBar->show();
	projectViewToolBar->hide();
	usersViewToolBar->hide();
	calendarViewToolBar->hide();

	// we want the main view button to be selected
	mainToolBar->resetToolBarButtons();
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
	QApplication::quit();
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
			this->statusBar()->showMessage("Connected as: " + username);
			createContextActions();
			
			//set-up user
			mainUser->setUsername(username);
			mainUser->setAccess("S");

			mainUser->setLoggedIn(true);

			displayApplication(parent);

			
		}
		else
		{
			this->statusBar()->showMessage(mySqlConnector->getDBError());
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
	removeToolBar(mainToolBar);
	removeToolBar(mainViewToolBar);
	removeToolBar(projectViewToolBar);
	removeToolBar(usersViewToolBar);
	removeToolBar(calendarViewToolBar);

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

	projectListView->show();
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
}