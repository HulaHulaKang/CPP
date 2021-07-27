#ifndef DLG_BTN_ADD_H
#define DLG_BTN_ADD_H

#include <QDialog>

namespace Ui {
class Dlg_Btn_add;
}

class Dlg_Btn_add : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_Btn_add(QWidget *parent = nullptr);
    ~Dlg_Btn_add();

private slots:
    void on_Btn_submit_clicked();

private:
    Ui::Dlg_Btn_add *ui;
};

#endif // DLG_BTN_ADD_H
