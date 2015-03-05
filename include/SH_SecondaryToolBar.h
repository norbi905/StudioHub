/*
SH_SecondaryToolBar
*/

#ifndef SH_SECONDARYTOOLBAR_H
#define SH_SECONDARYTOOLBAR_H

#include"include\SH_mainwindow.h"

//forward declare class
class SH_MainToolBar;

class SH_SecondaryToolBar : public QToolBar
{
	Q_OBJECT

public:
	SH_SecondaryToolBar(SH_MainToolBar *mainToolBar = 0, QWidget *parent = 0);
	~SH_SecondaryToolBar();

private:
	QToolButton	*firstButton;
	QToolButton	*secondButton;
	QToolButton	*thirdButton;
	QToolButton	*fourthButton;
	QToolButton	*fifthButton;
	QToolButton	*sixthButton;
	QToolButton	*seventhButton;
	QToolButton	*eighthButton;
	QToolButton	*ninethButton;
	QToolButton	*tenthButton;

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

protected:
	private slots :
		void	mainToolBarMainViewPressed();
		void	mainToolBarUsersViewPressed();
		void	mainToolBarProjectViewPressed();
		void	mainToolBarCalendarViewPressed();


};

#endif // SH_SecondaryToolBar