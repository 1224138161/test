#include "MainWindow.h"

cMainWindow::cMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_stackedWnd(nullptr)
    , m_blogListBtn(nullptr)
    , m_diaryListBtn(nullptr)
    , m_diaryListWnd(nullptr)
    , m_diaryEditorWnd(nullptr)
{
    setMinimumSize(100, 100);
    resize(400, 300);
    InitWnd();
    InitMenu();
}

cMainWindow::~cMainWindow()
{
}

void cMainWindow::InitWnd()
{
    m_stackedWnd = new QStackedWidget(this);
    setCentralWidget(m_stackedWnd);
    // START mainWnd
    QWidget *mainWnd = new QWidget(this);
    QVBoxLayout *vMainLayout = new QVBoxLayout(mainWnd);
    vMainLayout->setContentsMargins(0, 0, 0, 0);
    vMainLayout->setSpacing(0);
    // currentTimeLab
    QLabel *currentTimeLab = new QLabel(mainWnd);
    QTimer *currentTimeTimer = new QTimer(this);
    currentTimeTimer->start(1000);
    connect(currentTimeTimer, &QTimer::timeout, [currentTimeLab](){
        currentTimeLab->setText(QDateTime::currentDateTime().toString());
    });
    // m_blogListBtn
    m_blogListBtn = new QPushButton(tr("BlogList"), this);
    m_blogListBtn->setStyleSheet("border: none; background-color: rgb(122,103,122);");
    m_blogListBtn->setFixedSize(width(), height() / 3);
    // m_diaryListBtn
    m_diaryListBtn = new QPushButton(tr("DiaryList"), this);
    m_diaryListBtn->setStyleSheet("border: none; background-color: rgb(189,228,225);");
    m_diaryListBtn->setFixedSize(width(), height() / 3);
    connect(m_diaryListBtn, &QPushButton::clicked, [=](){
        if(m_diaryListWnd)
        {
            m_stackedWnd->setCurrentWidget(m_diaryListWnd);
        }
        else
        {
            m_diaryListWnd = new cDiaryListWnd(this);
            connect(m_diaryListWnd, &cDiaryListWnd::Sig_addDiary, this, &cMainWindow::On_addDiary);

            m_stackedWnd->addWidget(m_diaryListWnd);
            m_stackedWnd->setCurrentWidget(m_diaryListWnd);
        }
    });

    vMainLayout->addWidget(currentTimeLab, 0, Qt::AlignCenter);
    vMainLayout->addWidget(m_blogListBtn);
    vMainLayout->addWidget(m_diaryListBtn);
    // END mainWnd

    m_stackedWnd->addWidget(mainWnd);
}

void cMainWindow::InitMenu()
{
    QMenuBar *mainMenuBar = menuBar();
    setMenuBar(mainMenuBar);
    // START fileMenu
    QMenu *fileMenu = new QMenu("file", this);
    QAction *addAct = new QAction("add", this);
    connect(addAct, &QAction::triggered, [=](){

    });
    QAction *quitAct = new QAction("quit", this);
    connect(quitAct, &QAction::triggered, [=](){
        close();
    });

    fileMenu->addAction(addAct);
    fileMenu->addAction(quitAct);
    // End fileMenu

    mainMenuBar->addMenu(fileMenu);
}

void cMainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    m_blogListBtn->setFixedSize(width(), height() / 3);
    m_diaryListBtn->setFixedSize(width(), height() / 3);
    if (m_diaryListWnd)
    {
        m_diaryListWnd->setFixedSize(size());
    }
    if (m_diaryEditorWnd)
    {
        m_diaryEditorWnd->setFixedSize(size());
    }
}

void cMainWindow::On_addDiary()
{
    if (m_diaryEditorWnd)
    {
        m_stackedWnd->setCurrentWidget(m_diaryEditorWnd);
    }
    else
    {
        m_diaryEditorWnd = new cDiaryEditor(this);
        m_diaryEditorWnd->setFixedSize(size());

        m_stackedWnd->addWidget(m_diaryEditorWnd);
        m_stackedWnd->setCurrentWidget(m_diaryEditorWnd);
    }
}


