#include <QApplication>
#include <QtGui>

#include "MainWindow.h"
#include "MinesModel.h"
#include "GameControl.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 处理中文乱码问题
    QTextCodec *codec = QTextCodec::codecForName("system");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);

    // 加载Qt自带的控件汉化文件
    QTranslator translator;
    translator.load(":/res/language/qt_zh_CN.qm");
    app.installTranslator(&translator);

    MainWindow *view = new MainWindow();
    MinesModel *model = new MinesModel();
    GameControl *control = new GameControl(view, model);
    view->setGameControl(control);

    view->show();

    return app.exec();
}
