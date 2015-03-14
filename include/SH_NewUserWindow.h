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
#include "qlabel.h"
#include "qcombobox.h"
#include "qpushbutton.h"

class SH_NewUserWindow : public QDialog
{
	Q_OBJECT

public:
	SH_NewUserWindow(QWidget *parent = 0, Qt::WindowFlags f = 0);
	~SH_NewUserWindow();

	QString		getUserName();
	QString		getUserPassword();
	QString		getUserAccess();
	QString		getUserTitle();

private:
	QVBoxLayout	*mainLayout;
	QScrollArea	*mainScrollArea;
	QWidget		*placeholderWidget;
	QGridLayout *newLayout;

	// user info BOX section
	QGridLayout		*userInfoBoxLayout;	
	QGroupBox		*userInfoBox;
	QLabel			*usernameLabel;
	QLabel			*passwordLabel;
	QLabel			*accessLabel;
	QLabel			*titleLable;
	QLineEdit		*usernameLineEdit;
	QLineEdit		*passwordLineEdit;
	QLineEdit		*titleLineEdit;
	QComboBox		*accessComboBox;
	// END user info BOX section

	QPushButton		*addUserButton;
	QPushButton		*cancelAddUserButton;

	// create Actions/Signals
	void	createActions();
	void	createSignals();
	
protected:
};

#endif // SH_NewUserWindow_H