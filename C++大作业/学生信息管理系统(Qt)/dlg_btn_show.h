#ifndef DLG_BTN_SHOW_H
#define DLG_BTN_SHOW_H

#include <QDialog>

namespace Ui {
class Dlg_Btn_show;
}

class Dlg_Btn_show : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_Btn_show(QWidget *parent = nullptr);
    ~Dlg_Btn_show();

private slots:

    void on_radio_name_clicked();

    void on_radio_ID_clicked();

    void on_radio_rank_clicked();

    void on_radio_up_clicked();

    void on_radio_down_clicked();

private:
    Ui::Dlg_Btn_show *ui;
};

#endif // DLG_BTN_SHOW_H
