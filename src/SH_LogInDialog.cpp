/*
SH_LoginDialog.cpp
*/

#include "include\SH_LogInDialog.h"

/*
Constructor
*/
SH_LogInDialog::SH_LogInDialog(QWidget *parent, Qt::WindowFlags)
	: QDialog(parent)
{
	// Set-up window
	//this->setWindowFlags(Qt::FramelessWindowHint);
	//this->setWindowFlags(Qt::SubWindow);
	this->setFixedSize(400, 100);
	//this->setParent(parent);


	createLabels();
	createButtons();
	createEditBox();
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

	move(this->pos() + (event->pos() - QPoint(mouseClick_X_Coord, mouseClick_Y_Coord)));
}

/*
createButtons
*/
void SH_LogInDialog::createButtons()
{
	logInButton = new QPushButton("Log In", this);
	cancelButton = new QPushButton("Cancel", this);

	logInButton->setGeometry(125, 70, 80, 25);
	cancelButton->setGeometry(205, 70, 80, 25);

	createActions();
	createSignals();

	logInButton->addAction(logInAction);
	logInButton->setDefault(true);
	
	cancelButton->addAction(cancelAction);
}

/*
createActions
*/
void SH_LogInDialog::createActions()
{
	logInAction = new QAction(this);
	cancelAction = new QAction(this);
}



/*
createSignals
*/
void SH_LogInDialog::createSignals()
{
	connect(logInButton, SIGNAL(clicked()), this, SLOT(accept()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

/*
createEditBox
*/
void SH_LogInDialog::createEditBox()
{
	usernameEditBox = new QLineEdit(this);
	passwordEditBox = new QLineEdit(this);

	usernameEditBox->setGeometry(120, 10, 170, 22);
	passwordEditBox->setGeometry(120, 40, 170, 22);
	passwordEditBox->setEchoMode(QLineEdit::Password);
}

/*
createLabels
*/
void SH_LogInDialog::createLabels()
{
	usernameLabel = new QLabel("Username:", this);
	passwordLabel = new QLabel("Password:", this);

	usernameLabel->setGeometry(20, 8, 80, 25);
	passwordLabel->setGeometry(20, 38, 80, 25);
}

QString SH_LogInDialog::getUsername()
{
	return usernameEditBox->text();
}

QString SH_LogInDialog::getPassword()
{
	return passwordEditBox->text();
}