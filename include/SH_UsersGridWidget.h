
/*
SH_UsersGridWidget_H
*/

#ifndef SH_USERSGRIDWIDGET_H
#define SH_USERSGRIDWIDGET_H

#include "qwidget.h"
#include "qgroupbox.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include "qgridlayout.h"

class SH_UsersGridWidget : public QGroupBox
{
public:
	SH_UsersGridWidget(QWidget *parent = 0, 
							QString name = 0,
							QString access = 0,
							QString position = 0,
							QString specialties = 0,
							QString online = 0,
							QString status = 0,
							QString phone = 0,
							QString email = 0);
	~SH_UsersGridWidget();

	void addWidget(QWidget *parent);

private:
	QGridLayout	*mainLayout;
	QPushButton	*userProfileIcon;
	QLabel		*userAccess;
	QLabel		*userPosition;
	QLabel		*userSpecialties;
	QLabel		*userOnline;
	QLabel		*userStatus;
	QLabel		*userPhone;
	QLabel		*userEmail;

protected:
};

#endif // SH_UsersGridWidget_H