/**
 * 游戏视图类
 * @hurley
 * 2013/12/04
 */

#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>

#include "MinesModel.h"

class MainWindow;

class GameView : public QWidget
{
    Q_OBJECT
public:
    /// 构造函数
    explicit GameView(MainWindow *window, QWidget *parent = 0);
    explicit GameView(int x, int y, MainWindow *window, QWidget *parent = 0);

    /// 析构函数
    ~GameView();

    /// 设置视图尺寸
    void setViewSize(int x, int y);

    /// 设置雷区显示数据指针
    void setMinesViewData(MinesModel::MinesType mines_view[][MinesModel::MODEL_MAX_Y]);

    /// 绘制游戏区域图
    virtual void paintEvent(QPaintEvent * event);

    /// 鼠标消息
    virtual void mousePressEvent(QMouseEvent * event);

private:
    int game_x_;
    int game_y_;
    MainWindow *window_;
    MinesModel::MinesType (*mines_view_)[MinesModel::MODEL_MAX_Y];
};

#endif // GAMEWIDGET_H
