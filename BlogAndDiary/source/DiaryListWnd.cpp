#include "../header/DiaryListWnd.h"

cDiaryListWnd::cDiaryListWnd(QWidget *parent)
    : QWidget(parent)
    , m_listWnd(nullptr)
    , m_addDiaryBtn(nullptr)
{
    InitWnd();
}

void cDiaryListWnd::InitWnd()
{
    QVBoxLayout *vMainLayout = new QVBoxLayout(this);
    vMainLayout->setContentsMargins(0, 0, 0, 0);
    vMainLayout->setSpacing(0);
    // START m_listWnd
    m_listWnd = new QWidget(this);
    QGridLayout *gListLayout = new QGridLayout(m_listWnd);
    gListLayout->setContentsMargins(0, 0, 0, 0);
    gListLayout->setSpacing(0);
    gListLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QString qStrPath = QDir::currentPath() + PATH_DIARY;
    QDir qDirPath(qStrPath);
    if (qDirPath.exists())
    {
        QStringList dirList = qDirPath.entryList(QDir::Dirs);
        dirList.removeOne(".");
        dirList.removeOne("..");
        for (int i = 0; i < dirList.size(); i++)
        {
            QPushButton *yearsBtn = new QPushButton(m_listWnd);
            yearsBtn->setFixedSize(width() / 4, height() / 7);
            //yearsBtn->setStyleSheet("border: none; background-color: rgb(122,103,122);");
            yearsBtn->setText(dirList.at(i));
            gListLayout->addWidget(yearsBtn, i / 4, i % 4);
        }
    }
    // END m_listWnd
    // m_addDiaryBtn
    m_addDiaryBtn = new QPushButton("add diary", this);
    m_addDiaryBtn->setStyleSheet("border: none; background-color: rgb(122,103,122);");
    m_addDiaryBtn->setFixedSize(width(), height() / 7);
    connect(m_addDiaryBtn, &QPushButton::clicked, [=](){
        emit Sig_addDiary();
    });

    vMainLayout->addWidget(m_listWnd);
    vMainLayout->addWidget(m_addDiaryBtn);
}

void cDiaryListWnd::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    QList<QPushButton*> btnList = findChildren<QPushButton*>();
    for (int i = 0; i < btnList.size(); i++)
    {
        btnList.at(i)->setFixedSize(width() / 4, height() / 7);
    }
    m_addDiaryBtn->setFixedSize(width(), height() / 7);
}
