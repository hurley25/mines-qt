/**
 * 雷区数据定义 Model
 * @hurley
 * 2013/12/04
 */

#ifndef MINESMODEL_H
#define MINESMODEL_H

#include "Mines.h"

class MinesModel
{
public:
    /// 雷区枚举类型
    enum MinesType {
        mine_orig = PIC_ORIG,
        mine_num1 = PIC_NUM1,
        mine_mun2 = PIC_NUM2,
        mine_mun3 = PIC_NUM3,
        mine_mun4 = PIC_NUM4,
        mine_mun5 = PIC_NUM5,
        mine_mun6 = PIC_NUM6,
        mine_mun7 = PIC_NUM7,
        mine_mun8 = PIC_NUM8,
        mine_mine = PIC_MINE,
        mine_red = PIC_MINE_RED,
        mine_err = PIC_MINE_ERR,
        mine_flag = PIC_FLAG,
        mine_ques = PIC_QUES,
        mine_blank = PIC_BLANK,
        mine_origlight = PIC_ORIGLIGHT,
        mine_error_data
    };

    static const int MODEL_MAX_X = 100;
    static const int MODEL_MAX_Y = 100;

    MinesModel();
    MinesModel(int x, int y, int mine_counts);
    ~MinesModel();

    /// 初始化游戏区域
    void resetMinesZone();

    /// 重设游戏区域
    void resetMinesZone(int newX, int newY, int mine_counts);

    typedef MinesType (*PMINES_VIEW_T)[MODEL_MAX_Y];

    /// 获取界面显示数据指针
    PMINES_VIEW_T getViewDataPoint();

    /// 某坐标被单击
    bool leftClickOnCoord(int x, int y);

    /// 某坐标被右击
    void rightClickOnCoord(int x, int y);

    /// 获取某坐标类型
    MinesModel::MinesType getCoordType(int x, int y);

    /// 设置某坐标类型
    void setCoordType(int x, int y, MinesModel::MinesType type);

private:
    bool isAllowPoint(int x, int y);
    void clearMinesMap();
    void createMines();
    void createMinesNumber();

    int mines_x_;
    int mines_y_;
    int mine_counts_;
    int flag_counts_;
    MinesType mines_[MODEL_MAX_X][MODEL_MAX_Y];
    MinesType mines_view_[MODEL_MAX_X][MODEL_MAX_Y];
};

#endif // MINESMODEL_H
