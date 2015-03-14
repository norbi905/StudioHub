/*
SH_NewProjectWindow.cpp
*/

#include "include\SH_NewProjectWindow.h"

/*
Constructor
*/
SH_NewProjectWindow::SH_NewProjectWindow(QWidget *parent, Qt::WindowFlags f)
	: QDialog(parent)
{
	setWindowFlags(Qt::Tool);
	setMinimumSize(400, 300);

	mainLayout			= new QVBoxLayout(parent);
	mainScrollArea		= new QScrollArea(parent);
	placeholderWidget	= new QWidget(mainScrollArea);
	newLayout			= new QGridLayout(mainScrollArea);

	mainScrollArea->setWidgetResizable(true);

	projectInfoLayout	= new QGridLayout();
	projectInfoBox		= new QGroupBox(mainScrollArea);
	projectNameLabel	= new QLabel("Project name: ");
	projectNameLineEdit = new QLineEdit();

	projectInfoLayout->addWidget(projectNameLabel,0,0);
	projectInfoLayout->addWidget(projectNameLineEdit,0,1);
	projectInfoBox->setLayout(projectInfoLayout);

	newLayout->addWidget(projectInfoBox);
	placeholderWidget->setLayout(newLayout);
	mainScrollArea->setWidget(placeholderWidget);

	mainLayout->addWidget(mainScrollArea);
	setLayout(mainLayout);
}

/*
Destructor
*/
SH_NewProjectWindow::~SH_NewProjectWindow()
{

}