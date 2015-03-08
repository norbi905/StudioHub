/*
SH_UsersView
*/

#ifndef SH_USERSVIEW_H
#define SH_USERSVIEW_H

#include <QtSql>
#include "qtreeview.h"

class SH_UsersViewDetails;

class SH_UsersView : public QTreeView
{
	Q_OBJECT

public:
	SH_UsersView(QWidget *parent = 0);
	~SH_UsersView();

	void	setUserNameTableModel(QSqlTableModel *model);
	QString	getUserName();

private:
protected:
};

#endif // SH_UsersView