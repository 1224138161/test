#include "MainWindow.h"

cMainWindow::cMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(100, 100);

    InitWnd();
    InitMenu();
}

cMainWindow::~cMainWindow()
{
}

void cMainWindow::InitWnd()
{
    resize(400, 300);
    QWidget *mainWnd = new QWidget;
    setCentralWidget(mainWnd);
    QVBoxLayout *vMainLayout = new QVBoxLayout(mainWnd);
    vMainLayout->setContentsMargins(0, 0, 0, 0);
    vMainLayout->setSpacing(0);

    QLabel *currentTimeLab = new QLabel(this);
    QTimer *currentTimeTimer = new QTimer(this);
    currentTimeTimer->start(1000);
    connect(currentTimeTimer, &QTimer::timeout, [currentTimeLab](){
        currentTimeLab->setText(QDateTime::currentDateTime().toString());
    });

    QPushButton *blogListBtn = new QPushButton(tr("BlogList"), this);
    //connect(blogListBtn, QPushButton::clicked(), );

    QPushButton *diaryListBtn = new QPushButton(tr("DiaryList"), this);

    vMainLayout->addWidget(currentTimeLab, 0, Qt::AlignCenter);
    vMainLayout->addWidget(blogListBtn, 1, Qt::AlignCenter);
    vMainLayout->addWidget(diaryListBtn, 2, Qt::AlignCenter);
}

void cMainWindow::InitMenu()
{
    QMenuBar *mainMenuBar = menuBar();
    setMenuBar(mainMenuBar);

    QMenu *fileMenu = new QMenu("file");

    mainMenuBar->addMenu(fileMenu);
}

