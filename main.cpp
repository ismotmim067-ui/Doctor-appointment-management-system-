#include <QApplication>
#include "userprofile.h"
#include "logindialog.h"
#include "mainwindow.h"
#include "booking.h"
#include "cancellation.h"

// Global booking list (example)
QVector<BookingInfo> bookings;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Step 1: First, show the User Profile creation dialog
    UserProfile profileDialog;
    profileDialog.setWindowTitle("Create Profile");
    profileDialog.exec();  // Wait until user creates profile

    // Step 2: After profile creation, show login dialog
    LoginDialog loginDialog;
    if (loginDialog.exec() == QDialog::Accepted) {

        // Step 3: After successful login, show main window
        QString username = LoginDialog::loggedInUser;
        QString role = LoginDialog::loggedInUserRole;

        MainWindow mainWindow;
        mainWindow.show();

        return a.exec();
    }

    // Login cancelled or failed
    return 0;
}
