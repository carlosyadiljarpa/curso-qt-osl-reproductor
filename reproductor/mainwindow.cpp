#include "mainwindow.h"
#include "jdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //Create central widget and set main layout
    wgtMain_ = new QWidget(this);
    lytMain_ = new QGridLayout(wgtMain_);
    wgtMain_->setLayout(lytMain_);
    setCentralWidget(wgtMain_);

    //Initialize widgets
    mediaPlayer_  = new QMediaPlayer(this);//crear e inicializar widget
    playerSlider_ = new QSlider(Qt::Horizontal, this);//crear e inicializar widget
    videoWidget_  = new QVideoWidget(this);//crear e inicializar widget
    volumeSlider_ = new QSlider(Qt::Horizontal, this);//crear e inicializar widget
    btnOpen_      = new QToolButton(this);//crear e inicializar widget
    btnPlay_      = new QToolButton(this);//crear e inicializar widget
    btnPause_     = new QToolButton(this);//crear e inicializar widget
    btnStop_      = new QToolButton(this);//crear e inicializar widget

    //menu bar
    mainMenu_ = new QMenuBar(this);
    //menu archivo al menu bar
    mnuArchivo_ = new QMenu(tr("&Archivo"),this);
    mainMenu_->addMenu(mnuArchivo_);
    setMenuBar(mainMenu_);
    //menu abrir al menu archivo del menu bar
    actArchivoAbrir_ = new QAction (tr("&Abrir"),this);
    actArchivoAbrir_->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_O));
    mnuArchivo_->addAction(actArchivoAbrir_);

    //menu ayuda al menu bar
    mnuAyuda_ = new QMenu(tr("A&yuda"),this);
    mainMenu_->addMenu(mnuAyuda_);
    setMenuBar(mainMenu_);
    //menu ayuda al menu anyuda del menu bar
    actAyuda_ = new QAction (tr("&Acerca de"),this);
    actAyuda_->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_H));
    mnuAyuda_->addAction(actAyuda_);


    //menu ver al menu bar
    mnuVer_ = new QMenu(tr("&Ver"),this);
    mainMenu_->addMenu(mnuVer_);
    setMenuBar(mainMenu_);
    //menu ayuda al menu anyuda del menu bar
    actmetadata_ = new QAction (tr("&Metadata"),this);
    actmetadata_->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_H));
    mnuVer_->addAction(actmetadata_);



    //Setup widwgets
    videoWidget_->setMinimumSize(400, 400);//inicializar widget
    mediaPlayer_->setVideoOutput(videoWidget_);//inicializar widget
    mediaPlayer_->setVolume(100);//inicializar widget
    videoWidget_->setAspectRatioMode(Qt::KeepAspectRatio);//inicializar widget
    volumeSlider_->setRange(0, 100);//inicializar widget
    volumeSlider_->setSliderPosition(100);//inicializar widget

    //Populate grid layout
    lytMain_->addWidget(videoWidget_,  0, 0, 1, 5);//colocar los widget
    lytMain_->addWidget(playerSlider_, 1, 0, 1, 5);//colocar los widget
    lytMain_->addWidget(btnOpen_,      2, 0, 1, 1);//colocar los widget
    lytMain_->addWidget(btnPlay_,      2, 1, 1, 1);//colocar los widget
    lytMain_->addWidget(btnPause_,     2, 2, 1, 1);//colocar los widget
    lytMain_->addWidget(btnStop_,      2, 3, 1, 1);//colocar los widget
    lytMain_->addWidget(volumeSlider_, 2, 4, 1, 1);//colocar los widget

    //Buttons icons
    btnOpen_->setIcon(QIcon(QPixmap(":/icons/resources/eject.png")));//agrega iconos a los botones
    btnPause_->setIcon(QIcon(QPixmap(":/icons/resources/pause.png")));//agrega iconos a los botones
    btnPlay_->setIcon(QIcon(QPixmap(":/icons/resources/play.png")));//agrega iconos a los botones
    btnStop_->setIcon(QIcon(QPixmap(":/icons/resources/stop.png")));//agrega iconos a los botones

    //Connections/conexiones
    connect(btnOpen_,      SIGNAL(pressed()),               this,         SLOT(onOpen()));
    connect(btnPlay_,      SIGNAL(pressed()),               mediaPlayer_, SLOT(play()));
    connect(btnPause_,     SIGNAL(pressed()),               mediaPlayer_, SLOT(pause()));
    connect(btnStop_,      SIGNAL(pressed()),               mediaPlayer_, SLOT(stop()));
    connect(playerSlider_, SIGNAL(sliderReleased()),        this,         SLOT(onSeek()));
    connect(mediaPlayer_,  SIGNAL(durationChanged(qint64)), this,         SLOT(onDurationChanged(qint64)));
    connect(mediaPlayer_,  SIGNAL(positionChanged(qint64)), this,         SLOT(onPositionChanged(qint64)));
    connect(volumeSlider_, SIGNAL(sliderMoved(int)),        this,         SLOT(onVolumeChanged(int)));
    connect(actArchivoAbrir_, SIGNAL(triggered()), this, SLOT(onOpen()));
    connect(actAyuda_, SIGNAL(triggered()), this, SLOT(acercaDe()));
    connect(actmetadata_, SIGNAL(triggered()), this, SLOT(ver()));

}

MainWindow::~MainWindow()
{

}

void MainWindow::onOpen()
{
    //Show file open dialog
    mediaPlayer_->setMedia(QUrl("http://208.92.53.87:80/MAXIMAFM"));
//    QString fileName = QFileDialog::getOpenFileName(this,
//                                            tr("Abrir archivo"));
//    if (fileName != "") {
//        mediaPlayer_->setMedia(QUrl::fromLocalFile(fileName));
//    }
}

void MainWindow::onSeek()
{
    mediaPlayer_->setPosition(playerSlider_->sliderPosition());
}

void MainWindow::onDurationChanged(qint64 duration)
{
    playerSlider_->setRange(0, duration);
}

void MainWindow::onPositionChanged(qint64 position)
{
    playerSlider_->setSliderPosition(position);
}

void MainWindow::onVolumeChanged(int volume)
{
    mediaPlayer_->setVolume(volume);
}

void MainWindow::acercaDe()
{
    jdialog* ventana =new jdialog(this);
    ventana->exec();

}

void MainWindow::ver()
{
    MetadataDialog md(mediaPlayer_);
    md.exec();
}
