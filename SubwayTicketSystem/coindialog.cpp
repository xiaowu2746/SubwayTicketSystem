#include "coindialog.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

CoinDialog::CoinDialog(double total, QWidget *parent)
    : QDialog(parent)
    , totalPrice(total)
{
    this->setWindowTitle("投币找零");
    this->resize(300, 200);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *lblInfo = new QLabel(QString("应付金额：%1 元").arg(totalPrice));
    QLineEdit *editMoney = new QLineEdit();
    editMoney->setPlaceholderText("请输入投币金额");

    QPushButton *btnPay = new QPushButton("确认支付");
    QLabel *lblResult = new QLabel("");

    layout->addWidget(lblInfo);
    layout->addWidget(editMoney);
    layout->addWidget(btnPay);
    layout->addWidget(lblResult);

    connect(btnPay, &QPushButton::clicked, this, [=]() {
        double money = editMoney->text().toDouble();
        if (money < totalPrice) {
            lblResult->setText(" 投币不足，请继续投币！");
        } else {
            double change = money - totalPrice;
            QMessageBox::information(this, "购票成功",
                                     QString("出票成功！找零：%1 元").arg(change));
            accept();  // 关闭对话框
        }
    });
}

CoinDialog::~CoinDialog() {}

