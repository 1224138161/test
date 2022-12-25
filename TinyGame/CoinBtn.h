#ifndef CCOINBTN_H
#define CCOINBTN_H

#include <QPushButton>
#include "Include.h"

class cCoinBtn : public QPushButton
{
    Q_OBJECT
public:
    cCoinBtn(QWidget *parent = nullptr, QString img = "");
    void SetPix(QString img);
    void ChangeFlag();
    void mousePressEvent(QMouseEvent *e);
private:
    QString m_imagePath;
public:
    // 金币的属性
    int m_posX;
    int m_posY;
    bool m_flag;
    // 改变 flag 的方法
    QTimer* m_timer1;
    QTimer* m_timer2;
    int m_min = 1;
    int m_max = 8;
};

#endif // CCOINBTN_H
