/*
SH_ProjectListView
*/

#ifndef SH_PROJECTLISTVIEW_H
#define SH_PROJECTLISTVIEW_H

#include "qtableview.h"
#include "sh_mainwindow.h"

class SH_ProjectListView : public QTableView
{
	Q_OBJECT

public:
	SH_ProjectListView(QWidget *parent = 0);
	~SH_ProjectListView();

private:
	

protected:

};

#endif // SH_ProjectListView