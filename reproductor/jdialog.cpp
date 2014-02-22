#include "jdialog.h"
#include <QString>

jdialog::jdialog(QWidget *parent) :
    QDialog(parent)
{

    btnAceptar_ = new QPushButton(this);
    dialogLabel_= new QLabel("Acerca De");
    lytdialog_ = new QGridLayout(this);
    setLayout(lytdialog_);
    //setLayout(dialogLabel_);
    lytdialog_->addWidget(btnAceptar_,5,5,5,5);
    lytdialog_->addWidget(dialogLabel_,0,0,0,1);


    connect(btnAceptar_,      SIGNAL(pressed()),               this,         SLOT(close()));
}


