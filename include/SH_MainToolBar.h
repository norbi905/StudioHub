/*
SH_MainToolBar.h
*/

#ifndef SH_MAINTOOLBAR_H
#define SH_MAINTOOLBAR_H

#include "qtoolbutton.h"
#include "sh_mainwindow.h"
#include "SH_LogInDialog.h"
#include "sh_mainwindow.h"

class SH_LogInDialog;
class SH_MainWindow;

class SH_MainToolBar : public QToolBar
{
	Q_OBJECT

public:
	SH_MainToolBar(QWidget *parent = 0, SH_MainWindow *mainWindow = 0);
	~SH_MainToolBar();

	SH_LogInDialog	*logInDialog;

private:
	SH_MainWindow	*mainWindowReference;
	QWidget			*parentReference;
	QToolButton		*userProfileButton;

	QAction			*logOffAction;
	QAction			*quitAction;

	void			createProfileButton();
	void			createActions();
	void			createSignals();

private slots:
	void			quitApplication();
	void			logOff();

protected:

};

#endif // SH_MAINTOOLBAR_H