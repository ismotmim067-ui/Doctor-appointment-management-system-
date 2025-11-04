#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "bookinginfo.h"
#include "booking.h"
#include "cancellation.h"
#include "records.h"
#include "availableslots.h"   // নতুন উইন্ডো হেডার যুক্ত করলাম

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnBooking_clicked();
    void on_btnCancellation_clicked();
    void on_btnRecords_clicked();

    void on_btnAvailableSlots_clicked();    // নতুন বাটনের স্লট

private:
    Ui::MainWindow *ui;
    QVector<BookingInfo> bookings;  // Main storage of bookings
};

#endif // MAINWINDOW_H
