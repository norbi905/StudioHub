/*
SH_NewClientWindow_h
*/

#ifndef SH_NEWCLIENTWINDOW_H
#define SH_NEWCLIENTWINDOW_H

#include <qdialog.h>
#include <qwidget.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qgridlayout.h>
#include <qgroupbox.h>
#include <qpushbutton.h>

class SH_NewClientWindow : public QDialog
{
public:
	SH_NewClientWindow(QWidget *parent = 0);
	~SH_NewClientWindow();

	QString getClientName();

private:
	QGridLayout	*mainLayout;
	QGridLayout *clientInfoBoxLayout;

	QGroupBox	*clientInfoGroupBox;

	QLabel		*clientNameLabel;
	QLineEdit	*clientNameLineEdit;

	QPushButton	*addClientButton;
	QPushButton	*cancelButton;

	void		createSignals();

protected:
};

#endif // SH_NewClientWindow_H