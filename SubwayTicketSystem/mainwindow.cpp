#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menuwindow.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("地铁自动售票系统 - 欢迎界面");

    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(central);

    QLabel *lblTitle = new QLabel("欢迎使用地铁自动售票系统", this);
    lblTitle->setAlignment(Qt::AlignCenter);
    lblTitle->setStyleSheet("font-size:24px; font-weight:bold; color:#0055aa;");

    QLabel *lblInfo = new QLabel("作者：XXX | 版权：©2025 Subway System", this);
    lblInfo->setAlignment(Qt::AlignCenter);

    QPushButton *btnEnter = new QPushButton("进入系统", this);
    btnEnter->setFixedHeight(40);

    layout->addStretch();
    layout->addWidget(lblTitle);
    layout->addWidget(lblInfo);
    layout->addWidget(btnEnter);
    layout->addStretch();

    setCentralWidget(central);

    connect(btnEnter, &QPushButton::clicked, this, [=]() {
        MenuWindow *menu = new MenuWindow();
        menu->show();
        this->close();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

