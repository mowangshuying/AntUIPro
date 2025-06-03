#pragma once

#include <QString>
#include <QFile>
#include <QDateTime>

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
        static QString fileName(const char* filename);
        static void messageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    public:
        static QFile *m_gLogFile;
        static QtMessageHandler m_gDefaultHandler;
};

#define LOG_FUNC LOG_DEBUG << ";";
#define LOG_DEBUG                                                                    \
    qDebug().nospace() << "[" << AntLogUtils::time().toStdString().c_str() << "]"    \
                       << "["                                                        \
                       << "debug"                                                    \
                       << "]"                                                        \
                       << "[" << AntLogUtils::fileName(__FILE__).toStdString().c_str() << "][" << __FUNCTION__ << "][" << __LINE__ << "] "

#define LOG_INFO                                                                    \
    qInfo().nospace() << "[" << AntLogUtils::time().toStdString().c_str() << "]" \
                      << "["                                                        \
                      << "info"                                                     \
                      << "]"                                                        \
                      << "[" << AntLogUtils::fileName(__FILE__).toStdString().c_str() << "][" << __FUNCTION__ << "][" << __LINE__ << "] "

#define LOG_WARN                                                                       \
    qWarning().nospace() << "[" << AntLogUtils::time().toStdString().c_str() << "]" \
                         << "["                                                        \
                         << "warn"                                                     \
                         << "]"                                                        \
                         << "[" << AntLogUtils::fileName(__FILE__).toStdString().c_str() << "][" << __FUNCTION__ << "][" << __LINE__ << "] "

#define LOG_ERR                                                                      \
    qDebug().nospace() << "[" << AntLogUtils::time().toStdString().c_str() << "]" \
                       << "["                                                        \
                       << "err"                                                      \
                       << "]"                                                        \
                       << "[" << AntLogUtils::fileName(__FILE__).toStdString().c_str() << "][" << __FUNCTION__ << "][" << __LINE__ << "] "
