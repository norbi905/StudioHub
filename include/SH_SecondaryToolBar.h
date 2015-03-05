/*
SH_SecondaryToolBar
*/

#ifndef SH_SECONDARYTOOLBAR_H
#define SH_SECONDARYTOOLBAR_H

#include <qpushbutton.h>
#include"SH_mainwindow.h"

//forward declare class
class SH_MainToolBar;

class SH_SecondaryToolBar : public QToolBar
{
	Q_OBJECT

public:
	SH_SecondaryToolBar(SH_MainToolBar *mainToolBar = 0, QWidget *parent = 0);
	~SH_SecondaryToolBar();

private:
	QPushButton	*firstButton;
	QPushButton	*secondButton;
	QPushButton	*thirdButton;
	QPushButton	*fourthButton;
	QPushButton	*fifthButton;
	QPushButton	*sixthButton;
	QPushButton	*seventhButton;
	QPushButton	*eighthButton;
	QPushButton	*ninethButton;
	QPushButton	*tenthButton;

	QList<QPushButton*> mainViewButtonList;
	QList<QPushButton*> usersViewButtonList;
	QList<QPushButton*> projectViewButtonList;
	QList<QPushButton*> calendarViewButtonList;

	QAction		*firstButtonAction;
	QAction		*secondButtonAction;
	QAction		*thirdButtonAction;
	QAction		*fourthButtonAction;
	QAction		*fifthButtonAction;
	QAction		*sixthButtonAction;
	QAction		*seventhButtonAction;
	QAction		*eighthButtonAction;
	QAction		*ninethButtonAction;
	QAction		*tenthButtonAction;

	void		createActions();

	void		setVisibleMainView(bool visible);
	void        setVisibleUsersView(bool visible);
	void		setVisibleProjectView(bool visible);
	void		setVisibleCalendarView(bool visible);

protected:
	private slots :
		void	mainToolBarMainViewPressed();
		void	mainToolBarUsersViewPressed();
		void	mainToolBarProjectViewPressed();
		void	mainToolBarCalendarViewPressed();


};

#endif // SH_SecondaryToolBar