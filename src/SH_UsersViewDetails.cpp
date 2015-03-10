#include "include\SH_UsersViewDetails.h"

SH_UsersViewDetails::SH_UsersViewDetails(QWidget *parent)
	: SH_UsersView(parent)
{
	userProfileIcon = new QPushButton(QIcon("../StudioHubResources/ProfilePic/DefaultProfilePic.png"),"");
	userProfileIcon->setFixedSize(32, 32);
	userProfileIcon->setIconSize(QSize(32, 32));
	userProfileIcon->setEnabled(false);

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
	
	userProfileLayout->addWidget(userProfileIcon,0,0);
	userProfileLayout->addWidget(userName, 0, 1);
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
	userName->setText(index.data(Qt::DisplayRole).toString() + "\n" + index.model()->data(index.model()->index(index.row(), 1)).toString());
}