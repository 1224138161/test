#include "CoinBtn.h"

cCoinBtn::cCoinBtn(QWidget *parent, QString img)
{
    setParent(parent);

    if (!img.isEmpty())
    {
        SetPix(img);
    }

    m_timer1 = new QTimer(this);
    connect(m_timer1, &QTimer::timeout, this, [=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(m_min++);
        pix.load(str);

        setFixedSize(pix.size());
        setStyleSheet("QPushButton{border: none;}");
        setIcon(pix);
        setIconSize(pix.size());
        if (m_min > m_max)
        {
            m_min = 1;
            m_timer1->stop();
        }
    });

    m_timer2 = new QTimer(this);
    connect(m_timer2, &QTimer::timeout, this, [=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(m_max--);
        pix.load(str);

        setFixedSize(pix.size());
        setStyleSheet("QPushButton{border: none;}");
        setIcon(pix);
        setIconSize(pix.size());
        if (m_min > m_max)
        {
            m_max = 8;
            m_timer2->stop();
        }
    });
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

void cCoinBtn::ChangeFlag()
{
    if (m_flag)
    {
        m_timer1->start(30);
        m_flag = false;
    }
    else
    {
        m_timer2->start(30);
        m_flag = true;
    }
}

void cCoinBtn::mousePressEvent(QMouseEvent *e)
{
    if (m_timer1->isActive() || m_timer2->isActive())
    {
        return;
    }
    return QPushButton::mousePressEvent(e);
}
