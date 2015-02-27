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
		SH_MainWindow(QWidget *parent = 0);
		~SH_MainWindow();

		// right click context menu
		void showContextMenu(const QPoint& pos);
		void quitApplication();

private:
		Ui::SH_MainWindowClass ui;

protected:
		// Mouse movement
		void mousePressEvent(QMouseEvent *event);
		void mouseMoveEvent(QMouseEvent *event);

		float mouseClick_X_Coord;
		float mouseClick_Y_Coord;
};

#endif // SH_MAINWINDOW_H
