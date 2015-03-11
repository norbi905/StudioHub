/*
SH_NewUserWindow_h
*/

#ifndef SH_NEWUSERWINDOW_H
#define SH_NEWUSERWINDOW_H

#include <qdialog.h>
#include <qwidget.h>
#include <QGridLayout>
#include <qscrollarea.h>
#include <qlineedit.h>
#include "qgroupbox.h"

class SH_NewUserWindow : public QDialog
{
	Q_OBJECT

public:
	SH_NewUserWindow(QWidget *parent = 0, Qt::WindowFlags f = 0);
	~SH_NewUserWindow();

private:
	QVBoxLayout	*mainLayout;
	QScrollArea	*mainScrollArea;
	QWidget		*placeholderWidget;
	QGridLayout *newLayout;

	// group box layouts
	QGridLayout	*userInfoBoxLayout;
	QGridLayout	*tempBoxLayout;
	QGridLayout	*temp2BoxLayout;
	QGridLayout	*temp3BoxLayout;
	QGridLayout	*temp4BoxLayout;

	QLineEdit		*username;
	QLineEdit		*password;
	QLineEdit		*access;
	QLineEdit		*title;
	QLineEdit		*temp;
	QLineEdit		*temp2;
	QLineEdit		*temp3;
	QLineEdit		*temp4;

	QGroupBox		*userInfoBox;
	QGroupBox		*tempBox;
	QGroupBox		*temp2Box;
	QGroupBox		*temp3Box;
	QGroupBox		*temp4Box;
	

protected:
};

#endif // SH_NewUserWindow_H