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
	this->setSortingEnabled(true);

	contextAddProject = new QAction("Add project...", this);
	contextDeleteProject = new QAction("Delete project", this);

	connect(contextAddProject, SIGNAL(triggered()), this, SLOT(addProjectClicked()));
	connect(contextDeleteProject, SIGNAL(triggered()), this, SLOT(deleteProjectClicked()));

	addProjectWindow = new SH_NewProjectWindow(this);
	addProjectWindow->hide();
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

void SH_ProjectListView::setProjectListTableModel(QSqlTableModel *model)
{
	this->setModel(model);
	this->setColumnHidden(1, true);
	this->setColumnHidden(2, true);
	this->setColumnHidden(3, true);
	this->setColumnHidden(4, true);
	this->setColumnHidden(5, true);
	this->setColumnHidden(6, true);

	// FIX ME HACK sort to display newly added items
	this->sortByColumn(0, Qt::DescendingOrder);
	this->sortByColumn(0, Qt::AscendingOrder);
}

/*
addProjectClicked
*/
void SH_ProjectListView::addProjectClicked()
{
	addProjectWindow->show();
	addProjectWindow->updateClientComboBox();

	int result = addProjectWindow->exec();
	if (result == QDialog::Accepted)
	{
		QSqlQuery query;
		query.exec("INSERT INTO projects (name) VALUES ('" + addProjectWindow->getProjectName() + "')");
		query.exec("UPDATE projects SET client = '" + addProjectWindow->getProjectClient() + "' WHERE name = '" + addProjectWindow->getProjectName() + "'");
		this->sortByColumn(0, Qt::DescendingOrder);
		this->sortByColumn(0, Qt::AscendingOrder);
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
	QMessageBox::StandardButton confirmation;
	confirmation = QMessageBox::question(this, "Delete Project?", "Are you sure you want to delete " + this->currentIndex().data(Qt::DisplayRole).toString(), QMessageBox::Yes | QMessageBox::No);
	if (confirmation == QMessageBox::Yes)
	{
		model()->removeRow(this->currentIndex().row());
		this->sortByColumn(0, Qt::DescendingOrder);
		this->sortByColumn(0, Qt::AscendingOrder);
	}
	else
	{

	}
}