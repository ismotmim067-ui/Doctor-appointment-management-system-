#include "booking.h"
#include "ui_booking.h"
#include <QDate>
#include <QRandomGenerator>
#include <QDebug>

Booking::Booking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Booking),
    bookings(nullptr)
{
    ui->setupUi(this);

    // Initialize available slots here
    availableSlots = {"10:00 AM", "11:00 AM", "12:00 PM", "02:00 PM", "04:00 PM"};

    populateSlots();
}

Booking::~Booking()
{
    delete ui;
}

void Booking::setBookings(QVector<BookingInfo> *bookings)
{
    this->bookings = bookings;
    populateSlots();
}

QVector<BookingInfo>* Booking::getBookings()
{
    return bookings;
}

bool Booking::isSlotAvailable(const QString &slot)
{
    if (!bookings) return true;

    for (const BookingInfo &b : *bookings) {
        if (b.slot == slot) {
            return false;  // slot already booked
        }
    }
    return true;
}

void Booking::populateSlots()
{
    ui->cmbSlot->clear();

    for (const QString &slot : availableSlots) {
        if (isSlotAvailable(slot)) {
            ui->cmbSlot->addItem(slot);
        }
    }

    if (ui->cmbSlot->count() == 0) {
        ui->cmbSlot->addItem("No Slots Available");
        ui->btnBook->setEnabled(false);
    } else {
        ui->btnBook->setEnabled(true);
    }
}

void Booking::on_btnBook_clicked()
{
    if (!bookings) {
        qDebug() << "Booking storage not set!";
        ui->lblInfo->setText("Error: Booking storage not set!");
        return;
    }

    QString name = ui->txtName->text().trimmed();
    QString contact = ui->txtContactNo->text().trimmed();
    QString slot = ui->cmbSlot->currentText();

    if (name.isEmpty() || contact.isEmpty() || slot.isEmpty() || slot == "No Slots Available") {
        ui->lblInfo->setText("Please fill all fields and select a valid slot.");
        return;
    }

    int tokenNo = QRandomGenerator::global()->bounded(100000, 999999);

    BookingInfo newBooking;
    newBooking.name = name;
    newBooking.contact = contact;
    newBooking.slot = slot;
    newBooking.tokenNo = tokenNo;
    newBooking.date = QDate::currentDate();

    bookings->append(newBooking);

    ui->lblInfo->setText("Booked! Token No: " + QString::number(tokenNo));

    ui->txtName->clear();
    ui->txtContactNo->clear();

    populateSlots();  // Refresh available slots to remove booked one
}
