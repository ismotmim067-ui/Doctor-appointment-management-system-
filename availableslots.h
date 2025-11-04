#ifndef AVAILABLESLOTS_H
#define AVAILABLESLOTS_H

#include <QDialog>

namespace Ui {
class Availableslots;
}

class Availableslots : public QDialog
{
    Q_OBJECT

public:
    explicit Availableslots(QWidget *parent = nullptr);
    ~Availableslots();

private:
    Ui::Availableslots *ui;
};

#endif // AVAILABLESLOTS_H
