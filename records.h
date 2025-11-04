#ifndef RECORDS_H
#define RECORDS_H

#include <QDialog>
#include <QVector>
#include "bookinginfo.h" // ✅ added

namespace Ui {
class Records;
}

class Records : public QDialog
{
    Q_OBJECT

public:
    explicit Records(QWidget *parent = nullptr);
    ~Records();

    void setBookings(QVector<BookingInfo> *bookingList);

private:
    Ui::Records *ui;
    QVector<BookingInfo> *bookings = nullptr;

    void populateData();
};

#endif // RECORDS_H
