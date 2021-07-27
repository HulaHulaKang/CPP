#pragma once
#ifndef DLG1_H
#define DLG1_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dlg1; }
QT_END_NAMESPACE

class Dlg1 : public QDialog
{
    Q_OBJECT

public:
    Dlg1(QWidget *parent = nullptr);
    ~Dlg1();

private slots:

    void on_Btn_write_clicked();

    void on_Btn_show_clicked();

    void on_Btn_add_clicked();

    void on_Btn_find_clicked();

    void on_Btn_read_clicked();

private:
    Ui::Dlg1 *ui;
};
#endif // DLG1_H
