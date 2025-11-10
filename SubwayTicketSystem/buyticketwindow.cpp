#include "buyticketwindow.h"
#include "ui_buyticketwindow.h"
#include "coindialog.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QMessageBox>
#include <QInputDialog>

BuyTicketWindow::BuyTicketWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BuyTicketWindow)
    , price(0)
{
    ui->setupUi(this);
    this->setWindowTitle("地铁自动售票系统 - 购票");

    QWidget *central = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(central);

    // 起点与终点输入
    QHBoxLayout *h1 = new QHBoxLayout();
    QLabel *lblStart = new QLabel("起点站：");
    QLineEdit *editStart = new QLineEdit();
    QLabel *lblEnd = new QLabel("终点站：");
    QLineEdit *editEnd = new QLineEdit();
    h1->addWidget(lblStart);
    h1->addWidget(editStart);
    h1->addWidget(lblEnd);
    h1->addWidget(editEnd);

    // 票数输入
    QHBoxLayout *h2 = new QHBoxLayout();
    QLabel *lblNum = new QLabel("购票张数：");
    QSpinBox *spinNum = new QSpinBox();
    spinNum->setRange(1, 10);
    h2->addWidget(lblNum);
    h2->addWidget(spinNum);

    // 显示票价
    QLabel *lblPrice = new QLabel("票价：0 元");
    lblPrice->setAlignment(Qt::AlignCenter);
    lblPrice->setStyleSheet("font-size:18px; color:blue;");

    // 按钮
    QPushButton *btnCalc = new QPushButton("计算票价");
    QPushButton *btnPay = new QPushButton("投币付款");
    QPushButton *btnBack = new QPushButton("返回主菜单");

    mainLayout->addLayout(h1);
    mainLayout->addLayout(h2);
    mainLayout->addWidget(lblPrice);
    mainLayout->addWidget(btnCalc);
    mainLayout->addWidget(btnPay);
    mainLayout->addWidget(btnBack);

    setCentralWidget(central);

    // 计算票价
    connect(btnCalc, &QPushButton::clicked, this, [=]() mutable {
        QString s = editStart->text().trimmed();
        QString e = editEnd->text().trimmed();
        if (s.isEmpty() || e.isEmpty()) {
            QMessageBox::warning(this, "提示", "请输入起点和终点站名！");
            return;
        }

        int distance = abs(s.length() - e.length()) + 3; // 模拟距离
        double unitPrice;
        if (distance <= 3) unitPrice = 2;
        else if (distance <= 6) unitPrice = 3;
        else unitPrice = 4;
        price = unitPrice * spinNum->value();
        lblPrice->setText(QString("票价：%1 元").arg(price));
    });

    // 投币付款
    connect(btnPay, &QPushButton::clicked, this, [=]() {
        if (price <= 0) {
            QMessageBox::warning(this, "提示", "请先计算票价！");
            return;
        }
        CoinDialog dialog(price, this);
        dialog.exec();  // 打开对话框并等待用户操作
    });

    // 返回主菜单
    connect(btnBack, &QPushButton::clicked, this, &BuyTicketWindow::onBack);
}

void BuyTicketWindow::onBack()
{
    this->close();
}

BuyTicketWindow::~BuyTicketWindow()
{
    delete ui;
}
