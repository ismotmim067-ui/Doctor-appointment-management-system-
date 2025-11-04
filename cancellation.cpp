#include "cancellation.h"
#include "ui_cancellation.h"
#include <QDebug>

Cancellation::Cancellation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cancellation),
    bookings(nullptr)
{
    ui->setupUi(this);
}

Cancellation::~Cancellation()
{
    delete ui;
}

void Cancellation::setBookings(QVector<BookingInfo> *bookings)
{
    this->bookings = bookings;
    populateSlots();
}

void Cancellation::populateSlots()
{
    ui->cmbSlot->clear();
    if (!bookings) return;

    // Show only booked slots
    for (const BookingInfo &b : *bookings) {
        ui->cmbSlot->addItem(b.slot);
    }

    if (ui->cmbSlot->count() == 0) {
        ui->cmbSlot->addItem("No Bookings Found");
        ui->btnCancel->setEnabled(false);
    } else {
        ui->btnCancel->setEnabled(true);
    }
}

void Cancellation::on_btnCancel_clicked()
{
    if (!bookings) return;

    QString slot = ui->cmbSlot->currentText();

    if (slot.isEmpty() || slot == "No Bookings Found") {
        ui->lblInfo->setText("No booking selected");
        return;
    }

    // Remove booking with this slot
    for (int i = 0; i < bookings->size(); ++i) {
        if (bookings->at(i).slot == slot) {
            bookings->removeAt(i);
            ui->lblInfo->setText("Booking cancelled for slot " + slot);
            populateSlots();
            return;
        }
    }

    ui->lblInfo->setText("Booking not found");
}
