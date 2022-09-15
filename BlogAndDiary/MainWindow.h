#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>
#include "Include.h"

class cMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    cMainWindow(QWidget *parent = nullptr);
    ~cMainWindow();
    void InitWnd();
    void InitMenu();
};
#endif // CMAINWINDOW_H
