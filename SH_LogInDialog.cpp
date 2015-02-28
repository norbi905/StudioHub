/*
SH_LoginDialog.cpp
*/

#include "SH_LogInDialog.h"

/*
Constructor
*/
SH_LogInDialog::SH_LogInDialog(QWidget *parent)
	: QDialog(parent)
{
	// Set-up window
	//this->setWindowFlags(Qt::FramelessWindowHint);
	this->setFixedSize(400, 300);
	createButtons();
}

/*
Destructor
*/
SH_LogInDialog::~SH_LogInDialog()
{

}

/*
MousePressEvent
*/
void SH_LogInDialog::mousePressEvent(QMouseEvent *event)
{
	QDialog::mousePressEvent(event);

	mouseClick_X_Coord = event->x();
	mouseClick_Y_Coord = event->y();
}

/*
MouseMoveEvent
*/
void SH_LogInDialog::mouseMoveEvent(QMouseEvent *event)
{
	QDialog::mouseMoveEvent(event);

	move(event->globalX() - mouseClick_X_Coord, event->globalY() - mouseClick_Y_Coord);
}

/*
createButtons
*/
void SH_LogInDialog::createButtons()
{
	logInTitle = new QLabel("Log In", this);
	logInButton = new QPushButton("Log In", this);
	cancelButton = new QPushButton("Cancel", this);

	//logInTitle->set
	logInButton->setGeometry(125, 250, 80, 25);
	cancelButton->setGeometry(205, 250, 80, 25);
}