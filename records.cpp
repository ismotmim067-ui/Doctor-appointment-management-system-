#include "records.h"
#include "ui_records.h"

Records::Records(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Records)
{
    ui->setupUi(this);
}

Records::~Records()
{
    delete ui;
}

void Records::setBookings(QVector<BookingInfo> *bookingList)
{
    bookings = bookingList;
    populateData();
}

void Records::populateData()
{
    if (!bookings) return;

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(bookings->size());
    ui->tableWidget->setColumnCount(5);

    QStringList headers = {"Name", "Contact", "Slot", "Token No", "Date"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    for (int i = 0; i < bookings->size(); ++i) {
        const BookingInfo &b = bookings->at(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(b.name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(b.contact));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(b.slot));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(b.tokenNo)));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(b.date.toString("dd-MM-yyyy")));
    }

    ui->tableWidget->resizeColumnsToContents();
}
