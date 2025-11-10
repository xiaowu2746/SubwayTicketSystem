#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MapWindow; }
QT_END_NAMESPACE

class MapWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapWindow(QWidget *parent = nullptr);
    ~MapWindow();

private slots:
    void onBack();

private:
    Ui::MapWindow *ui;
};

#endif // MAPWINDOW_H
