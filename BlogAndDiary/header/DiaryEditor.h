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
    void resizeEvent(QResizeEvent *event);
private:
    QTextEdit *m_textEdit;
    QPushButton *m_saveBtn;
signals:
    void Sig_back();
    void Sig_save();
};

#endif // CDIARYEDITOR_H
