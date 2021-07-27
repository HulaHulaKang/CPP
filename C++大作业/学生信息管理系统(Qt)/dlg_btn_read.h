#ifndef DLG_BTN_READ_H
#define DLG_BTN_READ_H

#include <QDialog>

namespace Ui {
class Dlg_Btn_read;
}

class Dlg_Btn_read : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_Btn_read(QWidget *parent = nullptr);
    ~Dlg_Btn_read();

private slots:
    void on_Btn_read_clicked();

private:
    Ui::Dlg_Btn_read *ui;
};

#endif // DLG_BTN_READ_H
