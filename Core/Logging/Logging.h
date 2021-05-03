#ifndef LOGGING_H
#define LOGGING_H

#include <QString>

class Logging
{
public:
    static void log(QString );
    static void error(QString );
    static void warning(QString );

private:
    static void writeLog(QString );
};

#endif // LOGGING_H
