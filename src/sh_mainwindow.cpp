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

	ui.setupUi(this);
	this->show();

	createLogIn(parent);
	
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
	delete logInDialogWindow;
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
	contextQuitAction = new QAction(tr("&Quit"), this);
	contextQuitAction->setShortcut(QKeySequence::Quit);
	contextQuitAction->setStatusTip("Quit application");
	connect(contextQuitAction, SIGNAL(triggered()), this, SLOT(quitApplication()));

}

void SH_MainWindow::createMenus()
{

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

void SH_MainWindow::createLogIn(QWidget *parent)
{
	logInDialogWindow = new SH_LogInDialog(parent);
	int result = logInDialogWindow->exec();
	if (result == QDialog::Accepted)
	{
		//do something
		QString	username = logInDialogWindow->getUsername();
		QString password = logInDialogWindow->getPassword();
		//this->statusBar()->showMessage("Credentials: " + username +" " + password);
		
		mainUser = new SH_User(username, password, "S");
		bool connected = mainUser->isLoggedIn();
		if (connected)
			this->statusBar()->showMessage("Connected as:" + username);
		else
			this->statusBar()->showMessage(mainUser->getDBError());

	}
	if (result == QDialog::Rejected)
	{
		exit(0);
	}
	createActions();
	createMenus();
}