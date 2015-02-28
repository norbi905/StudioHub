/*
	SH_MainWindow.cpp
*/

#include "sh_mainwindow.h"

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

	createActions();
	createMenus();
	
	mainToolBar = new SH_MainToolBar(parent);
	addToolBar(mainToolBar);

	ui.setupUi(this);
}

/*
Destructor
*/
SH_MainWindow::~SH_MainWindow()
{
	delete mainToolBar;
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
