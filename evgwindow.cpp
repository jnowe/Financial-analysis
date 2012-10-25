#include "evgwindow.h"

#include <iostream>

EvgWindow::EvgWindow(QWidget *parent) :
    QMainWindow(parent)
{
    createMenus();
    createTabs();
    createAllModels();

    this->statusBar();

    this->setWindowIcon(QIcon(":/all/main_icon"));
}

EvgWindow::~EvgWindow()
{
    std::cout << "EvgWindow Destructor is called!" << std::endl;
}

void EvgWindow::mayToQuit()
{
    delete this;
}

void EvgWindow::createMenus()
{
    pItsMenuBar = new EvgMenuBar(this);
    this->setMenuBar(pItsMenuBar);

    connect(pItsMenuBar, SIGNAL(signToQuit()), this, SLOT(mayToQuit()));
}

void EvgWindow::createTabs()
{
    pItsTabWidget = new QTabWidget(this);
    this->setCentralWidget(pItsTabWidget);
}

void EvgWindow::createAllModels()
{
    pAllModels = new EvgAllModels(this);

    connect(pItsMenuBar, SIGNAL(calculateAll()), pAllModels, SLOT(calculateAllModels()));

    pItsTabWidget->insertTab(TypeModelInput, pAllModels->model(TypeModelInput), tr("Вихідні дані"));
    pItsTabWidget->insertTab(TypeModelAltman, pAllModels->model(TypeModelAltman), tr("Модель Альтмана"));
    pItsTabWidget->insertTab(TypeModelSpringate, pAllModels->model(TypeModelSpringate), tr("Модель Г. Спрінгейта"));
}
