#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_menu(Q_NULLPTR)
{
    ui->setupUi(this);

    setMainWindow();
    setMyMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setMainWindow()
{
    setFixedSize(320, 588);
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setWindowTitle("CoinFlip");

    CMyPushbutton *pushbutton_start = new CMyPushbutton(this, ":/res/MenuSceneStartButton.png");
    pushbutton_start->move(this->width() * 0.5 - pushbutton_start->width() * 0.5, this->height() * 0.7);

    CChooseLevelScene *window_levelScene = new CChooseLevelScene();
    connect(pushbutton_start, &CMyPushbutton::clicked, this, [=](){
        pushbutton_start->Zoom();
        QTimer::singleShot(200, this, [=](){
            window_levelScene->setGeometry(geometry());
            window_levelScene->show();
            this->close();
        });
    });
    connect(window_levelScene, &CChooseLevelScene::Sig_back, this, [=](){
        setGeometry(window_levelScene->geometry());
        show();
        window_levelScene->close();
    });
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

