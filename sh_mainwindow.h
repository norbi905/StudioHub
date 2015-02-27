#ifndef SH_MAINWINDOW_H
#define SH_MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_sh_mainwindow.h"

class SH_MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	SH_MainWindow(QWidget *parent = 0);
	~SH_MainWindow();

private:
	Ui::SH_MainWindowClass ui;
};

#endif // SH_MAINWINDOW_H
