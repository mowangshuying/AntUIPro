#include "AntLogUtils.h"

QFile *AntLogUtils::m_gLogFile = nullptr;
QtMessageHandler AntLogUtils::m_gDefaultHandler = nullptr;

void AntLogUtils::__init__()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString timeStr = dateTime.toString("[yyyy-MM-dd][hh_mm_ss_zzz]");
    QString filePath = QString("./log/%1.log").arg(timeStr);
    m_gLogFile = new QFile(filePath);
    if (!m_gLogFile->open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        delete m_gLogFile;
        m_gLogFile = nullptr;
        return;
    }

    m_gDefaultHandler = qInstallMessageHandler(messageOutput);
}

void AntLogUtils::__deinit__()
{
    if (m_gLogFile == nullptr)
        return;

    m_gLogFile->close();
    delete m_gLogFile;
    m_gLogFile = nullptr;
}

QString AntLogUtils::time()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString timeStr = dateTime.toString("yyyy-MM-dd hh:mm:ss.zzz");
    return timeStr;
}

QString AntLogUtils::fileName(const char* filename)
{
    QString fileStr = filename;
    QString fileNameStr = fileStr.right(fileStr.size() - fileStr.lastIndexOf("\\") - 1);
    return fileNameStr;
}

void AntLogUtils::messageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    if (m_gLogFile != nullptr)
    {
        QTextStream tWrite(m_gLogFile);
        tWrite << msg << "\n";
        m_gDefaultHandler(type, context, msg);
    }
    else
    {
        fprintf(stderr, "%s\n", msg.toStdString().c_str());
    }
}
