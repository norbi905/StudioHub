/*
SH_NewProjectWindow_H
*/
#ifndef SH_NEWPROJECTWINDOW_H
#define SH_NEWPROJECTWINDOW_H

#include <qdialog.h>
#include <qscrollarea.h>
#include <qgridlayout.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qcombobox.h>

class SH_NewProjectWindow : public QDialog
{
	Q_OBJECT

public:
	SH_NewProjectWindow(QWidget *parent = 0, Qt::WindowFlags f = 0);
	~SH_NewProjectWindow();

	QString		getProjectName();

private:
	QVBoxLayout	*mainLayout;
	QScrollArea	*mainScrollArea;
	QWidget		*placeholderWidget;
	QGridLayout *newLayout;

	// project info box
	QGridLayout	*projectInfoLayout;
	QGroupBox	*projectInfoBox;
	QLabel		*projectNameLabel;
	QLineEdit	*projectNameLineEdit;
	QLabel		*clientLabel;
	QComboBox	*clientComboBox;

	// add/cacnel buttons
	QPushButton	*addProjectButton;
	QPushButton	*cancelProjectButton;

	// create signals for buttons
	void		createSignals();
	
protected:
};

#endif //SH_NewProjectWindow_H