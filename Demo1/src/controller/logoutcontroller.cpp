#include "logoutcontroller.h"
#include <QCoreApplication>
#include "../global.h"
#include "../logincredentials.h"

LogoutController::LogoutController(QObject* parent)
    :HttpRequestHandler(parent)
{
    qDebug("LogoutController: created");
}

LogoutController::~LogoutController()
{
    qDebug("LogoutController: deleted");
}

void LogoutController::service(HttpRequest& request, HttpResponse& response)
{
    Q_UNUSED(request)
    // Get current session, if pager exist remove it
    HttpSession session=sessionStore->getSession(request,response);
    if (session.contains("pager"))
    {
        session.set("pager", "");
    }
    response.redirect("/");
}
