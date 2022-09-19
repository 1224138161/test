#include "../header/DiaryEditor.h"

cDiaryEditor::cDiaryEditor(QWidget *parent)
    : QWidget(parent)
    , m_textEdit(nullptr)
{
    InitWnd();
    InitData();
}

void cDiaryEditor::InitWnd()
{
    QVBoxLayout *vMainLayout = new QVBoxLayout(this);
    vMainLayout->setContentsMargins(0, 0, 0, 0);
    vMainLayout->setSpacing(0);

    QLabel *currentDateLab = new QLabel(this);
    currentDateLab->setText(QDate::currentDate().toString("yyyy-MM-dd"));
    // m_textEdit
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
    connect(m_saveBtn, &QPushButton::clicked, this, &cDiaryEditor::SaveDiary);
    // readFileBtn
    QPushButton *readFileBtn = new QPushButton("read file", bottomWnd);
    readFileBtn->setStyleSheet("border: none; background-color: rgb(133,116,116);");
    readFileBtn->setFixedSize(100, 50);
    // backBtn
    QPushButton *backBtn = new QPushButton("back", bottomWnd);
    backBtn->setStyleSheet("border: none; background-color: rgb(187,174,159);");
    backBtn->setFixedSize(100, 50);
    connect(backBtn, &QPushButton::clicked, this, [=](){
        emit Sig_back();
    });

    hBottomLayout->addWidget(m_saveBtn);
    hBottomLayout->addSpacing(5);
    hBottomLayout->addWidget(readFileBtn);
    hBottomLayout->addSpacing(5);
    hBottomLayout->addWidget(backBtn);
    hBottomLayout->addStretch();
    // END bottomWnd

    vMainLayout->addWidget(currentDateLab, 0, Qt::AlignCenter);
    vMainLayout->addWidget(m_textEdit);
    vMainLayout->addWidget(bottomWnd);
}

void cDiaryEditor::InitData()
{
    m_currentDate = QDate::currentDate();
    m_qStrPath = QDir::currentPath() + PATH_DIARY + m_currentDate.toString("/yyyy");
    QDir qDirPath(m_qStrPath);
    if (qDirPath.exists())
    {
        QFile qfileDiary(m_qStrPath + m_currentDate.toString("/yyyy-MM-dd.txt"));
        if (qfileDiary.exists())
        {
            qDebug() << qfileDiary;
            if (qfileDiary.open(QIODevice::ReadOnly))
            {
                QByteArray array = qfileDiary.readAll();
                m_textEdit->setPlainText(array.data());
                qfileDiary.close();
            }
        }
    }
}

void cDiaryEditor::SaveDiary()
{
    QDir qDirPath(m_qStrPath);
    if (!qDirPath.exists())
    {
        qDirPath.mkpath(m_qStrPath);
    }
    QFile qfileDiary(m_qStrPath + m_currentDate.toString("/yyyy-MM-dd.txt"));
    if (!qfileDiary.open(QIODevice::WriteOnly))
    {
        qDebug() << "open file failed, cant save";
        return;
    }
    qfileDiary.write(m_textEdit->document()->toPlainText().toStdString().data());
    qfileDiary.close();
    emit Sig_back();
}

void cDiaryEditor::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
}
