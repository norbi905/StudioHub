/*
SH_MainToolBar.h
*/

#ifndef SH_MAINTOOLBAR_H
#define SH_MAINTOOLBAR_H

#include "qtoolbutton.h"
#include "sh_mainwindow.h"
#include "SH_LogInDialog.h"

// forward declare classes
class SH_LogInDialog;
class SH_MainWindow;

class SH_MainToolBar : public QToolBar
{
	Q_OBJECT

public:
	SH_MainToolBar(QWidget *parent = 0);
	~SH_MainToolBar();

	SH_LogInDialog	*logInDialog;
	
	QLabel			*usernameLabel;

private:
	QToolButton		*userProfileButton;
	

	QAction			*logOffAction;
	QAction			*quitAction;

	void			createActionsAndSignals();
	void			createMenu();

private slots:
	void			userLogOffRequested();
	void			userQuitRequested();
signals :
	void			logOffRequested();
	void			quitRequested();

protected:

};

#endif // SH_MAINTOOLBAR_H