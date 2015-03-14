/*
SH_NewClientWindow.cpp
*/

#include "include\SH_NewClientWindow.h"

/*
Constructor
*/
SH_NewClientWindow::SH_NewClientWindow(QWidget *parent)
	: QDialog(parent)
{
	setWindowFlags(Qt::Tool);
	setMinimumSize(400, 300);

	addClientButton = new QPushButton("Add", this);
	cancelButton = new QPushButton("cancel", this);

	mainLayout			= new QGridLayout();
	clientInfoBoxLayout = new QGridLayout();

	clientInfoGroupBox = new QGroupBox("Client Info", this);
	

	clientNameLabel = new QLabel("Client name: ", this);
	clientNameLineEdit = new QLineEdit(this);

	clientInfoBoxLayout->addWidget(clientNameLabel, 0, 0);
	clientInfoBoxLayout->addWidget(clientNameLineEdit, 0, 1);

	clientInfoGroupBox->setLayout(clientInfoBoxLayout);

	mainLayout->addWidget(clientInfoGroupBox,0,0);
	mainLayout->addWidget(addClientButton,1,0);
	mainLayout->addWidget(cancelButton,1,1);

	setLayout(mainLayout);

	createSignals();
}

/*
Destructor
*/
SH_NewClientWindow::~SH_NewClientWindow()
{

}

/*
getClientName
*/
QString SH_NewClientWindow::getClientName()
{
	return clientNameLineEdit->text();
}

/*
createSignals
*/
void SH_NewClientWindow::createSignals()
{
	connect(addClientButton, SIGNAL(clicked()), this, SLOT(accept()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}