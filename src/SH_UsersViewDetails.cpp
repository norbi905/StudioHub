#include "include\SH_UsersViewDetails.h"

SH_UsersViewDetails::SH_UsersViewDetails(QWidget *parent)
	: SH_UsersView(parent)
{
	userName		= new QLabel();
	userAccess		= new QLabel();
	userPosition	= new QLabel();
	userSpecialties = new QLabel();
	userOnline		= new QLabel();
	userStatus		= new QLabel();
	userPhone		= new QLabel();
	userEmail		= new QLabel();
	userProfileIcon = new QPushButton(QIcon("../StudioHubResources/ProfilePic/DefaultProfilePic.png"),"");
	userProfileIcon->setFixedSize(140, 140);
	userProfileIcon->setIconSize(QSize(140, 140));
	userProfileIcon->setEnabled(false);

	usersViewDetailsLayout = new QVBoxLayout(this);
	userProfileLayout = new QGridLayout(this);
	
	userProfileBox = new QGroupBox("User Profile");
	userProfileBox->setMaximumHeight(200);
		
	usersViewDetailsLayout->setAlignment(Qt::AlignTop);
	usersViewDetailsLayout->addWidget(userProfileBox);
		
	userProfileLayout->addWidget(userProfileIcon,0,0,0,6);
	userProfileLayout->addWidget(userName, 0, 1);
	userProfileLayout->addWidget(userAccess, 1, 1);
	userProfileLayout->addWidget(userPosition, 2, 1);
	userProfileLayout->addWidget(userSpecialties, 3, 1);
	userProfileLayout->addWidget(userPhone, 4, 1);
	userProfileLayout->addWidget(userEmail, 5, 1);
	userProfileLayout->addWidget(userStatus, 6, 1);
	userProfileLayout->addWidget(userOnline, 7, 1);
		
	userProfileBox->setLayout(userProfileLayout);
}

SH_UsersViewDetails::~SH_UsersViewDetails()
{
	delete userProfileBox;
}

void SH_UsersViewDetails::usersTreeViewClickedItem(QModelIndex index)
{
	//userName->setText(index.data(Qt::DisplayRole).toString() + "\n" + index.model()->data(index.model()->index(index.row(), 1)).toString());
	userName->setText(index.data(Qt::DisplayRole).toString());
	userAccess->setText(index.model()->data(index.model()->index(index.row(), 1)).toString());
	userPosition->setText(index.model()->data(index.model()->index(index.row(), 2)).toString());
	userSpecialties->setText(index.model()->data(index.model()->index(index.row(), 3)).toString());
	userOnline->setText(index.model()->data(index.model()->index(index.row(), 4)).toString());
	userStatus->setText(index.model()->data(index.model()->index(index.row(), 5)).toString());
	userPhone->setText(index.model()->data(index.model()->index(index.row(), 6)).toString());
	userEmail->setText(index.model()->data(index.model()->index(index.row(), 7)).toString());
}