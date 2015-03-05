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
	secondaryToolBar	= new SH_SecondaryToolBar(mainToolBar, this);
	logInDialogWindow	= new SH_LogInDialog(parent);
	mainUser			= new SH_User();
	mySqlConnector		= new SH_MySqlConnector();

	// create connectors
	connect(mainToolBar, SIGNAL(logOffRequested()), this, SLOT(userRequestedLogOff()));
	connect(mainToolBar, SIGNAL(quitRequested()), this, SLOT(quitApplication()));

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
	delete secondaryToolBar;

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

void SH_MainWindow::displayApplication(QWidget *parent	)
{
	mainToolBar->usernameLabel->setText(mainUser->getUsername());
	addToolBar(mainToolBar);
	addToolBarBreak();
	addToolBar(secondaryToolBar);

	mainToolBar->show();
	secondaryToolBar->show();
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
	removeToolBar(secondaryToolBar);
	removeToolBar(mainToolBar);

	initiateLogIn(this);
}