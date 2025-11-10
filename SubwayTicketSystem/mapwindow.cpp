#include "mapwindow.h"
#include "ui_mapwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>

MapWindow::MapWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MapWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("地铁自动售票系统 - 地图查询");

    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(central);

    QLabel *lblTitle = new QLabel("地铁线路示意图", this);
    lblTitle->setAlignment(Qt::AlignCenter);
    lblTitle->setStyleSheet("font-size:20px; font-weight:bold;");

    QLabel *lblMap = new QLabel(this);
    lblMap->setAlignment(Qt::AlignCenter);
    lblMap->setPixmap(QPixmap(":/resources/subway_map.png").scaled(600, 400, Qt::KeepAspectRatio));

    QPushButton *btnBack = new QPushButton("返回主菜单", this);

    layout->addWidget(lblTitle);
    layout->addWidget(lblMap);
    layout->addWidget(btnBack);
    setCentralWidget(central);

    connect(btnBack, &QPushButton::clicked, this, &MapWindow::onBack);
}

void MapWindow::onBack()
{
    this->close();
}

MapWindow::~MapWindow()
{
    delete ui;
}
