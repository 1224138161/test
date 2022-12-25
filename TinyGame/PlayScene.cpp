#include "PlayScene.h"

cPlayScene::cPlayScene(QWidget *parent, int level)
    : m_isWin(false)
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

    QSound* winSound = new QSound(":/res/LevelWinSound.wav", this);
    QSound* conflipSound = new QSound(":/res/ConFlipSound.wav", this);

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

    QLabel* winLab = new QLabel(this);
    QPixmap winPix;
    winPix.load(":/res/LevelCompletedDialogBg.png");
    winLab->setFixedSize(winPix.size());
    winLab->setPixmap(winPix);
    winLab->move((width() - winPix.width()) * 0.5, -winPix.height());

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
            m_coinBtnArr[i][j] = coinBtn;
            if(m_arr[i][j])
            {
                coinBtn->SetPix(":/res/Coin0001.png");
            }
            else
            {
                coinBtn->SetPix(":/res/Coin0008.png");
            }
            coinBtn->setGeometry(59 + i * 50, 204 + j * 50, 50, 50);
            coinBtn->m_posX = i;
            coinBtn->m_posY = j;
            coinBtn->m_flag = m_arr[i][j];
            connect(coinBtn, &cCoinBtn::clicked, this, [=](){
                if (m_isWin) return;

                conflipSound->stop();
                conflipSound->play();

                coinBtn->ChangeFlag();
                if (coinBtn->m_posX + 1 <= 3) m_coinBtnArr[coinBtn->m_posX + 1][coinBtn->m_posY]->ChangeFlag();
                if (coinBtn->m_posX - 1 >= 0) m_coinBtnArr[coinBtn->m_posX - 1][coinBtn->m_posY]->ChangeFlag();
                if (coinBtn->m_posY + 1 <= 3) m_coinBtnArr[coinBtn->m_posX][coinBtn->m_posY + 1]->ChangeFlag();
                if (coinBtn->m_posY - 1 >= 0) m_coinBtnArr[coinBtn->m_posX][coinBtn->m_posY - 1]->ChangeFlag();

                m_isWin = true;
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (m_coinBtnArr[i][j]->m_flag == false)
                        {
                            m_isWin = false;
                            break;
                        }
                    }
                }
                if (m_isWin)
                {
                    QPropertyAnimation* animation = new QPropertyAnimation(winLab, "geometry");
                    animation->setDuration(1000);
                    animation->setStartValue(winLab->geometry());
                    QRect endValue = winLab->geometry();
                    endValue.setY(-winLab->y());
                    animation->setEndValue(endValue);
                    animation->setEasingCurve(QEasingCurve::OutBounce);
                    animation->start();

                    conflipSound->stop();
                    winSound->play();
                }
            });
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
