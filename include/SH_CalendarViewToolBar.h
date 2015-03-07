/*
SH_CalendarViewToolBar
*/

#ifndef SH_CALENDARVIEWTOOLBAR_H
#define SH_CALENDARVIEWTOOLBAR_H

#include "qpushbutton.h"

#include "include\SH_mainwindow.h"

// forward declare class
class SH_MainToolBar;

class SH_CalendarViewToolBar : public QToolBar
{
	Q_OBJECT

public:
	SH_CalendarViewToolBar(SH_MainToolBar *mainToolBar, QWidget *parent);
	~SH_CalendarViewToolBar();

private:
	QPushButton		*buttonOne;
	QPushButton		*buttonTwo;
	QPushButton		*buttonThree;


protected:
	private slots :
		void	mainToolBarCalendarViewPressed();
};
#endif // SH_CalendarViewToolBar