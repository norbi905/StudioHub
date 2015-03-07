/*
SH_MainViewToolBar
*/

#ifndef SH_MAINVIEWTOOLBAR_H
#define SH_MAINVIEWTOOLBAR_H

#include "qpushbutton.h"

#include "include\SH_mainwindow.h"

// forward declare class
class SH_MainToolBar;

class SH_MainViewToolBar : public QToolBar
{
	Q_OBJECT

public:
	SH_MainViewToolBar(SH_MainToolBar *mainToolBar, QWidget *parent);
	~SH_MainViewToolBar();

private:
	QPushButton		*buttonOne;
	QPushButton		*buttonTwo;


protected:
	private slots :
		void	mainToolBarMainViewPressed();
};
#endif // SH_MainViewToolBar