#include "userprofile.h"
#include "ui_userprofile.h"
#include "logindialog.h"
#include <QMessageBox>

UserProfile::UserProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserProfile)
{
    ui->setupUi(this);
}

UserProfile::~UserProfile()
{
    delete ui;
}

void UserProfile::on_btnCreateProfile_clicked()
{
    QString name = ui->txtName->text().trimmed();
    QString email = ui->txtEmail->text().trimmed();
    QString username = ui->txtUsername->text().trimmed();
    QString password = ui->txtPassword->text();

    if (name.isEmpty() || email.isEmpty() || username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields are required.");
        return;
    }

    // 🔸 [Optional] Save to file/vector/database if needed here

    QMessageBox::information(this, "Success", "Profile created successfully!");

    this->close();  // Close the profile creation dialog

    // 🔸 Show login window immediately
    LoginDialog login;
    login.exec();
}
