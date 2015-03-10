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

class SH_NewUserWindow : public QDialog
{
	Q_OBJECT

public:
	SH_NewUserWindow(QWidget *parent = 0, Qt::WindowFlags f = 0);
	~SH_NewUserWindow();

private:
	QVBoxLayout	*mainLayout;
	QScrollArea	*mainScrollArea;

	QLineEdit		*username;
	QLineEdit		*password;
	QLineEdit		*access;
	QLineEdit		*title;
	QLineEdit		*temp;
	QLineEdit		*temp2;
	QLineEdit		*temp3;
	QLineEdit		*temp4;
	

protected:
};

#endif // SH_NewUserWindow_H