#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_menu = Q_NULLPTR;

    setMainWindow();
    setMyMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setMainWindow()
{
    setFixedSize(390, 570);
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setWindowTitle("CoinFlip");
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, width(), height(), pix);
    pix.load(":/res/Title.png");
    painter.drawPixmap(10, 30, pix.width() * 0.5, pix.height() * 0.5, pix);
}

void MainWindow::setMyMenu()
{
    m_menu = new QMenu("start");
    ui->menubar->addMenu(m_menu);

    QAction *action_quit = new QAction("quit");
    connect(action_quit, &QAction::triggered, this, &MainWindow::close);

    QList<QAction*> list_action;
    list_action.append(action_quit);

    m_menu->addActions(list_action);
}

