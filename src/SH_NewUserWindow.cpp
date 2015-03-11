/*
SH_NewUserWindow
*/

#include "include\SH_NewUserWindow.h"

/*
Constructor
*/
SH_NewUserWindow::SH_NewUserWindow(QWidget *parent, Qt::WindowFlags)
	: QDialog(parent)
{
	setWindowFlags(Qt::Tool);

	mainLayout			= new QVBoxLayout(parent);
	mainScrollArea		= new QScrollArea(parent);
	placeholderWidget	= new QWidget(mainScrollArea);
	newLayout			= new QGridLayout(mainScrollArea);

	// need this so that whatever we place inside the scroll area will be resize when user resizes main window
	mainScrollArea->setWidgetResizable(true);


	// create text edit fields
	username	= new QLineEdit();
	password	= new QLineEdit();
	access		= new QLineEdit();
	title		= new QLineEdit();
	temp		= new QLineEdit();
	temp2		= new QLineEdit();
	temp3		= new QLineEdit();
	temp4		= new QLineEdit();

	username->setPlaceholderText("username");
	password->setPlaceholderText("password");
	access->setPlaceholderText("access");
	title->setPlaceholderText("title");
	temp->setPlaceholderText("temp");
	temp2->setPlaceholderText("temp2");
	temp3->setPlaceholderText("temp3");
	temp4->setPlaceholderText("temp4");

	// create group boxes
	userInfoBox = new QGroupBox("User Info", mainScrollArea);
	tempBox		= new QGroupBox("Temp" );
	temp2Box	= new QGroupBox("Temp 2" );
	temp3Box	= new QGroupBox("Temp 3" );
	temp4Box	= new QGroupBox("Temp4");

	// create group box layouts
	userInfoBoxLayout	= new QGridLayout();
	tempBoxLayout		= new QGridLayout();
	temp2BoxLayout		= new QGridLayout();
	temp3BoxLayout		= new QGridLayout();
	temp4BoxLayout		= new QGridLayout();

	userInfoBoxLayout->addWidget(username);
	userInfoBoxLayout->addWidget(password);
	userInfoBoxLayout->addWidget(access);
	userInfoBoxLayout->addWidget(title);
	userInfoBox->setLayout(userInfoBoxLayout);

	tempBoxLayout->addWidget(temp);
	tempBox->setLayout(tempBoxLayout);

	temp2BoxLayout->addWidget(temp2);
	temp2Box->setLayout(temp2BoxLayout);

	temp3BoxLayout->addWidget(temp3);
	temp3Box->setLayout(temp3BoxLayout);

	temp4BoxLayout->addWidget(temp4);
	temp4Box->setLayout(temp4BoxLayout);

	newLayout->addWidget(userInfoBox);
	newLayout->addWidget(tempBox);
	newLayout->addWidget(temp2Box);
	newLayout->addWidget(temp3Box);
	newLayout->addWidget(temp4Box);

	placeholderWidget->setLayout(newLayout);
	mainScrollArea->setWidget(placeholderWidget);

	mainLayout->addWidget(mainScrollArea);

	setLayout(mainLayout);

}

/*
Destructor
*/
SH_NewUserWindow::~SH_NewUserWindow()
{

}