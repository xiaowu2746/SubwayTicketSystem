#ifndef COINDIALOG_H
#define COINDIALOG_H

#include <QDialog>

class CoinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CoinDialog(double total, QWidget *parent = nullptr);
    ~CoinDialog();

private:
    double totalPrice;
};

#endif // COINDIALOG_H


