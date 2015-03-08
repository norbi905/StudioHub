#include "include\SH_UsersViewDetails.h"

SH_UsersViewDetails::SH_UsersViewDetails(QWidget *parent)
	: SH_UsersView(parent)
{
	usersViewDetailsLayout = new QVBoxLayout(this);

	userProfile = new QGroupBox("User Profile", this);
	//userProfile->setAlignment(Qt::AlignRight);
	placeholder1 = new QGroupBox("Placeholder1", this);
	placeholder2 = new QGroupBox("Placeholder2", this);

	usersViewDetailsLayout->addWidget(userProfile);
	usersViewDetailsLayout->addWidget(placeholder1);
	usersViewDetailsLayout->addWidget(placeholder2);
}

SH_UsersViewDetails::~SH_UsersViewDetails()
{

}