/**
  @file
  @author Stefan Frings
*/
#ifndef LOGINCREDENTIALS_H
#define LOGINCREDENTIALS_H

#include "httprequesthandler.h"

using namespace stefanfrings;

/**
  The request mapper dispatches incoming HTTP requests to controller classes
  depending on the requested path.
*/

class LoginCredentials : public HttpRequestHandler {
    Q_OBJECT
    Q_DISABLE_COPY(LoginCredentials)
public:

    /**
      Constructor.
      @param parent Parent object
    */
    LoginCredentials(QObject* parent=0);

    /**
      Destructor.
    */
    ~LoginCredentials();

    bool validate(HttpRequest& request, HttpResponse& response);

    QByteArray getUserName();
    void setUserName(const QByteArray& thisUserName);

    QByteArray getPassword();
    void setPassword(const QByteArray& thisPassword);

    bool isValid(QByteArray userName, QByteArray password);

    private:
        QByteArray userName = "";
        QByteArray password = "";
};


#endif // LOGINCREDENTIALS_H
