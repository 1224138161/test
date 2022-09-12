#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Include.h"
#include "cmypushbutton.h"
#include "cchooselevelscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMenu               *m_menu;

private:
    void setMainWindow();
    void paintEvent(QPaintEvent *event);
    void setMyMenu();
};
#endif // MAINWINDOW_H
