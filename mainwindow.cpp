#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Available Slots বাটনের ক্লিক ইভেন্ট সংযোগ (যদি auto connect না থাকে)
    connect(ui->btnAvailableSlots, &QPushButton::clicked,
            this, &MainWindow::on_btnAvailableSlots_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnBooking_clicked()
{
    Booking dlg(this);
    dlg.setBookings(&bookings);
    dlg.exec();
}

void MainWindow::on_btnCancellation_clicked()
{
    Cancellation dlg(this);
    dlg.setBookings(&bookings);
    dlg.exec();
}

void MainWindow::on_btnRecords_clicked()
{
    Records dlg(this);
    dlg.setBookings(&bookings);
    dlg.exec();
}

void MainWindow::on_btnAvailableSlots_clicked()
{
    Availableslots dlg(this);
    dlg.exec();
}
