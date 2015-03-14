/*
SH_ClientViewToolBar_H
*/

#ifndef SH_CLIENTVIEWTOOLBAR_H
#define SH_CLIENTVIEWTOOLBAR_H

#include "sh_mainwindow.h"

class SH_MainToolBar;

class SH_ClientViewToolBar : public QToolBar
{
	Q_OBJECT

public:
	SH_ClientViewToolBar(SH_MainToolBar *mainToolBar, QWidget *parent);
	~SH_ClientViewToolBar();

private:
	QIcon	*addClientIcon;
	QIcon	*removeClientIcon;

	QPushButton	*addClientButton;
	QPushButton *removeClientButton;

protected:

signals :
	void clientViewAddClientClicked();
	void clientViewRemoveClientClicked();

private slots:
	void addClientClicked();
	void removeClientClicked();
};

#endif // SH_ClientViewToolBar_H