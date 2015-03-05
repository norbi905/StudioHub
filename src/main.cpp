/*
	Main.cpp
*/

#include "include\sh_mainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication StudioHub_application(argc, argv);
	SH_MainWindow *studioHub_MainWindow = new SH_MainWindow();

	studioHub_MainWindow->show();
	return StudioHub_application.exec();
}
