/*
SH_MainView
*/

#include "include\SH_MainView.h"

/*
Constructor
*/
SH_MainView::SH_MainView(QWidget *parent)
	: QLabel(parent)
{
	this->setStyleSheet("background-color: white");
	this->setText("Main View");
}

/*
Destructor
*/
SH_MainView::~SH_MainView()
{

}