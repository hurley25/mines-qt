#include "GameControl.h"
#include "MainWindow.h"
#include "GameView.h"
#include "MinesModel.h"

static LevelInfo level_info[3] = {{9, 9, 10}, {16, 16, 40}, {30, 16, 99}};

GameControl::GameControl(MainWindow *window, MinesModel *model, GameControl::Level level)
{
    this->nowLevel_ = level;
    this->window_ = window;
    this->model_ = model;
    this->window_->getView()->setMinesViewData(model_->getViewDataPoint());
    resetLevel(level);
}

GameControl::~GameControl()
{

}

void GameControl::restartGame()
{
    this->model_->resetMinesZone();
    this->window_->getView()->update();
}

void GameControl::leftMousePress(int x, int y)
{
    if (!this->model_->leftClickOnCoord(x, y)) {
        // 游戏结束
    }
    this->window_->getView()->update();
}

void GameControl::rightMousePress(int x, int y)
{
    this->model_->rightClickOnCoord(x, y);
    this->window_->getView()->update();
}

void GameControl::resetLevel(GameControl::Level level)
{
    // 获取游戏设置数据
    this->game_x_ = level_info[level].x;
    this->game_y_ = level_info[level].y;
    this->game_mines_ = level_info[level].mines;

    // 重设模型
    this->model_->resetMinesZone(game_x_, game_y_, game_mines_);

    // 重设视图
    this->window_->getView()->setViewSize(game_x_, game_y_);
    this->window_->getView()->update();
}
