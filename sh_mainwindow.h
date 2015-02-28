/*
	SH_MainWindow.h
*/

#ifndef SH_MAINWINDOW_H
#define SH_MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include "ui_sh_mainwindow.h"

class SH_MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	// constructor/destructor
	SH_MainWindow(QWidget *parent = 0);
	~SH_MainWindow();

private:
	Ui::SH_MainWindowClass ui;

	QAction	*contextQuitAction;
	
	void	createActions();
	void	createMenus();

	// Mouse key press/movement
	void	mousePressEvent(QMouseEvent *event);
	void	mouseMoveEvent(QMouseEvent *event);
	int		mouseClick_X_Coord;
	int		mouseClick_Y_Coord;
	
protected:
	// right click context menu
	void	contextMenuEvent(QContextMenuEvent *event) Q_DECL_OVERRIDE;

	private slots:
		void quitApplication();
};

#endif // SH_MAINWINDOW_H
