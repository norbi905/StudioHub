#ifndef SH_USERSVIEWDETAILS_H
#define SH_USERSVIEWDETAILS_H

#include "sh_mainwindow.h"
#include "qdebug.h"

class SH_UsersViewDetails : public SH_UsersView
{
	Q_OBJECT

public:
	SH_UsersViewDetails(QWidget *parent = 0);
	~SH_UsersViewDetails();

private:
	QVBoxLayout	*usersViewDetailsLayout;
	QGridLayout	*userProfileLayout;
	
	QGroupBox	*userProfileBox;
	
	QPushButton	*userProfileIcon;
	QLabel		*userName;
	QLabel		*userAccess;
	QLabel		*userPosition;
	QLabel		*userSpecialties;
	QLabel		*userOnline;
	QLabel		*userStatus;
	QLabel		*userPhone;
	QLabel		*userEmail;

protected:
	private slots:
		void	usersTreeViewClickedItem(QModelIndex index);
};

#endif