/*
SH_ClientView_H
*/

#ifndef SH_CLIENTVIEW_H
#define SH_CLIENTVIEW_H

#include <QtSql>
#include <qtreeview.h>
#include <qaction.h>
#include <qmenu.h>
#include <qevent.h>
#include <qmessagebox.h>

#include "SH_NewClientWindow.h"

class SH_ClientView : public QTreeView
{
	Q_OBJECT

public:
	SH_ClientView(QWidget *parent = 0);
	~SH_ClientView();

	void setClientViewTableModel(QSqlTableModel *model);

private:
	QAction	*contextAddClient;
	QAction *contextDeleteClient;

	SH_NewClientWindow	*clientWindow;

protected:
	private slots :
		void addClientClicked();
		void removeClientClicked();
		void contextMenuEvent(QContextMenuEvent *event) Q_DECL_OVERRIDE;
};

#endif // SH_ClientView_H