#ifndef CANCELLATION_H
#define CANCELLATION_H

#include <QDialog>
#include <QVector>
#include "bookinginfo.h"

namespace Ui {
class Cancellation;
}

class Cancellation : public QDialog
{
    Q_OBJECT

public:
    explicit Cancellation(QWidget *parent = nullptr);
    ~Cancellation();

    void setBookings(QVector<BookingInfo> *bookings);

private slots:
    void on_btnCancel_clicked();

private:
    Ui::Cancellation *ui;
    QVector<BookingInfo> *bookings;
    void populateSlots();
};

#endif // CANCELLATION_H
