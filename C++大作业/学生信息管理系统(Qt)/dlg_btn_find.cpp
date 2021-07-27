#include "dlg_btn_find.h"
#include "ui_dlg_btn_find.h"
#include "classes/DataBase.h"
#include <QMessageBox>

#include "dlg_fail.h"
#include "dlg_success.h"

extern DataBase mydata;

Dlg_Btn_find::Dlg_Btn_find(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_Btn_find)
{
    ui->setupUi(this);
    setFixedSize(this->width(),this->height());//固定窗口大小
}

Dlg_Btn_find::~Dlg_Btn_find()
{
    delete ui;
}

void Dlg_Btn_find::on_Btn_find_clicked()
{
    int n=mydata.gettotal();
    int x=-1;//用于记录匹配到的记录的索引

    if(ui->radio_ID->isChecked())
    {
        for(int i=0;i<n;++i)
        {
            if(mydata[i].getID()==ui->lineEdit->text()){x=i;break;}
        }
    }

    else if(ui->radio_name->isChecked())
    {
        for(int i=0;i<n;++i)
        {
            if(mydata[i].getname()==ui->lineEdit->text()){x=i;break;}
        }
    }

    else
    {
        for(int i=0;i<n;++i)
        {
            if(mydata[i].getrank()==ui->lineEdit->text().toInt()){x=i;break;}
        }
    }

    /* **************************************************************** */
    QString text;

    if(x==-1)
    {
        text="未查询到结果";
        QMessageBox::information(this,"查询结果",text,QMessageBox::Ok);
    }

    else
    {
        text="姓名:"+mydata[x].getname()+"\n学号:"+mydata[x].getID()+"\n名次:"+QString::number(mydata[x].getrank())+"\n性别:"+mydata[x].getgender()+"\n学历:"+mydata[x].getEduBkg();

        QPushButton *dbtn=new QPushButton(QObject::tr("删除此条记录"));
        QPushButton *cbtn=new QPushButton(QObject::tr("回到主页"));
        QMessageBox *mymsg=new QMessageBox;
        mymsg->addButton(dbtn,QMessageBox::AcceptRole);//索引为0
        mymsg->addButton(cbtn,QMessageBox::RejectRole);//索引为1
        mymsg->setWindowTitle("查询结果");
        mymsg->setDefaultButton(cbtn);
        mymsg->setText(text);

        int result=mymsg->exec();

        //选择了删除
        if(result==0)
        {
            QMessageBox::warning(mymsg,"删除记录","你确认删除此条记录吗？此操作不可恢复。",QMessageBox::Yes|QMessageBox::No);
            mydata.del(x);
        }


        ui->lineEdit->setText("");
        this->close();
    }

}


void Dlg_Btn_find::on_Btn_cancel_clicked()
{
    ui->lineEdit->setText("");
    this->close();
}

