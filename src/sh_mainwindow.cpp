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

	mySqlConnector = new SH_MySqlConnector();

	ui.setupUi(this);
	this->show();

	initiateLogIn(parent);
	
	//mainToolBar = new SH_MainToolBar(parent);
	//addToolBar(mainToolBar);
}

/*
Destructor
*/
SH_MainWindow::~SH_MainWindow()
{
	delete mainUser;
	delete mainToolBar;
	delete mainUser;
	delete mySqlConnector;
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


void SH_MainWindow::createActions()
{
	/*contextQuitAction = new QAction(tr("&Quit"), this);
	contextQuitAction->setShortcut(QKeySequence::Quit);
	contextQuitAction->setStatusTip("Quit application");
	connect(contextQuitAction, SIGNAL(triggered()), this, SLOT(quitApplication()));*/
}

void SH_MainWindow::createMenus(QWidget *parent	)
{
	mainToolBar = new SH_MainToolBar(parent, this);
	addToolBar(mainToolBar);
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
	logInDialogWindow = new SH_LogInDialog(parent);
	int result = logInDialogWindow->exec();

	if (result == QDialog::Accepted)
	{
		QString	username = logInDialogWindow->getUsername();
		QString password = logInDialogWindow->getPassword();
		
		bool connected = mySqlConnector->connectToDatabase(username, password);
		if (connected)
		{
			this->statusBar()->showMessage("Connected as: " + username);
			createActions();
			createMenus(parent);
		}
		else
		{
			this->statusBar()->showMessage(mySqlConnector->getDBError());
			initiateLogIn(parent);
		}

		mainUser = new SH_User(username, password, "S");
		mainUser->setLoggedIn(true);

	}

	if (result == QDialog::Rejected)
	{
		delete logInDialogWindow;
		exit(0);
	}	
}

/*
userRequestedLogOff
*/
void SH_MainWindow::userRequestedLogOff(QWidget *parent)
{
	/*this->removeToolBar(mainToolBar);
	delete mainToolBar;*/
	delete mainUser;

	removeToolBar(mainToolBar);
	delete mainToolBar;
	delete logInDialogWindow;

	initiateLogIn(parent);
}