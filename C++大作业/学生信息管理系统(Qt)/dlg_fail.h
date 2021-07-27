#ifndef DLG_FAIL_H
#define DLG_FAIL_H

#include <QDialog>

namespace Ui {
class Dlg_Fail;
}

class Dlg_Fail : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_Fail(QWidget *parent = nullptr);
    ~Dlg_Fail();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dlg_Fail *ui;
};

#endif // DLG_FAIL_H
