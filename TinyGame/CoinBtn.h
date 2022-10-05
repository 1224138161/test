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
private:
    QString m_imagePath;
};

#endif // CCOINBTN_H
