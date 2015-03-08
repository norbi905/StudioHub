/*
SH_MainView
*/

#include "include\SH_MainView.h"

/*
Constructor
*/
SH_MainView::SH_MainView(QWidget *parent)
	: QTextEdit(parent)
{
	this->setStyleSheet("background-color: white");
	this->setReadOnly(true);
}

/*
Destructor
*/
SH_MainView::~SH_MainView()
{

}

/*
addMessage
*/
void SH_MainView::addMessage(QString message)
{
	this->setText(message + "\n");
}