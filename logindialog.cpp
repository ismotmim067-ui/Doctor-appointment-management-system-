#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

QString LoginDialog::loggedInUser = "";
QString LoginDialog::loggedInUserRole = "";

// Define static users vector here
QVector<User> LoginDialog::users = {};

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    // Load default users only if users vector is empty
    if (users.isEmpty())
        loadUsers();
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::loadUsers()
{
    users.append({"mim", "mim123", "mim"});
    users.append({"user", "user123", "user"});
}

void LoginDialog::on_btnLogin_clicked()
{
    QString username = ui->txtUsername->text().trimmed();
    QString password = ui->txtPassword->text();

    bool found = false;

    for (const User &user : users)
    {
        if (user.username == username && user.password == password)
        {
            loggedInUser = user.username;
            loggedInUserRole = user.role;
            found = true;
            break;
        }
    }

    if (found)
    {
        accept();  // Login successful
    }
    else
    {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password");
    }
}
