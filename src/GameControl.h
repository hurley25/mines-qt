/**
 * 游戏控制器
 * @hurley
 * 2013/12/04
 */

#ifndef GAMECONTROL_H
#define GAMECONTROL_H

class MainWindow;
class MinesModel;

struct LevelInfo {
    int x;
    int y;
    int mines;
};

class GameControl
{
public:
    /// 游戏级别枚举值
    enum Level {
        level_low,
        level_midd,
        level_high
    };

    /// 构造函数，默认级别为初级
    GameControl(MainWindow *window, MinesModel *model, GameControl::Level level = level_low);

    /// 析构函数
    ~GameControl();

    /// 新游戏
    void restartGame();

    /// 左键单击
    void leftMousePress(int x, int y);

    /// 右键单击
    void rightMousePress(int x, int y);

    /// 重设游戏级别
    void resetLevel(GameControl::Level level);

private:
    int game_x_;
    int game_y_;
    int game_mines_;

    Level nowLevel_;
    MainWindow *window_;
    MinesModel *model_;
};

#endif // GAMECONTROL_H
