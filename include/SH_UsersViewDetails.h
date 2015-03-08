#ifndef SH_USERSVIEWDETAILS_H
#define SH_USERSVIEWDETAILS_H

#include "sh_mainwindow.h"

class SH_UsersViewDetails : public SH_UsersView
{
	Q_OBJECT

public:
	SH_UsersViewDetails(QWidget *parent = 0);
	~SH_UsersViewDetails();

private:
	QVBoxLayout	*usersViewDetailsLayout;
	QGridLayout	*userProfileLayout;
	QGridLayout	*placeholder1Layout;
	QGridLayout	*placeholder2Layout;

	QGroupBox	*userProfile;
	QGroupBox	*placeholder1;
	QGroupBox	*placeholder2;

	QLabel		*userName;
	QLabel		*access;

protected:
	private slots:
		void	usersTreeViewClickedItem(QModelIndex index);
};

#endif