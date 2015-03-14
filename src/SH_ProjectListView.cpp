/*
SH_ProjectListView
*/

#include "include\SH_ProjectListView.h"

/*
Constructor
*/
SH_ProjectListView::SH_ProjectListView(QWidget *parent)
	: QTreeView(parent)
{
	contextAddProject = new QAction("Add project...", this);
	contextDeleteProject = new QAction("Delete project", this);

	connect(contextAddProject, SIGNAL(triggered()), this, SLOT(addProjectClicked()));
	connect(contextDeleteProject, SIGNAL(triggered()), this, SLOT(deleteProjectClicked()));
}

/*
Destructor
*/
SH_ProjectListView::~SH_ProjectListView()
{

}

/*
contextMenuEvent
*/
void SH_ProjectListView::contextMenuEvent(QContextMenuEvent *event)
{
	QMenu contextMenu(this);
	contextMenu.addAction(contextAddProject);
	contextMenu.addAction(contextDeleteProject);
	contextMenu.exec(event->globalPos());
}

/*
addProjectClicked
*/
void SH_ProjectListView::addProjectClicked()
{
	addProjectWindow = new SH_NewProjectWindow(this);
	int result = addProjectWindow->exec();
	if (result == QDialog::Accepted)
	{

	}
	else
	{
		addProjectWindow->close();
	}
}

/*
deleteProjectClicked
*/
void SH_ProjectListView::deleteProjectClicked()
{
	exit(0);
}