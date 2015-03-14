/*
SH_ClientView.cpp
*/

#include "include\SH_ClientView.h"

/*
Constructor
*/
SH_ClientView::SH_ClientView(QWidget *parent)
	: QTreeView(parent)
{
	this->setSortingEnabled(true);
}

/*
Destructor
*/
SH_ClientView::~SH_ClientView()
{

}

/*
setClientViewTableModel
*/
void SH_ClientView::setClientViewTableModel(QSqlTableModel *model)
{
	this->setModel(model);

	// HACK FIXME
	this->sortByColumn(0, Qt::DescendingOrder);
	this->sortByColumn(0, Qt::AscendingOrder);
}