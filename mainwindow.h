#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QAction>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>
#include <QDateTime>
#include <QUrl>
#include <QDesktopServices>
#include "about.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString saveFileName;
private slots:
    void newFileSlot();
    void openFileSlot();
    void saveFileSlot();
    void printFileSlot();
    void saveAsFileSlot();
    //void exitSlot();
    void setFontSlot();
    void setColorSlot();
    void currentDateTimeSlot();
    void aboutWebsiteSlot();
    void aboutSoftwareSlot();
};

#endif // MAINWINDOW_H
