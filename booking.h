#ifndef BOOKING_H
#define BOOKING_H

#include <QDialog>
#include <QVector>
#include "bookinginfo.h"

namespace Ui {
class Booking;
}

class Booking : public QDialog
{
    Q_OBJECT

public:
    explicit Booking(QWidget *parent = nullptr);
    ~Booking();

    void setBookings(QVector<BookingInfo> *bookings);  // bookings pointer পাবে
    QVector<BookingInfo>* getBookings();               // bookings রিটার্ন করবে

private slots:
    void on_btnBook_clicked();

private:
    Ui::Booking *ui;
    QVector<BookingInfo> *bookings;    // pointer to main vector

    QVector<QString> availableSlots;   // Available slots list
    void populateSlots();
    bool isSlotAvailable(const QString &slot);
};

#endif // BOOKING_H
