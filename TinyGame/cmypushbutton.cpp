#include "cmypushbutton.h"

CMyPushbutton::CMyPushbutton(QString imagePath, QString pressedImagePath)
{
    this->m_imagePath = imagePath;
    this->m_pressedImagePath = pressedImagePath;

    QPixmap pix;
    bool ret = pix.load(imagePath);
    if (!ret)
    {
        qDebug() << "load picture failed!";
        return;
    }
    this->setFixedSize(pix.size());
    this->setStyleSheet("QPushButton{border: none;}");
    this->setIcon(pix);
    this->setIconSize(pix.size());
}

CMyPushbutton::CMyPushbutton(QWidget *parent, QString imagePath, QString pressedImagePath)
{
    this->setParent(parent);
    this->m_imagePath = imagePath;
    this->m_pressedImagePath = pressedImagePath;

    QPixmap pix;
    bool ret = pix.load(imagePath);
    if (!ret)
    {
        qDebug() << "load picture failed!";
        return;
    }
    this->setFixedSize(pix.size());
    this->setStyleSheet("QPushButton{border: none;}");
    this->setIcon(pix);
    this->setIconSize(pix.size());
}

void CMyPushbutton::Zoom()
{
    QPropertyAnimation *animation_zoom1 = new QPropertyAnimation(this, "geometry");
    animation_zoom1->setDuration(100);
    animation_zoom1->setStartValue(this->geometry());
    animation_zoom1->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    animation_zoom1->start();

    QPropertyAnimation *animation_zoom2 = new QPropertyAnimation(this, "geometry");
    animation_zoom2->setDuration(100);
    animation_zoom2->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    animation_zoom2->setEndValue(this->geometry());
    animation_zoom2->start();
}

void CMyPushbutton::mousePressEvent(QMouseEvent *e)
{
    if (!m_pressedImagePath.isEmpty())
    {
        QPixmap pix;
        if (!pix.load(m_pressedImagePath))
        {
            qDebug() << "load pressed picture failed!";
            return;
        }
        setIcon(pix);
        setIconSize(pix.size());
    }
    return QPushButton::mousePressEvent(e);
}

void CMyPushbutton::mouseReleaseEvent(QMouseEvent *e)
{
    if (!m_pressedImagePath.isEmpty())
    {
        QPixmap pix;
        if (!pix.load(m_imagePath))
        {
            qDebug() << "load picture failed!";
            return;
        }
        setIcon(pix);
        setIconSize(pix.size());
    }
    return QPushButton::mouseReleaseEvent(e);
}
