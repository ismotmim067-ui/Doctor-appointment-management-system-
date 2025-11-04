#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QMainWindow>

namespace Ui {
class AdminPanel;
}

class AdminPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminPanel(QWidget *parent = nullptr);
    ~AdminPanel();

private slots:
    void on_btnShowUsers_clicked();

private:
    Ui::AdminPanel *ui;
};

#endif // ADMINPANEL_H
