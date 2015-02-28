/*
SH_MainToolBar.h
*/

#ifndef SH_MAINTOOLBAR_H
#define SH_MAINTOOLBAR_H

#include "qtoolbutton.h"
#include "sh_mainwindow.h"
#include "SH_LogInDialog.h"

class SH_LogInDialog;

class SH_MainToolBar : public QToolBar
{
	Q_OBJECT

public:
	SH_MainToolBar(QWidget *parent = 0);
	~SH_MainToolBar();

	SH_LogInDialog	*logInDialog;

private:
	QToolButton	*userProfileButton;

	QAction		*logInAction;
	QAction		*logOffAction;
	QAction		*quitAction;

	void		createProfileButton();
	void		createActions();
	void		createSignals();

private slots:
	void		quitApplication();
	void		displayLogInDialog();
	void		logOff();

protected:

};

#endif // SH_MAINTOOLBAR_H