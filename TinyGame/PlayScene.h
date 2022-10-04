#ifndef CPLAYSCENE_H
#define CPLAYSCENE_H

#include <QMainWindow>
#include "Include.h"
#include "cmypushbutton.h"

class cPlayScene : public QMainWindow
{
    Q_OBJECT
public:
    cPlayScene(QWidget *parent = nullptr, int level = 0);
private:
    void Init();
    void SetMyMenu();
    void paintEvent(QPaintEvent *event);
private:
    QMenuBar            *m_menuBar;
    QMenu               *m_menu;
    CMyPushbutton       *m_backBtn;
    int m_levelIndex;
signals:
    void Sig_back();
};

#endif // CPLAYSCENE_H
