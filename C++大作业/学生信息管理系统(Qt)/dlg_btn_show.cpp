#include "dlg_btn_show.h"
#include "ui_dlg_btn_show.h"
#include "dlg1.h"
#include "classes/DataBase.h"
#include<QStandardItemModel>

extern DataBase mydata;//声明全局变量

void filltable(Ui::Dlg_Btn_show* ui,CS_Student*ss,int n);//填充表格
void sort(Ui::Dlg_Btn_show*);

Dlg_Btn_show::Dlg_Btn_show(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_Btn_show)
{
    ui->setupUi(this);

    setFixedSize(this->width(),this->height());//固定窗口大小

    sort(ui);
}

Dlg_Btn_show::~Dlg_Btn_show()
{
    delete ui;
}


void Dlg_Btn_show::on_radio_name_clicked()
{
    sort(ui);
}

void filltable(Ui::Dlg_Btn_show* ui,CS_Student*ss,int n)//填充表格
// n:数组ss[]的元素个数
{
    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(5);
    model->setHeaderData(0,Qt::Horizontal,"姓名");
    model->setHeaderData(1,Qt::Horizontal,"学号");
    model->setHeaderData(2,Qt::Horizontal,"名次");
    model->setHeaderData(3,Qt::Horizontal,"性别");
    model->setHeaderData(4,Qt::Horizontal,"学历");

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);//表头文字居中
    ui->tableView->setColumnWidth(0,100);
    ui->tableView->setColumnWidth(1,200);
    ui->tableView->setColumnWidth(2,100);
    ui->tableView->setColumnWidth(3,100);
    ui->tableView->setColumnWidth(4,115);

    for(int i = 0; i < n; i++)
    {
        model->setItem(i,0,new QStandardItem(ss[i].getname()));
        model->setItem(i,1,new QStandardItem(ss[i].getID()));
        model->setItem(i,2,new QStandardItem(QString::number(ss[i].getrank())));
        model->setItem(i,3,new QStandardItem(ss[i].getgender()));
        model->setItem(i,4,new QStandardItem(ss[i].getEduBkg()));
        for(int j=0;j<5;j++)model->item(i,j)->setTextAlignment(Qt::AlignCenter);//文字居中
    }

}

void sort(Ui::Dlg_Btn_show* ui)
{
    //数据准备
    int n=mydata.gettotal();
    CS_Student *ss=new CS_Student[n];

    for(int i=0;i<n;++i)
    {
        ss[i]=mydata[i];
    }


    //排序
    if(ui->radio_up->isChecked())
    {
        if(ui->radio_name->isChecked())
        {
            //升序
            for(int i=0;i<n-1;++i)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(ss[i].getname()>ss[j].getname())
                    {
                        CS_Student temp=ss[i];
                        ss[i]=ss[j];
                        ss[j]=temp;
                    }
                }
            }
        }
    else if(ui->radio_ID->isChecked())
        {
            //升序
            for(int i=0;i<n-1;++i)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(ss[i].getID()>ss[j].getID())
                    {
                        CS_Student temp=ss[i];
                        ss[i]=ss[j];
                        ss[j]=temp;
                    }
                }
            }
        }
    else
        {
            //升序
            for(int i=0;i<n-1;++i)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(ss[i].getrank()>ss[j].getrank())
                    {
                        CS_Student temp=ss[i];
                        ss[i]=ss[j];
                        ss[j]=temp;
                    }
                }
            }
        }
    }

    else
    {
        if(ui->radio_ID->isChecked())
        {
            //降序
            for(int i=0;i<n-1;++i)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(ss[i].getID()<ss[j].getID())
                    {
                        CS_Student temp=ss[i];
                        ss[i]=ss[j];
                        ss[j]=temp;
                    }
                }
            }
        }

        else if(ui->radio_name->isChecked())
        {
            //降序
            for(int i=0;i<n-1;++i)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(ss[i].getname()<ss[j].getname())
                    {
                        CS_Student temp=ss[i];
                        ss[i]=ss[j];
                        ss[j]=temp;
                    }
                }
            }
        }

        else
        {
            //降序
            for(int i=0;i<n-1;++i)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(ss[i].getrank()<ss[j].getrank())
                    {
                        CS_Student temp=ss[i];
                        ss[i]=ss[j];
                        ss[j]=temp;
                    }
                }
            }
        }
    }

    //显示
    filltable(ui,ss,n);

    delete []ss;
}

void Dlg_Btn_show::on_radio_ID_clicked()
{
    sort(ui);
}


void Dlg_Btn_show::on_radio_rank_clicked()
{
    sort(ui);
}


void Dlg_Btn_show::on_radio_up_clicked()
{
    sort(ui);
}


void Dlg_Btn_show::on_radio_down_clicked()
{
    sort(ui);
}

