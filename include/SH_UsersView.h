/*
SH_UsersView
*/

#ifndef SH_USERSVIEW_H
#define SH_USERSVIEW_H

#include <QtSql>
#include "qtreeview.h"
#include "qaction.h"
#include "qmessagebox.h"

#include "SH_NewUserWindow.h"

class SH_UsersViewDetails;

class SH_UsersView : public QTreeView
{
	Q_OBJECT

public:
	SH_UsersView(QWidget *parent = 0);
	~SH_UsersView();

	void	setUserNameTableModel(QSqlTableModel *model);
	QString	getUserName();

	// menu items for custom context menu when right clicking in this window
	QAction	*contextAddUser;
	QAction	*contextDeleteUser;

private:
	SH_NewUserWindow	*addNewUserWindow;
	
protected:
	private slots :
	void addUserClicked();
	void removeUserClicked();

	void contextMenuEvent(QContextMenuEvent *event) Q_DECL_OVERRIDE;
};

#endif // SH_UsersView