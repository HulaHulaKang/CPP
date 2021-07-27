#include "dlg_fail.h"
#include "ui_dlg_fail.h"

Dlg_Fail::Dlg_Fail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_Fail)
{
    ui->setupUi(this);
}

Dlg_Fail::~Dlg_Fail()
{
    delete ui;
}

void Dlg_Fail::on_pushButton_clicked()
{
    this->close();
}

