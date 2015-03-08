#include "include\SH_UsersViewDetails.h"

SH_UsersViewDetails::SH_UsersViewDetails(QWidget *parent)
	: SH_UsersView(parent)
{
	usersViewDetailsLayout = new QVBoxLayout(this);
	userProfileLayout = new QGridLayout(this);

	userProfile = new QGroupBox("User Profile", this);
	userProfile->setAlignment(Qt::AlignRight);
	placeholder1 = new QGroupBox("Placeholder1", this);
	placeholder1->setAlignment(Qt::AlignRight);
	placeholder2 = new QGroupBox("Placeholder2", this);
	placeholder2->setAlignment(Qt::AlignRight);

	usersViewDetailsLayout->addWidget(userProfile);
	usersViewDetailsLayout->addWidget(placeholder1);
	usersViewDetailsLayout->addWidget(placeholder2);

	userName = new QLabel("User: " );
	access = new QLabel("Access: ");
	
	userProfileLayout->addWidget(userName, 0, 0);
	userProfileLayout->addWidget(access, 1, 0);
	userProfile->setLayout(userProfileLayout);
	
}

SH_UsersViewDetails::~SH_UsersViewDetails()
{
	delete placeholder2;
	delete placeholder1;
	delete userProfile;
}

void SH_UsersViewDetails::usersTreeViewClickedItem(QModelIndex index)
{
	//int row = index.row();
	userName->setText("User: " + index.data(Qt::DisplayRole).toString());
	//access->setText("Access: " + index.row.data()
	//access->setText("Access: " + index.data.row());
}