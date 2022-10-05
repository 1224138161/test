#include "DataConfig.h"

cDataConfig::cDataConfig()
{
    int arr1[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 0, 0},
        {1, 1, 0, 1}
    };
    InsertArray(arr1, 1);

    int arr2[4][4] = {
        {1, 0, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 0, 0},
        {1, 1, 0, 1}
    };
    InsertArray(arr2, 2);

    int arr3[4][4] = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };
    InsertArray(arr3, 3);

    int arr4[4][4] = {
        {0, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 0, 1, 1},
        {1, 1, 1, 1}
    };
    InsertArray(arr4, 4);

    int arr5[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 0, 0},
        {1, 1, 0, 1}
    };
    InsertArray(arr5, 5); // none

    int arr6[4][4] = {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {1, 0, 0, 1}
    };
    InsertArray(arr6, 6);

    int arr7[4][4] = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0}
    };
    InsertArray(arr7, 7);

    int arr8[4][4] = {
        {0, 1, 0, 1},
        {1, 0, 0, 0},
        {0, 0, 0, 1},
        {1, 0, 1, 0}
    };
    InsertArray(arr8, 8);

    int arr9[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 0, 0},
        {1, 1, 0, 1}
    };
    InsertArray(arr9, 9); // none

    int arr10[4][4] = {
        {1, 0, 1, 1},
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {1, 1, 0, 1}
    };
    InsertArray(arr10, 10);

    int arr11[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 0, 0},
        {1, 1, 0, 1}
    };
    InsertArray(arr11, 11); // none

    int arr12[4][4] = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };
    InsertArray(arr12, 12);

    int arr13[4][4] = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 1, 0}
    };
    InsertArray(arr13, 13);

    int arr14[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 0, 0},
        {1, 1, 0, 1}
    };
    InsertArray(arr14, 14); // none

    int arr15[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 0, 0},
        {1, 1, 0, 1}
    };
    InsertArray(arr15, 15); // none after

    int arr16[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 0, 0},
        {1, 1, 0, 1}
    };
    InsertArray(arr16, 16);

    int arr17[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 0, 0},
        {1, 1, 0, 1}
    };
    InsertArray(arr17, 17);

    int arr18[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 0, 0},
        {1, 1, 0, 1}
    };
    InsertArray(arr18, 18);

    int arr19[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 0, 0},
        {1, 1, 0, 1}
    };
    InsertArray(arr19, 19);

    int arr20[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 0, 0},
        {1, 1, 0, 1}
    };
    InsertArray(arr20, 20);
}

void cDataConfig::InsertArray(int arr[][4], int pos)
{
    QVector<QVector<int>> array;
    for (int i = 0; i < 4; i++)
    {
        QVector<int> v;
        for (int j = 0; j < 4; j++)
        {
            v.append(arr[i][j]);
        }
        array.append(v);
    }
    m_data.insert(pos, array);
}
