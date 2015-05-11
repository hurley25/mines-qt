#include <QtGui>

#include "MainWindow.h"
#include "GameView.h"
#include "GameControl.h"
#include "Mines.h"

GameView::GameView(MainWindow *window, QWidget *parent)
    : QWidget(parent)
{
    this->window_ = window;
    this->mines_view_ = NULL;
}

GameView::GameView(int x, int y, MainWindow *window, QWidget *parent)
    : QWidget(parent)
{
    this->window_ = window;
    setViewSize(x, y);
}

GameView::~GameView()
{

}

void GameView::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    QImage image(":/res/picture/blank.bmp");

    for (int x = 0; x < game_x_; ++x) {
        for (int y = 0; y < game_y_; ++y) {
            paint.drawImage(x * PIC_MINE_SIZE, y * PIC_MINE_SIZE, image,
                            0, mines_view_[x][y] * PIC_MINE_SIZE, PIC_MINE_SIZE, PIC_MINE_SIZE);
        }
    }
}

void GameView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        // 左键单击发生了
        int view_x = event->x() / PIC_MINE_SIZE;
        int view_y = event->y() / PIC_MINE_SIZE;
        this->window_->getGameControl()->leftMousePress(view_x, view_y);
        return;
    } else if (event->button() == Qt::RightButton) {
        // 右键单击发生了
        int view_x = event->x() / PIC_MINE_SIZE;
        int view_y = event->y() / PIC_MINE_SIZE;
        this->window_->getGameControl()->rightMousePress(view_x, view_y);
        return;
    }
    QWidget::mousePressEvent(event);
}

void GameView::setViewSize(int x, int y)
{
    this->game_x_ = x;
    this->game_y_ = y;
    this->setFixedSize(x * PIC_MINE_SIZE, y * PIC_MINE_SIZE);
    this->window_->setFixedSize(x * PIC_MINE_SIZE + VIEW_WIDTH_BRINK,
                           y * PIC_MINE_SIZE + VIEW_HEIGHT_BRINK);
    this->window_->moveWindowCenter();
}

void GameView::setMinesViewData(MinesModel::MinesType mines_view[][MinesModel::MODEL_MAX_Y])
{
    this->mines_view_ = mines_view;
}
