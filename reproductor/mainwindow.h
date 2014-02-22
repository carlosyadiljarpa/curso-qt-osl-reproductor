#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDir>
#include <QSlider>
#include <QFileDialog>
#include <QToolButton>
#include <QMenuBar>
#include <QMenu>
#include "metadatadialog.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    QGridLayout*        lytMain_; //declarar widget
    QWidget*            wgtMain_; //declarar widget
    QMediaPlayer*       mediaPlayer_; //declarar widget
    QSlider*            playerSlider_; //declarar widget
    QVideoWidget*       videoWidget_; //declarar widget
    QSlider*            volumeSlider_; //declarar widget
    QToolButton*        btnOpen_; //declarar widget
    QToolButton*        btnPlay_; //declarar widget
    QToolButton*        btnPause_; //declarar widget
    QToolButton*        btnStop_; //declarar widget
    QMenuBar*           mainMenu_;
    QMenu*              mnuArchivo_;
    QMenu*              mnuAyuda_;
    QMenu*              mnuVer_;
    QAction*            actArchivoAbrir_;
    QAction*            actAyuda_;
    QAction*            actmetadata_;


private slots:
    void onOpen();
    void onSeek();
    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);
    void onVolumeChanged(int volume);
    void acercaDe();
    void ver();

};

#endif // MAINWINDOW_H
