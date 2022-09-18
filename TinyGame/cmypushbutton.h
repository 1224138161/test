#ifndef CMYPUSHBUTTON_H
#define CMYPUSHBUTTON_H

#include <QPushButton>
#include "Include.h"

class CMyPushbutton : public QPushButton
{
    Q_OBJECT
public:
    CMyPushbutton(QString imagePath, QString pressedImagePath = "");
    CMyPushbutton(QWidget *parent, QString imagePath, QString pressedImagePath = "");
    void Zoom();
private:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private:
    QString m_imagePath;
    QString m_pressedImagePath;
};

#endif // CMYPUSHBUTTON_H
