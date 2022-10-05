#include "CoinBtn.h"

cCoinBtn::cCoinBtn(QWidget *parent, QString img)
{
    setParent(parent);

    if (img.isEmpty())
    {
        return;
    }
    m_imagePath = img;

    QPixmap pix;
    bool ret = pix.load(m_imagePath);
    if (!ret)
    {
        qDebug() << "load picture failed!";
        return;
    }
    setFixedSize(pix.size());
    setStyleSheet("QPushButton{border: none;}");
    setIcon(pix);
    setIconSize(pix.size());
}

void cCoinBtn::SetPix(QString img)
{
    m_imagePath = img;

    QPixmap pix;
    bool ret = pix.load(m_imagePath);
    if (!ret)
    {
        qDebug() << "load picture failed!";
        return;
    }
    setFixedSize(pix.size());
    setStyleSheet("QPushButton{border: none;}");
    setIcon(pix);
    setIconSize(pix.size());
}
