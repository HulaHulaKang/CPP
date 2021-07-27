#ifndef DLG_BTN_FIND_H
#define DLG_BTN_FIND_H

#include <QDialog>

namespace Ui {
class Dlg_Btn_find;
}

class Dlg_Btn_find : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_Btn_find(QWidget *parent = nullptr);
    ~Dlg_Btn_find();

private slots:
    void on_Btn_find_clicked();

    void on_Btn_cancel_clicked();

private:
    Ui::Dlg_Btn_find *ui;
};

#endif // DLG_BTN_FIND_H
