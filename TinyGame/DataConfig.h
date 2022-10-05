#ifndef CDATACONFIG_H
#define CDATACONFIG_H

#include "Include.h"

class cDataConfig
{
public:
    cDataConfig();
public:
    QMap<int, QVector<QVector<int>>> m_data;
private:
    void InsertArray(int arr[][4], int pos);
};

#endif // CDATACONFIG_H
