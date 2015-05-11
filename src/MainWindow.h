/**
 * 主窗口现实类
 * @hurley
 * 2013/12/04
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QPushButton;
class QLabel;
class GameView;
class QVBoxLayout;
class QHBoxLayout;
class QWidget;
class GameControl;
class QMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /// 移动窗口到屏幕中央
    void moveWindowCenter();

    /// 设置游戏控制器
    void setGameControl(GameControl *gameControl);

    /// 获得游戏控制器
    GameControl *getGameControl();

    /// 获取显示区域对象
    GameView *getView();

public slots:
    /// 新游戏
    void newGame();

    /// 切换到低级
    void lowLevel();

    /// 切换到中级
    void middLevel();

    /// 切换到高级
    void highLevel();

    /// 关于对话框
    void about();

private:
    void CreateMainWidget();
    void CreateAction();
    void CreateMenu();

    QVBoxLayout *vLayout;
    QHBoxLayout *hLayout;
    QLabel *lab_time;
    QLabel *lab_timehigh;
    QLabel *lab_timelow;
    QPushButton *state_btn;
    QLabel *lab_mines;
    QLabel *lab_mineshigh;
    QLabel *lab_mineslow;
    QWidget *mainWidget;
    GameView *gameView_;
    GameControl *gameControl_;

    QAction *newGameAction;
    QAction *lowLevelAction;
    QAction *middLevelAction;
    QAction *highLevelAction;
    QAction *aboutAction;

    QMenu *gameMenu;
    QMenu *levelMenu;
    QMenu *aboutMenu;
};

#endif // MAINWINDOW_H
