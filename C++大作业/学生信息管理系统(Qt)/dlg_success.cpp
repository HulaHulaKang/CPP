#include "dlg_success.h"
#include "ui_dlg_success.h"

Dlg_Success::Dlg_Success(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_Success)
{
    ui->setupUi(this);
    setFixedSize(this->width(),this->height());//固定窗口大小
}

Dlg_Success::~Dlg_Success()
{
    delete ui;
}

void Dlg_Success::on_pushButton_clicked()
{
    this->close();
}

