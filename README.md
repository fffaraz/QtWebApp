# QtWebApp HTTP Server in C++

Fork from Stefan's QtWebApp: http://stefanfrings.de/qtwebapp/index-en.html

QtWepApp is a HTTP server library in C++, inspired by Java Servlets. For Linux, Windows, Mac OS and many other operating systems that the Qt Framework supports.

QtWebApp contains the following components:

* HTTP(S) Server
* Template Engine
* File Logger
* These components can be used independently of each other.
* The logger improves disk space and performance by retaining debug messages in memory until an error occurs. No debug messages are written as long everything works fine. Changes to the configuration of the logger become active automatically without program restart. A very small example:

### Usage

This short example demonstrates how to use the library:

```C++
// The request handler receives and responds HTTP requests
void MyRequestHandler::service(HttpRequest& request, HttpResponse& response)
{
    // Get a request parameters
    QByteArray username = request.getParameter("username");

    // Set a response header
    response.setHeader("Content-Type", "text/html; charset=UTF-8");

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

### Tutorial

* http://stefanfrings.de/qtwebapp/tutorial/index.html

### API documentation

* http://stefanfrings.de/qtwebapp/api/index.html

### See also

* https://github.com/StefanFrings/QtWebApp
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
