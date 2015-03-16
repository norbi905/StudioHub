/*
SH_UsersGridWidget.cpp
*/

#include "include\SH_UsersGridWidget.h"

/*
Constructor
*/
SH_UsersGridWidget::SH_UsersGridWidget(QWidget *parent, QString name,
														QString access,
														QString position,
														QString specialties,
														QString online,
														QString status,
														QString phone,
														QString email)
	: QGroupBox(parent)
{
	this->setMinimumSize(200, 200);
	this->setTitle(name);

	mainLayout = new QGridLayout();

	userAccess			= new QLabel(access);
	userPosition		= new QLabel(position);
	userSpecialties		= new QLabel(specialties);
	userOnline			= new QLabel(online);
	userStatus			= new QLabel(status);
	userPhone			= new QLabel(phone);
	userEmail			= new QLabel(email);
	userProfileIcon		= new QPushButton(QIcon("../StudioHubResources/ProfilePic/DefaultProfilePic.png"), "");
	userProfileIcon->setFixedSize(64, 64);
	userProfileIcon->setIconSize(QSize(64, 64));
	userProfileIcon->setEnabled(false);

	userAccess->setFixedHeight(10);
	userPosition->setFixedHeight(10);
	userSpecialties->setFixedHeight(10);
	userOnline->setFixedHeight(10);
	userStatus->setFixedHeight(10);
	userPhone->setFixedHeight(10);
	userEmail->setFixedHeight(10);

	mainLayout->setSpacing(0);

	mainLayout->addWidget(userProfileIcon, 0, 0, 2, 0, Qt::AlignTop);
	mainLayout->addWidget(userAccess,0,1);
	mainLayout->addWidget(userPosition,1,1);
	mainLayout->addWidget(userSpecialties,4,0);
	mainLayout->addWidget(userOnline,5,0);
	mainLayout->addWidget(userStatus,6,0);
	mainLayout->addWidget(userPhone,7,0);
	mainLayout->addWidget(userEmail,8,0);

	
	
	this->setLayout(mainLayout);

}

/*
Destructor
*/
SH_UsersGridWidget::~SH_UsersGridWidget()
{
	delete userProfileIcon;
	delete userEmail;
	delete userPhone;
	delete userStatus;
	delete userOnline;
	delete userSpecialties;
	delete userPosition;
	delete userAccess;
	delete mainLayout;
}