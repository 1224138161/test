#ifndef CDIARYLISTWND_H
#define CDIARYLISTWND_H

#include <QWidget>
#include "Include.h"

class cDiaryListWnd : public QWidget
{
    Q_OBJECT
public:
    explicit cDiaryListWnd(QWidget *parent = nullptr);
private:
    void InitWnd();
    void resizeEvent(QResizeEvent *event);
private:
    QWidget *m_listWnd;
    QPushButton *m_addDiaryBtn;
signals:
    void Sig_addDiary();
};

#endif // CDIARYLISTWND_H
