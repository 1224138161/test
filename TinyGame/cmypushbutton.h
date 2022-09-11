#ifndef CMYPUSHBUTTON_H
#define CMYPUSHBUTTON_H

#include <QPushButton>
#include <QDebug>
#include <QPropertyAnimation>

class CMyPushbutton : public QPushButton
{
    Q_OBJECT
public:
    CMyPushbutton(QString imagePath, QString pressedImagePath = "");
    CMyPushbutton(QWidget *parent, QString imagePath, QString pressedImagePath = "");
private:
    void Zoom();
private:
    QString m_imagePath;
    QString m_pressedImagePath;
};

#endif // CMYPUSHBUTTON_H
