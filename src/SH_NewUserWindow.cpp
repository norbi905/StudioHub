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
	//setWindowFlags(Qt::Dialog);

	mainLayout = new QVBoxLayout(this);
	mainScrollArea = new QScrollArea(this);
	mainLayout->addWidget(mainScrollArea);
	

	//// create text edit fields
	username = new QLineEdit(this);
	password = new QLineEdit(this);
	access = new QLineEdit(this);
	title = new QLineEdit(this);
	temp = new QLineEdit(this);
	temp2 = new QLineEdit(this);
	temp3 = new QLineEdit(this);
	temp4 = new QLineEdit(this);

	username->setPlaceholderText("username");
	password->setPlaceholderText("password");
	access->setPlaceholderText("access");
	title->setPlaceholderText("title");
	temp->setPlaceholderText("temp");
	temp2->setPlaceholderText("temp2");
	temp3->setPlaceholderText("temp3");
	temp4->setPlaceholderText("temp4");

	QGridLayout *newLayout = new QGridLayout();



////mainLayout->addWidget(mainScrollArea);
	newLayout->addWidget(username);
	newLayout->addWidget(password);
	newLayout->addWidget(access);
	newLayout->addWidget(title);
	newLayout->addWidget(temp);
	newLayout->addWidget(temp2);
	newLayout->addWidget(temp3);
	newLayout->addWidget(temp4);

	setLayout(newLayout);
	mainScrollArea->setWidget(parent);

//mainScrollArea->setWidget(username);
//	mainScrollArea->setWidget(password);
//	mainScrollArea->setWidget(access);
//	mainScrollArea->setWidget(title);
//	mainScrollArea->setWidget(temp);
//	mainScrollArea->setWidget(temp2);
//	mainScrollArea->setWidget(temp3);
//	mainScrollArea->setWidget(temp4);

//
//username->setLayout(mainLayout);
//password->setLayout(mainLayout);
//access->setLayout(mainLayout);
//title->setLayout(mainLayout);
//temp->setLayout(mainLayout);
//temp2->setLayout(mainLayout);
//temp3->setLayout(mainLayout);
//temp4->setLayout(mainLayout);
	
	
	//setLayout(mainLayout);
	
	//mainScrollArea->show();
}

/*
Destructor
*/
SH_NewUserWindow::~SH_NewUserWindow()
{

}