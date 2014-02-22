#ifndef JDIALOG_H
#define JDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QString>

class jdialog : public QDialog
{
    Q_OBJECT
public:
    explicit jdialog(QWidget *parent = 0);
private:
    QGridLayout*        lytdialog_;
    QWidget*            wgtdialog_;
    QPushButton*        btnAceptar_;
    QLabel*             dialogLabel_;

signals:

public slots:

};

#endif // JDIALOG_H
