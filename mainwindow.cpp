#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Untitled");
    QObject::connect(ui->actionNew,SIGNAL(triggered()),this,SLOT(newFileSlot()));
    QObject::connect(ui->actionOpen_N,SIGNAL(triggered()),this,SLOT(openFileSlot()));
    QObject::connect(ui->actionSave_S,SIGNAL(triggered()),this,SLOT(saveFileSlot()));
    QObject::connect(ui->actionLingcuwei,SIGNAL(triggered()),this,SLOT(saveAsFileSlot()));
    QObject::connect(ui->actionQuit_Q,SIGNAL(triggered()),this,SLOT(close()));
    /////////////////////////////////
    QObject::connect(ui->undoAction,SIGNAL(triggered()),ui->textEdit,SLOT(undo()));
    QObject::connect(ui->redoAction,SIGNAL(triggered()),ui->textEdit,SLOT(redo()));
    QObject::connect(ui->copyAction,SIGNAL(triggered()),ui->textEdit,SLOT(copy()));
    QObject::connect(ui->pasteAction,SIGNAL(triggered()),ui->textEdit,SLOT(paste()));
    QObject::connect(ui->cutAction,SIGNAL(triggered()),ui->textEdit,SLOT(cut()));
    QObject::connect(ui->selectAllAction,SIGNAL(triggered()),ui->textEdit,SLOT(selectAll()));
    QObject::connect(ui->datetimeAction,SIGNAL(triggered()),this,SLOT(currentDateTimeSlot()));
    //////////////////////////////////
    QObject::connect(ui->actionFont,SIGNAL(triggered()),this,SLOT(setFontSlot()));
    QObject::connect(ui->actionColor,SIGNAL(triggered()),this,SLOT(setColorSlot()));
    QObject::connect(ui->actionAbout_Qt,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
    QObject::connect(ui->actionWebsite,SIGNAL(triggered()),this,SLOT(aboutWebsiteSlot()));
    QObject::connect(ui->actionAbout,SIGNAL(triggered()),this,SLOT(aboutSoftwareSlot()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFileSlot()
{
    if(ui->textEdit->document()->isModified())
    {
        qDebug()<<"current file modified";
    }
    else
    {
        qDebug()<<"not modified";
        ui->textEdit->clear();
        this->setWindowTitle("Untitled.txt----------");
    }

}

void MainWindow::openFileSlot()
{
    //open file
    QString filename = QFileDialog::getOpenFileName(this,"Open file",QDir::currentPath());
    qDebug()<<"File open"<<filename;
    if(filename.isEmpty())
    {
        QMessageBox::information(this,"Error Message","Please Select a Text File");
        return ;
    }
    QFile *file=new QFile;
    file->setFileName(filename);
    bool ok=file->open(QIODevice::ReadOnly);
    if(ok)
    {
        QTextStream in(file);
        ui->textEdit->setText(in.readAll());
        file->close();
        delete file;
    }
    else
    {
        QMessageBox::information(this,"Error Message","open File failed"+file->errorString());
        return ;
    }
}

void MainWindow::saveFileSlot()
{
    if(saveFileName.isEmpty())
    {
        saveAsFileSlot();
    }
    else
    {
        QFile *file=new QFile;
        file->setFileName(saveFileName);
        bool ok=file->open(QIODevice::WriteOnly);
        if(ok)
        {
            QTextStream out(file);
            out<<ui->textEdit->toPlainText();//将textedit中的纯文本取出重定向到out文件流
            file->close();
            delete file;
        }
    }
}

void MainWindow::saveAsFileSlot()
{
    QString saveFileName=QFileDialog::getSaveFileName(this,"save file",QDir::currentPath());
    if(saveFileName.isEmpty())
    {
        QMessageBox::information(this,"Error Message","Please input filename");
        return ;
    }
    QFile *file=new QFile;
    file->setFileName(saveFileName);
    bool ok=file->open(QIODevice::WriteOnly);
    if(ok)
    {
        QTextStream out(file);
        out<<ui->textEdit->toPlainText();//将textedit中的纯文本取出重定向到out文件流
        file->close();
        delete file;
    }
    else
    {
        QMessageBox::information(this,"error","save file failed"+file->errorString());
    }
}

void MainWindow::printFileSlot()
{
    //
}

void MainWindow::setFontSlot()
{
    /*
      bool ok;
QFont font = QFontDialog::getFont(
                &ok, QFont("Helvetica [Cronyx]", 10), this);
if (ok) {
    // the user clicked OK and font is set to the font the user selected
} else {
    // the user canceled the dialog; font is set to the initial
    // value, in this case Helvetica [Cronyx], 10
}
     */
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if(ok)
    {
        ui->textEdit->setFont(font);
    }
    else
    {
        QMessageBox::information(this,"error message","font error");
    }

}

void MainWindow::setColorSlot()
{
    /*
      const QColorDialog::ColorDialogOptions options = QFlag(colorDialogOptionsWidget->value());
    const QColor color = QColorDialog::getColor(Qt::green, this, "Select Color", options);

    if (color.isValid()) {
        colorLabel->setText(color.name());
        colorLabel->setPalette(QPalette(color));
        colorLabel->setAutoFillBackground(true);
    }
     */
    QColor color =QColorDialog::getColor(Qt::red,this);
    if(color.isValid())
    {
        ui->textEdit->setTextColor(color);
    }
    else
    {
        QMessageBox::information(this,"error message","color error");
        return ;
    }
}

void MainWindow::currentDateTimeSlot()
{
    QDateTime current=QDateTime::currentDateTime();
    QString time=current.toString("yyyy-M-dd hh:mm:ss");
    ui->textEdit->append(time);

}

void MainWindow::aboutWebsiteSlot()
{
    QDesktopServices::openUrl(QUrl("https://github.com/wailaixing"));
}

void MainWindow::aboutSoftwareSlot()
{
    about *dialog=new about;
    dialog->show();
}
