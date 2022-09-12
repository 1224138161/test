#include "cchooselevelscene.h"

CChooseLevelScene::CChooseLevelScene(QWidget *parent) : QMainWindow(parent)
    , m_menuBar(Q_NULLPTR)
    , m_menu(Q_NULLPTR)
{
    Init();
    SetMyMenu();
}

void CChooseLevelScene::Init()
{
    setFixedSize(390, 570);
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setWindowTitle("Select Level");

    pushbutton_back = new CMyPushbutton(this, ":/res/BackButton.png", ":/res/BackButtonSelected.png");
    pushbutton_back->move(this->width() - pushbutton_back->width(), this->height() - pushbutton_back->height());
    connect(pushbutton_back, &CMyPushbutton::clicked, this, &CChooseLevelScene::close);
}

void CChooseLevelScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0, 0, width(), height(), pix);
    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width() - pix.width()) * 0.5, 30, pix.width(), pix.height(), pix);
}

void CChooseLevelScene::SetMyMenu()
{
    m_menuBar = menuBar();
    this->setMenuBar(m_menuBar);

    m_menu = new QMenu("start");
    m_menuBar->addMenu(m_menu);

    QAction *action_quit = new QAction("quit");
    connect(action_quit, &QAction::triggered, this, &CChooseLevelScene::close);

    QList<QAction*> list_action;
    list_action.append(action_quit);

    m_menu->addActions(list_action);
}
