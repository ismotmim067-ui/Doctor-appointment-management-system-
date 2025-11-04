#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QVector>

namespace Ui {
class LoginDialog;
}

// Struct to hold user info
struct User {
    QString username;
    QString password;
    QString role; // "admin" or "user"
};

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    static QString loggedInUser;
    static QString loggedInUserRole;

    // Static public vector of users, can be modified outside
    static QVector<User> users;

private slots:
    void on_btnLogin_clicked();

private:
    Ui::LoginDialog *ui;

    void loadUsers();
};

#endif // LOGINDIALOG_H
