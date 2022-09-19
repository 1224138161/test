#ifndef CDIARYEDITOR_H
#define CDIARYEDITOR_H

#include <QWidget>
#include "Include.h"

class cDiaryEditor : public QWidget
{
    Q_OBJECT
public:
    explicit cDiaryEditor(QWidget *parent = nullptr);
private:
    void InitWnd();
    void InitData();
    void SaveDiary();
    void resizeEvent(QResizeEvent *event);
private:
    QTextEdit *m_textEdit;
    QPushButton *m_saveBtn;
    QDate m_currentDate;
    QString m_qStrPath;
signals:
    void Sig_back();
};

#endif // CDIARYEDITOR_H
