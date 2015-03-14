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
	setMinimumSize(400, 300);

	mainLayout			= new QVBoxLayout(parent);
	mainScrollArea		= new QScrollArea(parent);
	placeholderWidget	= new QWidget(mainScrollArea);
	newLayout			= new QGridLayout(mainScrollArea);

	newLayout->setRowStretch(0, 1);

	// need this so that whatever we place inside the scroll area will be resize when user resizes main window
	mainScrollArea->setWidgetResizable(true);



	// create user info BOX section
	usernameLabel		= new QLabel("Username ");
	passwordLabel		= new QLabel("Password ");
	titleLable			= new QLabel("Title ");
	accessLabel			= new QLabel("Access ");

	usernameLineEdit	= new QLineEdit();
	passwordLineEdit	= new QLineEdit();
	titleLineEdit		= new QLineEdit();

	usernameLineEdit->setPlaceholderText("username");
	passwordLineEdit->setPlaceholderText("password");
	titleLineEdit->setPlaceholderText("title");

	accessComboBox		= new QComboBox();
	accessComboBox->addItem("Administrator", 0);
	accessComboBox->addItem("User", 1);
	
	userInfoBox = new QGroupBox("User Info", mainScrollArea);
	
	userInfoBoxLayout	= new QGridLayout();

	userInfoBoxLayout->addWidget(usernameLabel,0,0);
	userInfoBoxLayout->addWidget(passwordLabel,1,0);
	userInfoBoxLayout->addWidget(titleLable,2,0);
	userInfoBoxLayout->addWidget(accessLabel,3,0);
	userInfoBoxLayout->addWidget(usernameLineEdit,0,1);
	userInfoBoxLayout->addWidget(passwordLineEdit,1,1);
	userInfoBoxLayout->addWidget(titleLineEdit,2,1);
	userInfoBoxLayout->addWidget(accessComboBox,3,1);

	userInfoBox->setLayout(userInfoBoxLayout);
	// ------------ END user info BOX section

	// create ADD/CANCEL buttons
	addUserButton = new QPushButton("Add");
	cancelAddUserButton = new QPushButton("Cancel");

	newLayout->addWidget(userInfoBox,0,0);
	newLayout->addWidget(addUserButton,1,0);
	newLayout->addWidget(cancelAddUserButton,1,1);
	
	placeholderWidget->setLayout(newLayout);
	mainScrollArea->setWidget(placeholderWidget);

	mainLayout->addWidget(mainScrollArea);

	setLayout(mainLayout);

	createSignals();
}

/*
Destructor
*/
SH_NewUserWindow::~SH_NewUserWindow()
{

}

/*
createSignals
*/
void SH_NewUserWindow::createSignals()
{
	connect(addUserButton, SIGNAL(clicked()), this, SLOT(accept()));
	connect(cancelAddUserButton, SIGNAL(clicked()), this, SLOT(reject()));
}

/*
getUserName
*/
QString SH_NewUserWindow::getUserName()
{
	return usernameLineEdit->text();
}

/*
getUserAccess
*/
QString SH_NewUserWindow::getUserAccess()
{
	return "NONE";
}

/*
getUserPassword
*/
QString SH_NewUserWindow::getUserPassword()
{
	return passwordLineEdit->text();
}