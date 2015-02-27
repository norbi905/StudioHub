#include "sh_mainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SH_MainWindow w;
	w.show();
	return a.exec();
}
