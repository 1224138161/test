#ifndef CCHOOSELEVELSCENE_H
#define CCHOOSELEVELSCENE_H

#include <QMainWindow>
#include <QWidget>
#include "Include.h"
#include "cmypushbutton.h"
#include "PlayScene.h"

class CChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit CChooseLevelScene(QWidget *parent = nullptr);
private:
    void Init();
    void paintEvent(QPaintEvent *event);
    void SetMyMenu();
private:
    QMenuBar            *m_menuBar;
    QMenu               *m_menu;
    CMyPushbutton       *pushbutton_back;
    cPlayScene          *m_playScene;
signals:
    void Sig_back();
};

#endif // CCHOOSELEVELSCENE_H
