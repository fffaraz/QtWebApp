/**
  @file
  @author Stefan Frings
*/

#ifndef TEMPLATECONTROLLER_H
#define TEMPLATECONTROLLER_H

#include "httprequest.h"
#include "httpresponse.h"
#include "httprequesthandler.h"

using namespace stefanfrings;

/**
  This controller generates a website using the template engine.
*/

class TemplateController : public HttpRequestHandler {
    Q_OBJECT
    Q_DISABLE_COPY(TemplateController)
public:

    /** Constructor */
    TemplateController();

    /** Generates the response */
    void service(HttpRequest& request, HttpResponse& response);
};

#endif // TEMPLATECONTROLLER_H
