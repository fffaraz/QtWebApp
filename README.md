# QtWebApp

QtWebApp is a HTTP server library in C++, based on Qt Framework.

Fork from Stefan's QtWebApp: http://stefanfrings.de/qtwebapp/index-en.html

https://github.com/StefanFrings/QtWebApp

### Tutorial

* http://stefanfrings.de/qtwebapp/tutorial/index.html

### API documentation

* http://stefanfrings.de/qtwebapp/api/index.html

### Usage

This short example demonstrates how to use the library:

```C++
// The request handler receives and responds HTTP requests
void MyRequestHandler::service(HttpRequest& request, HttpResponse& response)
{
    // Get a request parameters
    QByteArray username=request.getParameter("username");

    // Set a response header
    response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");

    // Generate the HTML document
    response.write("<html><body>");
    response.write("Hello ");
    response.write(username);
    response.write("</body></html>");
}

// The main program starts the HTTP server
int main(int argc, char *argv[])
{
    QCoreApplication app(argc,argv);

    new HttpListener(
        new QSettings("configfile.ini",QSettings::IniFormat,&app),
        new MyRequestHandler(&app),
        &app);

    return app.exec();
}
```

### See also

* https://github.com/azadkuh/qhttp
* https://github.com/BoostGSoC14/boost.http
* https://github.com/etr/libhttpserver
* https://github.com/msrd0/QtWebApp
* https://github.com/nikhilm/qhttpserver
* https://github.com/nitroshare/qhttpengine
* https://github.com/samiavasil/QtWebApp
* https://github.com/yhirose/cpp-httplib
* https://github.com/eidheim/Simple-Web-Server
* https://gitlab.com/eidheim/Simple-Web-Server
