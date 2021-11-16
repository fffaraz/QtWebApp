/**
  @file
  @author Stefan Frings
*/

#include <QDateTime>
#include "../global.h"
#include "logincontroller.h"
#include "../logincredentials.h"

LoginController::LoginController()
{}

void LoginController::service(HttpRequest& request, HttpResponse& response)
{
    LoginCredentials *myLoginCredentials = new LoginCredentials(this);
    if (myLoginCredentials->validate(request,response))
    {
        response.setHeader("Content-Type", "text/html; charset=UTF-8");
        response.write("<html><body>");
        response.write("You logged in as name=");
        response.write(myLoginCredentials->getUserName());
        response.write("with password=");
        response.write(myLoginCredentials->getPassword());
        response.write("</body></html>", true);
    }
    else
    {
        qInfo("User is not logged in");
        response.setStatus(401,"Unauthorized");
        response.setHeader("WWW-Authenticate","Basic realm=Please login with any name and password");
    }
}
