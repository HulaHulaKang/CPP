#pragma once
#ifndef DLG_BTN_WRITE_H
#define DLG_BTN_WRITE_H

#include <QDialog>

namespace Ui {
class Dlg_Btn_write;
}

class Dlg_Btn_write : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_Btn_write(QWidget *parent = nullptr);
    ~Dlg_Btn_write();

private slots:

    void on_radio_default_clicked();

    void on_radio_personal_clicked();

    void on_Btn_cancel_clicked();


    void on_Btn_write_clicked();

private:
    Ui::Dlg_Btn_write *ui;
};

#endif // DLG_BTN_WRITE_H
