#ifndef SH_USERSVIEWDETAILS_H
#define SH_USERSVIEWDETAILS_H

#include <QSql>
#include "qdebug.h"
#include "qscrollarea.h"

#include "sh_mainwindow.h"
#include "SH_UsersGridLayout.h"
#include "SH_UsersGridWidget.h"

class SH_UsersViewDetails : public SH_UsersView
{
	Q_OBJECT

public:
	SH_UsersViewDetails(QWidget *parent = 0);
	~SH_UsersViewDetails();

	void setTableModel(QSqlTableModel *model);
	void setView();
	void updateView(QSqlTableModel *model);

private:
	QSqlTableModel		*thisModel;

	QScrollArea			*mainScrollArea;
	SH_UsersGridLayout	*usersGridLayout;
	QWidget				*placeholderWidget;
	QGridLayout			*newLayout;
	QVBoxLayout			*mainLayout;

	/*QVBoxLayout	*usersViewDetailsLayout;
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
	QLabel		*userEmail;*/

protected:
	private slots:
		void	usersTreeViewClickedItem(QModelIndex index);
};

#endif