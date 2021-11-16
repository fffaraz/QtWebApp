#ifndef LOGOUTCONTROLLER_H
#define LOGOUTCONTROLLER_H

#include "httprequesthandler.h"

using namespace stefanfrings;

/**
  The request mapper dispatches incoming HTTP requests to controller classes
  depending on the requested path.
*/
class LogoutController : public HttpRequestHandler {
    Q_OBJECT
    Q_DISABLE_COPY(LogoutController)
public:

    /**
      Constructor.
      @param parent Parent object
    */
    LogoutController(QObject* parent=0);

    /**
      Destructor.
    */
    ~LogoutController();
    /**
      Dispatch incoming HTTP requests to different controllers depending on the URL.
      @param request The received HTTP request
      @param response Must be used to return the response
    */
    void service(HttpRequest& request, HttpResponse& response);
};

#endif // LOGOUTCONTROLLER_H
