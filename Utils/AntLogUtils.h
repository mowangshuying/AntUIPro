#pragma once

#include <QString>


class AntLogUtils {
    public:
        enum LogLevel {
            Debug,
            Info,
            Warning,
            Err,
        };
    public:
        AntLogUtils();

        static void __init__();
        static void __deinit__();

        static QString time();
        static QString fileName(const QString &filePath);
        static messageOutPut(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    public:
        static QFile *m_gLogFile;
        static QtMessageHandler m_gDefaultHandler;
};
