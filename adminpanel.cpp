#include "adminpanel.h"
#include "ui_adminpanel.h"
#include <QMessageBox>

AdminPanel::AdminPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminPanel)
{
    ui->setupUi(this);
}

AdminPanel::~AdminPanel()
{
    delete ui;
}

void AdminPanel::on_btnShowUsers_clicked()
{
    QMessageBox::information(this, "Users Info", "Admin can view user info here.");
}
