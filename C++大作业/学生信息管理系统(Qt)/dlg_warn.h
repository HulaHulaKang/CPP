#ifndef DLG_WARN_H
#define DLG_WARN_H

#include <QDialog>

namespace Ui {
class Dlg_Warn;
}

class Dlg_Warn : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_Warn(QWidget *parent = nullptr);
    ~Dlg_Warn();

private slots:
    void on_Btn_cancel_clicked();

private:
    Ui::Dlg_Warn *ui;
};

#endif // DLG_WARN_H
