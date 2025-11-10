#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "mapwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QApplication>
#include "buyticketwindow.h"

MenuWindow::MenuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("地铁自动售票系统 - 主菜单");

    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(central);

    QPushButton *btnBuy = new QPushButton("购票");
    QPushButton *btnMap = new QPushButton("地图查询");
    QPushButton *btnExit = new QPushButton("退出系统");

    btnBuy->setFixedHeight(40);
    btnMap->setFixedHeight(40);
    btnExit->setFixedHeight(40);

    layout->addStretch();
    layout->addWidget(btnBuy);
    layout->addWidget(btnMap);
    layout->addWidget(btnExit);
    layout->addStretch();

    setCentralWidget(central);

    connect(btnBuy, &QPushButton::clicked, this, &MenuWindow::onBuyTicket);
    connect(btnMap, &QPushButton::clicked, this, &MenuWindow::onMapQuery);
    connect(btnExit, &QPushButton::clicked, this, &MenuWindow::onExitSystem);
}

void MenuWindow::onBuyTicket()
{
    BuyTicketWindow *win = new BuyTicketWindow();
    win->show();
}

void MenuWindow::onMapQuery()
{
    MapWindow *map = new MapWindow();
    map->show();
}

void MenuWindow::onExitSystem()
{
    QApplication::quit();
}

MenuWindow::~MenuWindow()
{
    delete ui;
}
