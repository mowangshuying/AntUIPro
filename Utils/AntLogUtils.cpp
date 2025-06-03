#include "AntLogUtils.h"

QFile *FluLogUtils::gFileLog = nullptr;
QtMessageHandler FluLogUtils::gDefaultHandler = nullptr;

void AntLogUtils::__init__()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString timeStr = dateTime.toString("[yyyy-MM-dd][hh_mm_ss_zzz]");
    QString filePath = QString("./log/%1.log").arg(timeStr);
    gFileLog = new QFile(filePath);
    if (!gFileLog->open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        delete gFileLog;
        gFileLog = nullptr;
        return;
    }

    gDefaultHandler = qInstallMessageHandler(myMessageOutput);
}

void AntLogUtils::__deinit()
{
    if (gFileLog == nullptr)
        return;

    gFileLog->close();
    delete gFileLog;
    gFileLog = nullptr;
}

QString AntLogUtils::time()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString timeStr = dateTime.toString("yyyy-MM-dd hh:mm:ss.zzz");
    return timeStr;
}

QString AntLogUtils::fileName(const char *file)
{
    QString fileStr = file;
    QString fileNameStr = fileStr.right(fileStr.size() - fileStr.lastIndexOf("\\") - 1);
    return fileNameStr;
}

void AntLogUtils::messageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    if (gFileLog)
    {
        QTextStream tWrite(gFileLog);
        tWrite << msg << "\n";
        gDefaultHandler(type, context, msg);
    }
    else
    {
        fprintf(stderr, "%s\n", msg.toStdString().c_str());
    }
}
