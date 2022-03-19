/**
  @file
  @author Stefan Frings
*/

#include <QDateTime>
#include "../global.h"
#include "logincontroller.h"

LoginController::LoginController()
{}

void LoginController::service(HttpRequest& request, HttpResponse& response)
{
    QByteArray auth = request.getHeader("Authorization");
    if (auth.isNull())
    {
        qInfo("User is not logged in");
        response.setStatus(401,"Unauthorized");
        response.setHeader("WWW-Authenticate","Basic realm=Please login with any name and password");
    }
    else
    {
        QByteArray decoded = QByteArray::fromBase64(auth.mid(6)); // Skip the first 6 characters ("Basic ")
        qInfo("Authorization request from %s",qPrintable(decoded));
        QList<QByteArray> parts = decoded.split(':');
        QByteArray name=parts[0];
        QByteArray password=parts[1];

        response.setHeader("Content-Type", "text/html; charset=UTF-8");

        response.write("<html><body>");
        response.write("You logged in as name=");
        response.write(name);
        response.write(" with password=");
        response.write(password);
        response.write("</body></html>", true);
    }
}
