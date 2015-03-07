/*
SH_ProjectViewToolBar
*/

#ifndef SH_PROJECTVIEWTOOLBAR_H
#define SH_PROJECTVIEWTOOLBAR_H

#include "qpushbutton.h"

#include "include\SH_mainwindow.h"

// forward declare class
class SH_MainToolBar;

class SH_ProjectViewToolBar : public QToolBar
{
	Q_OBJECT

public:
	SH_ProjectViewToolBar(SH_MainToolBar *mainToolBar, QWidget *parent);
	~SH_ProjectViewToolBar();

private:
	QPushButton		*buttonOne;
	QPushButton		*buttonTwo;
	QPushButton		*buttonThree;


protected:
	private slots :
		void	mainToolBarProjectViewPressed();
};
#endif // SH_ProjectViewToolBar