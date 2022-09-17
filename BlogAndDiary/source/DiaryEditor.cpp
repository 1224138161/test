#include "../header/DiaryEditor.h"

cDiaryEditor::cDiaryEditor(QWidget *parent)
    : QWidget(parent)
    , m_textEdit(nullptr)
{
    InitWnd();
}

void cDiaryEditor::InitWnd()
{
    QVBoxLayout *vMainLayout = new QVBoxLayout(this);
    vMainLayout->setContentsMargins(0, 0, 0, 0);
    vMainLayout->setSpacing(0);

    m_textEdit = new QTextEdit(this);

    // START bottomWnd
    QWidget *bottomWnd = new QWidget(this);
    bottomWnd->setFixedHeight(50);
    QHBoxLayout *hBottomLayout = new QHBoxLayout(bottomWnd);
    hBottomLayout->setContentsMargins(0, 0, 0, 0);
    hBottomLayout->setSpacing(0);
    // m_saveBtn
    m_saveBtn = new QPushButton("save", bottomWnd);
    m_saveBtn->setStyleSheet("border: none; background-color: rgb(215,205,188);");
    m_saveBtn->setFixedSize(100, 50);
    // readFileBtn
    QPushButton *readFileBtn = new QPushButton("read file", bottomWnd);
    readFileBtn->setStyleSheet("border: none; background-color: rgb(133,116,116);");
    readFileBtn->setFixedSize(100, 50);
    // backBtn
    QPushButton *backBtn = new QPushButton("back", bottomWnd);
    backBtn->setStyleSheet("border: none; background-color: rgb(187,174,159);");
    backBtn->setFixedSize(100, 50);
    connect(backBtn, &QPushButton::clicked, this, &cDiaryEditor::Sig_back);

    hBottomLayout->addWidget(m_saveBtn);
    hBottomLayout->addSpacing(5);
    hBottomLayout->addWidget(readFileBtn);
    hBottomLayout->addSpacing(5);
    hBottomLayout->addWidget(backBtn);
    hBottomLayout->addStretch();
    // END bottomWnd

    vMainLayout->addWidget(m_textEdit);
    vMainLayout->addWidget(bottomWnd);
}

void cDiaryEditor::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
}
