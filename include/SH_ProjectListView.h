/*
SH_ProjectListView
*/

#ifndef SH_PROJECTLISTVIEW_H
#define SH_PROJECTLISTVIEW_H

#include <qtreeview.h>
#include <qaction.h>
#include <qmenu.h>
#include <qevent.h>
//#include "sh_mainwindow.h"
#include "SH_NewProjectWindow.h"

class SH_ProjectListView : public QTreeView
{
	Q_OBJECT

public:
	SH_ProjectListView(QWidget *parent = 0);
	~SH_ProjectListView();

	// right click context menu
	QAction	*contextAddProject;
	QAction *contextDeleteProject;

private:
	SH_NewProjectWindow		*addProjectWindow;

protected:
	
	private slots:
	void addProjectClicked();
	void deleteProjectClicked();

	// override right click menu
	void contextMenuEvent(QContextMenuEvent *event) Q_DECL_OVERRIDE;
};

#endif // SH_ProjectListView