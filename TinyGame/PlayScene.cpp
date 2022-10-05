#include "PlayScene.h"

cPlayScene::cPlayScene(QWidget *parent, int level)
{
    setFixedSize(parent->size());
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

    cDataConfig dataConfig;
    if (dataConfig.m_data.find(m_levelIndex) == dataConfig.m_data.end())
    {
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            m_arr[i][j] = dataConfig.m_data[m_levelIndex][i][j];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            QLabel *coinBgLab = new QLabel(this);
            coinBgLab->setGeometry(57 + i * 50, 200 + j * 50, 50, 50);
            coinBgLab->setPixmap(QPixmap(":/res/BoardNode.png"));

            cCoinBtn *coinBtn = new cCoinBtn(this);
            if(m_arr[i][j])
            {
                coinBtn->SetPix(":/res/Coin0001.png");
            }
            else
            {
                coinBtn->SetPix(":/res/Coin0008.png");
            }
            coinBtn->setGeometry(59 + i * 50, 204 + j * 50, 50, 50);
        }
    }
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
