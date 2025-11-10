#ifndef BUYTICKETWINDOW_H
#define BUYTICKETWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class BuyTicketWindow; }
QT_END_NAMESPACE

class BuyTicketWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BuyTicketWindow(QWidget *parent = nullptr);
    ~BuyTicketWindow();

private slots:
    void onBack();   // ✅ 只保留这个，其他两个删掉

private:
    Ui::BuyTicketWindow *ui;
    double price;
};

#endif // BUYTICKETWINDOW_H


