#include "dlg_warn.h"
#include "ui_dlg_warn.h"

Dlg_Warn::Dlg_Warn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_Warn)
{
    ui->setupUi(this);
}

Dlg_Warn::~Dlg_Warn()
{
    delete ui;
}

void Dlg_Warn::on_Btn_cancel_clicked()
{
    this->close();
}

