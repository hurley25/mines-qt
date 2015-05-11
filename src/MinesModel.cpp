#include <cstring>
#include <cstdlib>
#include <ctime>

#include "MinesModel.h"

MinesModel::MinesModel()
{

}

MinesModel::MinesModel(int x, int y, int mine_counts)
{
    resetMinesZone(x, y, mine_counts);
}

MinesModel::~MinesModel()
{

}

void MinesModel::resetMinesZone()
{
    // 清理雷区数据
    clearMinesMap();

    // 布雷
    createMines();

    // 设置雷区数字
    createMinesNumber();
}

void MinesModel::resetMinesZone(int newX, int newY, int mine_counts)
{
    this->mines_x_ = newX;
    this->mines_y_ = newY;
    this->mine_counts_ = mine_counts;
    this->flag_counts_ = 0;
    this->resetMinesZone();
}

MinesModel::PMINES_VIEW_T MinesModel::getViewDataPoint()
{
    return this->mines_view_;
}

bool MinesModel::leftClickOnCoord(int x, int y)
{
    if (!isAllowPoint(x, y)) {
        return false;
    }
    // TODO 各种判断
    this->mines_view_[x][y] = this->mines_[x][y];
    return true;
}

void MinesModel::rightClickOnCoord(int x, int y)
{
    if (isAllowPoint(x, y)) {
        this->mines_view_[x][y] = this->mines_[x][y];
    }
}

MinesModel::MinesType MinesModel::getCoordType(int x, int y)
{
    if (isAllowPoint(x, y)) {
        return this->mines_[x][y];
    }

    return mine_error_data;
}

void MinesModel::setCoordType(int x, int y, MinesModel::MinesType type)
{
    if (isAllowPoint(x, y)) {
        this->mines_[x][y] = type;
    }
}

bool MinesModel::isAllowPoint(int x, int y)
{
    return (x >= 0 && y >= 0 && x < mines_x_ && y < mines_y_);
}

void MinesModel::clearMinesMap()
{
    // 雷区数据初始化
    for (int x = 0; x < mines_x_; ++x) {
        for (int y = 0; y < mines_y_; ++y) {
            this->mines_[x][y] = MinesModel::mine_blank;
            this->mines_view_[x][y] = MinesModel::mine_orig;
        }
    }
}

void MinesModel::createMines()
{
    // 布雷
    int count = 0;
    srand(time(NULL));
    while (count < mine_counts_) {
        int x = rand() % mines_x_;
        int y = rand() % mines_y_;
        if (mines_[x][y] != mine_mine) {
            mines_[x][y] = mine_mine;
            count++;
        }
    }
}

void MinesModel::createMinesNumber()
{
    for (int x = 0; x < mines_x_; ++x) {
        for (int y = 0; y < mines_y_; ++y) {
            int mine_count = 0;

            if (mines_[x][y] == mine_mine) {
                continue;
            }
            if (isAllowPoint(x-1, y-1) && mines_[x-1][y-1] == mine_mine) {
                mine_count++;
            }
            if (isAllowPoint(x, y-1) && mines_[x][y-1] == mine_mine) {
                mine_count++;
            }
            if (isAllowPoint(x+1, y-1) && mines_[x+1][y-1] == mine_mine) {
                mine_count++;
            }
            if (isAllowPoint(x-1, y) && mines_[x-1][y] == mine_mine) {
                mine_count++;
            }
            if (isAllowPoint(x+1, y) && mines_[x+1][y] == mine_mine) {
                mine_count++;
            }
            if (isAllowPoint(x-1, y+1) && mines_[x-1][y+1] == mine_mine) {
                mine_count++;
            }
            if (isAllowPoint(x, y+1) && mines_[x][y+1] == mine_mine) {
                mine_count++;
            }
            if (isAllowPoint(x+1, y+1) && mines_[x+1][y+1] == mine_mine) {
                mine_count++;
            }
            if (mine_count != 0) {
                mines_[x][y] = (MinesType)mine_count;
            }
        }
    }
}
