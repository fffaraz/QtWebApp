/**
  @file
  @author Stefan Frings
*/

#include "requesthandler.h"
#include "filelogger.h"

/** Logger class */
extern FileLogger* logger;

RequestHandler::RequestHandler(QObject* parent)
    :HttpRequestHandler(parent)
{}

void RequestHandler::service(HttpRequest& request, HttpResponse& response)
{
    QByteArray path=request.getPath();
    qDebug("Conroller: path=%s",path.data());

    // Set a response header
    response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");

    // Return a simple HTML document
    response.write("<html><body>Hello World</body></html>",true);

    qDebug("Conroller: finished request");

    // Clear the log buffer
    if (logger)
    {
       logger->clear();
    }
}
