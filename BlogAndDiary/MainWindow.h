#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>
#include "Include.h"
#include "header/DiaryListWnd.h"
#include "header/DiaryEditor.h"

class cMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    cMainWindow(QWidget *parent = nullptr);
    ~cMainWindow();
private:
    void InitWnd();
    void InitMenu();
    void resizeEvent(QResizeEvent *event);
private:
    QStackedWidget *m_stackedWnd;
    QWidget *m_mainWnd;
    QPushButton *m_blogListBtn;
    QPushButton *m_diaryListBtn;
    cDiaryListWnd *m_diaryListWnd;
    cDiaryEditor *m_diaryEditorWnd;
private slots:
    void On_addDiary();
    void On_back();
};
#endif // CMAINWINDOW_H
