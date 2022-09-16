#include "../header/DiaryListWnd.h"

cDiaryListWnd::cDiaryListWnd(QWidget *parent)
    : QWidget(parent)
    , m_addDiaryBtn(nullptr)
{
    InitWnd();
}

void cDiaryListWnd::InitWnd()
{
    QVBoxLayout *vMainLayout = new QVBoxLayout(this);
    vMainLayout->setContentsMargins(0, 0, 0, 0);
    vMainLayout->setSpacing(0);
    // m_addDiaryBtn
    m_addDiaryBtn = new QPushButton(this);
    m_addDiaryBtn->setStyleSheet("border: none; background-color: rgb(122,103,122);");
    m_addDiaryBtn->setFixedSize(size());
    connect(m_addDiaryBtn, &QPushButton::clicked, [=](){
        emit Sig_addDiary();
    });

    vMainLayout->addWidget(m_addDiaryBtn);
}

void cDiaryListWnd::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    m_addDiaryBtn->setFixedSize(size());
}
