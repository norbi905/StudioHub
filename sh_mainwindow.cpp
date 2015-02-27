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
	// dont want the main window frame to show
	setWindowFlags(Qt::FramelessWindowHint);

	// we want to be able to right click anywhere within the main window and display a dropdown populated with options/selections
	setContextMenuPolicy(Qt::CustomContextMenu);
	connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(showContextMenu(const QPoint&)));


	ui.setupUi(this);
}

/*
Destructor
*/
SH_MainWindow::~SH_MainWindow()
{

}

/*
MousePressEvent
*/
void SH_MainWindow::mousePressEvent(QMouseEvent *event)
{
	QMainWindow::mousePressEvent(event);

	QPoint	mouseCoord(event->x(), event->y());

	mouseClick_X_Coord = event->x();
	mouseClick_Y_Coord = event->y();

	if (event->button() == Qt::RightButton)
	{
		showContextMenu(mouseCoord);
	}
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
ShowContextMenu
*/
void SH_MainWindow::showContextMenu(const QPoint &pos)
{
	QMenu contextMenu(tr("ContextMenu"), this);
	QAction action1("Quit", this);
	QObject::connect(&action1, SIGNAL(triggered()), this, SLOT(quitApplication()));
	contextMenu.addAction(&action1);

	contextMenu.exec(mapToGlobal(pos));
}

void SH_MainWindow::quitApplication()
{
	QApplication::quit();
	exit(1);
}