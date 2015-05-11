#include <QtGui>

#include "MainWindow.h"
#include "GameView.h"
#include "GameControl.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    CreateAction();
    CreateMenu();
    CreateMainWidget();
    this->setWindowTitle(tr("扫雷 Alpha 1"));
}

MainWindow::~MainWindow()
{

}

void MainWindow::setGameControl(GameControl *gameControl)
{
    this->gameControl_ = gameControl;
}

GameControl *MainWindow::getGameControl()
{
    return this->gameControl_;
}

GameView *MainWindow::getView()
{
    return this->gameView_;
}

void MainWindow::newGame()
{
    this->gameControl_->restartGame();
}

void MainWindow::lowLevel()
{
    this->gameControl_->resetLevel(GameControl::level_low);
}

void MainWindow::middLevel()
{
    this->gameControl_->resetLevel(GameControl::level_midd);
}

void MainWindow::highLevel()
{
    this->gameControl_->resetLevel(GameControl::level_high);
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("关于 扫雷"),
                tr("<h2>扫雷 测试版</h2>"
                    "<p>Copyright (C) 2013 XiYouLinux Group</p>"
                   "<p>就是一个扫雷，没啥特殊的东西。</p>"));
}

void MainWindow::moveWindowCenter()
{
    this->move((qApp->desktop()->width() - this->width()) >> 1,
               (qApp->desktop()->height() - this->height()) >> 1);
}

void MainWindow::CreateMainWidget()
{
    lab_time = new QLabel(tr("时间："));
    lab_timehigh = new QLabel;
    lab_timelow = new QLabel;

    state_btn = new QPushButton;
    state_btn->setIcon(QIcon(":/res/picture/orig.bmp"));
    state_btn->setIconSize(QSize(PIC_FACE_SIZE, PIC_FACE_SIZE));
    state_btn->setFixedSize(PIC_FACE_SIZE + PIC_FACE_BRINK, PIC_FACE_SIZE + PIC_FACE_BRINK);
    connect(state_btn, SIGNAL(clicked()), this, SLOT(newGame()));

    lab_mines = new QLabel(tr("雷数："));
    lab_mineshigh = new QLabel;
    lab_mineslow = new QLabel;

    hLayout = new QHBoxLayout;
    hLayout->addWidget(lab_time);
    hLayout->addWidget(lab_timehigh);
    hLayout->addWidget(lab_timelow);
    hLayout->addStretch();
    hLayout->addWidget(state_btn);
    hLayout->addStretch();
    hLayout->addWidget(lab_mines);
    hLayout->addWidget(lab_mineshigh);
    hLayout->addWidget(lab_mineslow);

    gameView_ = new GameView(this);

    vLayout = new QVBoxLayout;
    vLayout->addLayout(hLayout);
    vLayout->addWidget(gameView_);

    mainWidget = new QWidget;
    mainWidget->setLayout(vLayout);

    this->setCentralWidget(mainWidget);
}

void MainWindow::CreateAction()
{
    newGameAction = new QAction(tr("新游戏"), this);
    newGameAction->setStatusTip(tr("新游戏"));
    connect(newGameAction, SIGNAL(triggered()), this, SLOT(newGame()));

    lowLevelAction = new QAction(tr("低级"), this);
    lowLevelAction->setStatusTip(tr("低级"));
    connect(lowLevelAction, SIGNAL(triggered()), this, SLOT(lowLevel()));

    middLevelAction = new QAction(tr("中级"), this);
    middLevelAction->setStatusTip(tr("中级"));
    connect(middLevelAction, SIGNAL(triggered()), this, SLOT(middLevel()));

    highLevelAction = new QAction(tr("高级"), this);
    highLevelAction->setStatusTip(tr("高级"));
    connect(highLevelAction, SIGNAL(triggered()), this, SLOT(highLevel()));

    aboutAction = new QAction(tr("关于"), this);
    aboutAction->setStatusTip(tr("关于"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
}

void MainWindow::CreateMenu()
{
    gameMenu = this->menuBar()->addMenu(tr("游戏"));
    gameMenu->addAction(newGameAction);
    levelMenu = gameMenu->addMenu(tr("级别"));
    levelMenu->addAction(lowLevelAction);
    levelMenu->addAction(middLevelAction);
    levelMenu->addAction(highLevelAction);

    aboutMenu = this->menuBar()->addMenu(tr("关于"));
    aboutMenu->addAction(aboutAction);
}
