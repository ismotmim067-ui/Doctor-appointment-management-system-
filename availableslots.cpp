#include "availableslots.h"
#include "ui_availableslots.h"

Availableslots::Availableslots(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Availableslots)
{
    ui->setupUi(this);

    // Available slots UI তে add করা
    QStringList availableSlots = {"10:00 AM", "11:00 AM", "12:00 PM", "02:00 PM", "04:00 PM"};

    ui->listWidget->addItems(availableSlots);
}

Availableslots::~Availableslots()
{
    delete ui;
}
