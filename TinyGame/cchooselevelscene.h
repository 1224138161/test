#ifndef CCHOOSELEVELSCENE_H
#define CCHOOSELEVELSCENE_H

#include <QMainWindow>
#include <QWidget>
#include "Include.h"
#include "cmypushbutton.h"

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
signals:

};

#endif // CCHOOSELEVELSCENE_H
