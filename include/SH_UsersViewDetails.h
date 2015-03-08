#ifndef SH_USERSVIEWDETAILS_H
#define SH_USERSVIEWDETAILS_H

//class SH_UsersView;
#include "SH_UsersView.h"
#include "sh_mainwindow.h"

class SH_UsersViewDetails : public SH_UsersView
{
	Q_OBJECT

public:
	SH_UsersViewDetails(QWidget *parent = 0);
	~SH_UsersViewDetails();

private:
	QVBoxLayout	*usersViewDetailsLayout;

	QGroupBox	*userProfile;
	QGroupBox	*placeholder1;
	QGroupBox	*placeholder2;

protected:
};

#endif