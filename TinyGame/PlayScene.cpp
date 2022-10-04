#include "PlayScene.h"

cPlayScene::cPlayScene(QWidget *parent, int level)
{
    setGeometry(parent->geometry());
    m_levelIndex = level;
    Init();
    SetMyMenu();
}

void cPlayScene::Init()
{
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    QString qStrText = QString("Level %1").arg(m_levelIndex);
    setWindowTitle(qStrText);

    m_backBtn = new CMyPushbutton(this, ":/res/BackButton.png", ":/res/BackButtonSelected.png");
    m_backBtn->move(this->width() - m_backBtn->width(), this->height() - m_backBtn->height());
    connect(m_backBtn, &CMyPushbutton::clicked, this, [=](){
        emit Sig_back();
    });

    QLabel *levelLab = new QLabel(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    levelLab->setFont(font);
    levelLab->setGeometry(30, height() - 50, 120, 50);
    levelLab->setText(qStrText);
}

void cPlayScene::SetMyMenu()
{
    m_menuBar = menuBar();
    this->setMenuBar(m_menuBar);

    m_menu = new QMenu("start");
    m_menuBar->addMenu(m_menu);

    QAction *action_quit = new QAction("quit");
    connect(action_quit, &QAction::triggered, this, &cPlayScene::close);

    QList<QAction*> list_action;
    list_action.append(action_quit);

    m_menu->addActions(list_action);
}

void cPlayScene::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, width(), height(), pix);
    pix.load(":/res/Title.png");
    painter.drawPixmap(10, 30, pix.width() * 0.5, pix.height() * 0.5, pix);
}
