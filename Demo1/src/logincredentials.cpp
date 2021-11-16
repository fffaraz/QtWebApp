/**
  @file
  @author Stefan Frings
*/

#include <QCoreApplication>
#include "global.h"
#include "logincredentials.h"

LoginCredentials::LoginCredentials(QObject* parent)
    :HttpRequestHandler(parent)
{
    qDebug("LoginCredentials: created");
}

LoginCredentials::~LoginCredentials()
{
    qDebug("LoginCredentials: deleted");
}

bool LoginCredentials::isValid(QByteArray userName, QByteArray password)
{
    /*
     *  FIXME TODO Implement your Validation here
     *  I made this a separate function since this can get complex depending on your needs
     */
    if (userName.compare("Spongebob")!=0 || password.compare("secret")!=0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool LoginCredentials::validate(HttpRequest& request, HttpResponse& response)
{
    QByteArray auth = request.getHeader("Authorization");
    if (auth.isNull())
    {
        qInfo("User is not logged in");
        return false;
    }
    else
    {
        // This only means someone loged in, the Credentials are unknown
        QByteArray decoded = QByteArray::fromBase64(auth.mid(6)); // Skip the first 6 characters ("Basic ")
        qInfo("Authorization request from %s",qPrintable(decoded));
        QList<QByteArray> parts = decoded.split(':');
        QByteArray name=parts[0];
        QByteArray password=parts[1];
        // Get current session, or create a new one
        HttpSession session=sessionStore->getSession(request,response);

        if (request.getPath() == "/login")
        {
            if (session.contains("pager"))
            {
                if (session.get("pager") == "")
                {
                    session.set("pager","logon"); // means we are in a loop
                    return false;
                }
                else if (session.get("pager") == "logon")
                {
                    if (isValid(name, password))
                    {
                        setUserName(name);
                        setPassword(password);
                        session.set("pager",session.getId()); // means logged on with Session ID for security
                        return true;
                    }
                    else
                    {
                        session.set("pager",""); // means logged off
                        return false;
                    }
                }
                else
                {
                    return false; // should not get here unless session has expired but a return is required
                }
            }
            else
            {
                if (isValid(name, password))
                {
                    setUserName(name);
                    setPassword(password);
                    session.set("pager",session.getId()); // means logged on with Session ID for security
                    return true;
                }
                else
                {
                    session.set("pager",""); // means logged off
                    return false;
                }
            }
        }
        else
        {
            if (session.contains("pager"))
            {
                if (session.get("pager") == session.getId())
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false; // we should never get here but a return is required
            }
        }
    }
}

QByteArray LoginCredentials::getUserName()
{
    return userName;
}

void LoginCredentials::setUserName(const QByteArray& thisUserName)
{
    userName = thisUserName;
}

QByteArray LoginCredentials::getPassword()
{
    return password;
}

void LoginCredentials::setPassword(const QByteArray& thisPassword)
{
    password = thisPassword;
}
