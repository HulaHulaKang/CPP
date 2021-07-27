#ifndef DLG_SUCCESS_H
#define DLG_SUCCESS_H

#include <QDialog>

namespace Ui {
class Dlg_Success;
}

class Dlg_Success : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_Success(QWidget *parent = nullptr);
    ~Dlg_Success();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dlg_Success *ui;
};

#endif // DLG_SUCCESS_H
