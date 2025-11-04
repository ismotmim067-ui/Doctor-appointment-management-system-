#ifndef BOOKINGINFO_H
#define BOOKINGINFO_H

#include <QString>
#include <QDate>

struct BookingInfo {
    QString name;
    QString contact;
    QString slot;
    int tokenNo;
    QDate date;
};
