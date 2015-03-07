/*
SH_CalendarView
*/

#ifndef SH_CALENDARVIEW_H
#define SH_CALENDARVIEW_H

#include "qcalendarwidget.h"
#include "sh_mainwindow.h"

class SH_CalendarView : public QCalendarWidget
{
	Q_OBJECT

public:
	SH_CalendarView(QWidget *parent = 0);
	~SH_CalendarView();

private:

protected:

};

#endif // SH_CalendarView