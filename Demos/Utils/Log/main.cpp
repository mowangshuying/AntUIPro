#include <QApplication>
#include <QWidget>
#include "../../../Utils/AntLogUtils.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    AntLogUtils::__init__();
    
    LOG_DEBUG << "--- AntLogUtils Test --- ";
    LOG_INFO << "--- AntLogUtils Test --- ";
     LOG_WARN << "--- AntLogUtils Test --- ";
     LOG_ERR << "--- AntLogUtils Test --- ";

    QWidget w;
    w.show();

    AntLogUtils::__deinit__();
    
    return app.exec();
}