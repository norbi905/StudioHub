/*
SH_ClientView_H
*/

#ifndef SH_CLIENTVIEW_H
#define SH_CLIENTVIEW_H

#include <QtSql>
#include <qtreeview.h>

class SH_ClientView : public QTreeView
{
	Q_OBJECT

public:
	SH_ClientView(QWidget *parent = 0);
	~SH_ClientView();

	void setClientViewTableModel(QSqlTableModel *model);

private:
protected:
};

#endif // SH_ClientView_H