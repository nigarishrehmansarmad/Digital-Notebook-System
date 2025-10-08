#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include<string>
#include<fstream>
#include <QMessageBox>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Pai_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_DS_clicked(){
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_discrete_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_mm_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);
}


void MainWindow::on_prob_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);

}


void MainWindow::on_add_ds_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}


void MainWindow::on_save_ds_clicked()
{
    string get_lec,get_date,get_topic;
    get_date= ui->date_ds->text().toStdString();
    get_topic=ui->topic_ds->text().toStdString();
    get_lec = ui->ds_lec->toPlainText().toStdString();
    ofstream out("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/ds.txt",ios::app);

    out<<get_date<<"\t"<<get_topic<<"\t"<<get_lec<< "\n";

    out.close();

}


void MainWindow::on_view_ds_clicked()
{
    ifstream in("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/ds.txt");
    string line;
    while(getline(in,line)){
        size_t pos = line.find("\t");
        size_t pos1 = line.find("\t", pos+1);
        size_t pos2 = line.find("\t", pos1+1);
        QString topic = QString::fromStdString(line.substr(pos+1,pos1-pos-1));
        QString date = QString::fromStdString(line.substr(0,pos));
        QString lecture = QString::fromStdString(line.substr(pos1+1,pos2-pos1-1));
        ui->ds_lec_view->insertPlainText("Date: "+date+"\t\t"+"Topic: " + topic+"\n"+"Lecture"+"\n"+lecture+"\n\n");
    }
    in.close();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_search_ds_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_manifying_glass_clicked()
{
    ifstream in("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/ds.txt");
    string line;
    QString ftopic = ui->search_topic_ds->text();
    while(getline(in,line)){
        size_t pos = line.find("\t");
        size_t pos1 = line.find("\t", pos+1);
        size_t pos2 = line.find("\t", pos1+1);
        QString topic = QString::fromStdString(line.substr(pos+1,pos1-pos-1));
        if(topic==ftopic){
            QString date = QString::fromStdString(line.substr(0,pos));
            QString lecture = QString::fromStdString(line.substr(pos1+1,pos2-pos1-1));
            ui->view_searched->insertPlainText("Date: "+date+"\t\t"+"Topic: " + topic+"\n"+"Lecture"+"\n"+lecture);
        }

    }
    in.close();
}


void MainWindow::on_edit_ds_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_save_ds_edit_clicked()
{
    ofstream out("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/temp.txt");
    string filename = "C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/ds.txt";
    ifstream in(filename);
    string line;
    QString ftopic = ui->search_topic_ds->text();
    while(getline(in,line)){
        size_t pos = line.find("\t");
        size_t pos1 = line.find("\t", pos+1);
        size_t pos2 = line.find("\t", pos1+1);
        QString topic = QString::fromStdString(line.substr(pos+1,pos1-pos-1));
        if(topic==ftopic){
            string get_lec,get_date,get_topic;
            get_date= ui->edit_date->text().toStdString();
            get_topic=ui->edit_topic->text().toStdString();
            get_lec = ui->edit_lec->toPlainText().toStdString();
            out << get_date << "\t" << get_topic << "\t" << get_lec << "\n";
            continue;
        }
        out << line;
    }
    out.close();
    in.close();
    remove(filename.c_str());
    rename("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/temp.txt", filename.c_str());
    return;
}

void MainWindow::on_discrete_save_clicked()
{
    string get_lec,get_date,get_topic;
    get_date= ui->date_discrete->text().toStdString();
    get_topic=ui->topic_discrete->text().toStdString();
    get_lec = ui->discrete_lec->toPlainText().toStdString();
    ofstream out("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/discrete.txt",ios::app);

    out<<get_date<<"\t"<<get_topic<<"\t"<<get_lec<< "\n";

    out.close();
}

void MainWindow::on_add_discrete_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);

}

void MainWindow::on_back_ds_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_back_discrete_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_edit_discrete_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_ds_search_edit_clicked()
{
    string filename = "C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/ds.txt";
    ifstream in(filename);
    string line;
    QString ftopic = ui->ds_search_edit_topic->text();
    while(getline(in,line)){
        size_t pos = line.find("\t");
        size_t pos1 = line.find("\t", pos+1);
        size_t pos2 = line.find("\n", pos1+1);
        QString topic = QString::fromStdString(line.substr(pos+1,pos1-pos-1));
        if(topic==ftopic){

            QString date = QString::fromStdString(line.substr(0,pos));
            QString lecture = QString::fromStdString(line.substr(pos1+1,pos2-pos1-1));
            ui->edit_date->setText(date);
            ui->edit_topic->setText(topic);
            ui->edit_lec->insertPlainText(lecture);

            break;
        }

    }
    in.close();
    return;

}


void MainWindow::on_ds_edit_save_clicked()
{
    ofstream out("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/temp.txt");
    string filename = "C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/ds.txt";
    ifstream in(filename);
    string line;
    QString ftopic = ui->ds_search_edit_topic->text();
    while(getline(in,line)){
        size_t pos = line.find("\t");
        size_t pos1 = line.find("\t", pos+1);
        //size_t pos2 = line.find("\t", pos1+1);
        QString topic = QString::fromStdString(line.substr(pos+1,pos1-pos-1));
        qDebug() << "he";
        if(topic==ftopic){

            string get_lec,get_date,get_topic;
            get_date= ui->edit_date->text().toStdString();
            get_topic=ui->edit_topic->text().toStdString();
            get_lec = ui->edit_lec->toPlainText().toStdString();
            out << get_date << "\t" << get_topic << "\t" << get_lec << "\n";
            continue;
        }
        out << line << "\n";
    }
    out.close();
    in.close();
    remove(filename.c_str());
    rename("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/temp.txt", filename.c_str());
    return;

}

void MainWindow::on_back_prob_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_back_add_discrete_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_back_search_discrete_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_back_view_discrete_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_back_add_ds_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_back_edit_ds_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_back_add_mm_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);
}


void MainWindow::on_back_edit_mm_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);
}


void MainWindow::on_back_search_mm_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);
}


void MainWindow::on_back_view_mm_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);
}


void MainWindow::on_back_add_pai_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_back_edit_pai_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_back_search_pai_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_back_add_prob_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}


void MainWindow::on_back_edit_prob_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}


void MainWindow::on_back_search_prob_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}


void MainWindow::on_back_view_prob_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}


void MainWindow::on_back_mm_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_view_mm_clicked()
{
    ifstream in("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/mm.txt");
    string line;
    while(getline(in,line)){
        size_t pos = line.find("\t");
        size_t pos1 = line.find("\t", pos+1);
        size_t pos2 = line.find("\t", pos1+1);
        QString topic = QString::fromStdString(line.substr(pos+1,pos1-pos-1));
        QString date = QString::fromStdString(line.substr(0,pos));
        QString lecture = QString::fromStdString(line.substr(pos1+1,pos2-pos1-1));
        ui->view_lec_mm->insertPlainText("Date: "+date+"\t\t"+"Topic: " + topic+"\n"+"Lecture"+"\n"+lecture+"\n\n");
    }
    in.close();

    ui->stackedWidget->setCurrentIndex(24);
}


void MainWindow::on_edit_mm_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);
}


void MainWindow::on_search_mm_clicked()
{
    ui->stackedWidget->setCurrentIndex(25);
}


void MainWindow::on_add_pai_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}


void MainWindow::on_view_pai_clicked()
{
    ifstream in("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/pai.txt");
    string line;
    while(getline(in,line)){
        size_t pos = line.find("\t");
        size_t pos1 = line.find("\t", pos+1);
        size_t pos2 = line.find("\t", pos1+1);
        QString topic = QString::fromStdString(line.substr(pos+1,pos1-pos-1));
        QString date = QString::fromStdString(line.substr(0,pos));
        QString lecture = QString::fromStdString(line.substr(pos1+1,pos2-pos1-1));
        ui->view_lec_pai->insertPlainText("Date: "+date+"\t\t"+"Topic: " + topic+"\n"+"Lecture"+"\n"+lecture+"\n\n");
    }
    in.close();
    ui->stackedWidget->setCurrentIndex(15);
}


void MainWindow::on_edit_pai_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}


void MainWindow::on_search_pai_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}


void MainWindow::on_add_prob_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}


void MainWindow::on_view_prob_clicked()
{
    ifstream in("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/prob.txt");
    string line;
    while(getline(in,line)){
        size_t pos = line.find("\t");
        size_t pos1 = line.find("\t", pos+1);
        size_t pos2 = line.find("\t", pos1+1);
        QString topic = QString::fromStdString(line.substr(pos+1,pos1-pos-1));
        QString date = QString::fromStdString(line.substr(0,pos));
        QString lecture = QString::fromStdString(line.substr(pos1+1,pos2-pos1-1));
        ui->view_lec_prob->insertPlainText("Date: "+date+"\t\t"+"Topic: " + topic+"\n"+"Lecture"+"\n"+lecture+"\n\n");
    }
    in.close();

    ui->stackedWidget->setCurrentIndex(19);
}


void MainWindow::on_edit_prob_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
}


void MainWindow::on_search_prob_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_back_search_ds_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::on_back_edit_discrete_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_view_discrete_clicked()
{
    ifstream in("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/discrete.txt");
    string line;
    while(getline(in,line)){
        size_t pos = line.find("\t");
        size_t pos1 = line.find("\t", pos+1);
        size_t pos2 = line.find("\t", pos1+1);
        QString topic = QString::fromStdString(line.substr(pos+1,pos1-pos-1));
        QString date = QString::fromStdString(line.substr(0,pos));
        QString lecture = QString::fromStdString(line.substr(pos1+1,pos2-pos1-1));
        ui->view_lec_discrete->insertPlainText("Date: "+date+"\t\t"+"Topic: " + topic+"\n"+"Lecture"+"\n"+lecture+"\n\n");
    }
    in.close();

    ui->stackedWidget->setCurrentIndex(10);
}


void MainWindow::on_search_discrete_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}


void MainWindow::on_magnifying_glass_clicked()
{
    ifstream in("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/discrete.txt");
    string line;
    QString ftopic = ui->search_topic_discrete->text();
    while(getline(in,line)){
        size_t pos = line.find("\t");
        size_t pos1 = line.find("\t", pos+1);
        size_t pos2 = line.find("\t", pos1+1);
        QString topic = QString::fromStdString(line.substr(pos+1,pos1-pos-1));
        if(topic==ftopic){
            QString date = QString::fromStdString(line.substr(0,pos));
            QString lecture = QString::fromStdString(line.substr(pos1+1,pos2-pos1-1));
            ui->view_searched_discrete->insertPlainText("Date: "+date+"\t\t"+"Topic: " + topic+"\n"+"Lecture"+"\n"+lecture);
        }

    }
    in.close();
    ui->stackedWidget->setCurrentIndex(9);
}


void MainWindow::on_back_view_ds_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_back_view_pai_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_discrete_edit_save_clicked()
{
    ofstream out("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/temp.txt");
    string filename = "C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/discrete.txt";
    ifstream in(filename);
    string line;
    QString ftopic = ui->discrete_search_topic->text();
    while(getline(in,line)){
        size_t pos = line.find("\t");
        size_t pos1 = line.find("\t", pos+1);
        //size_t pos2 = line.find("\t", pos1+1);
        QString topic = QString::fromStdString(line.substr(pos+1,pos1-pos-1));
        qDebug() << "he";
        if(topic==ftopic){

            string get_lec,get_date,get_topic;
            get_date= ui->edit_date->text().toStdString();
            get_topic=ui->edit_topic->text().toStdString();
            get_lec = ui->edit_lec->toPlainText().toStdString();
            out << get_date << "\t" << get_topic << "\t" << get_lec << "\n";
            continue;
        }
        out << line << "\n";
    }
    out.close();
    in.close();
    remove(filename.c_str());
    rename("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/temp.txt", filename.c_str());
    return;

}


void MainWindow::on_save_add_pai_clicked()
{
    string get_lec,get_date,get_topic;
    get_date= ui->date_pai->text().toStdString();
    get_topic=ui->topic_pai->text().toStdString();
    get_lec = ui->lec_pai->toPlainText().toStdString();
    ofstream out("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/pai.txt",ios::app);

    out<<get_date<<"\t"<<get_topic<<"\t"<<get_lec<< "\n";

    out.close();
}


void MainWindow::on_back_pai_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_add_save_mm_clicked()
{
    string get_lec,get_date,get_topic;
    get_date= ui->date_mm->text().toStdString();
    get_topic=ui->topic_mm->text().toStdString();
    get_lec = ui->lec_mm->toPlainText().toStdString();
    ofstream out("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/mm.txt",ios::app);

    out<<get_date<<"\t"<<get_topic<<"\t"<<get_lec<< "\n";

    out.close();
}


void MainWindow::on_add_mm_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);
}


void MainWindow::on_edit_search_topic_mm_clicked()
{
    string filename = "C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/mm.txt";
    ifstream in(filename);
    string line;
    QString ftopic = ui->searching_topic_mm->text();
    while(getline(in,line)){
        size_t pos = line.find("\t");
        size_t pos1 = line.find("\t", pos+1);
        size_t pos2 = line.find("\n", pos1+1);
        QString topic = QString::fromStdString(line.substr(pos+1,pos1-pos-1));
        if(topic==ftopic){

            QString date = QString::fromStdString(line.substr(0,pos));
            QString lecture = QString::fromStdString(line.substr(pos1+1,pos2-pos1-1));
            ui->edit_date_mm->setText(date);
            ui->edit_topic_mm->setText(topic);
            ui->edit_lec_mm->insertPlainText(lecture);

            break;
        }

    }
    in.close();
    return;
}


void MainWindow::on_save_edit_mm_clicked()
{
    ofstream out("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/temp.txt");
    string filename = "C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/mm.txt";
    ifstream in(filename);
    string line;
    QString ftopic = ui->searching_topic_mm->text();
    while(getline(in,line)){
        size_t pos = line.find("\t");
        size_t pos1 = line.find("\t", pos+1);
        //size_t pos2 = line.find("\t", pos1+1);
        QString topic = QString::fromStdString(line.substr(pos+1,pos1-pos-1));
        qDebug() << "he";
        if(topic==ftopic){

            string get_lec,get_date,get_topic;
            get_date= ui->edit_date_mm->text().toStdString();
            get_topic=ui->edit_topic_mm->text().toStdString();
            get_lec = ui->edit_lec_mm->toPlainText().toStdString();
            out << get_date << "\t" << get_topic << "\t" << get_lec << "\n";
            continue;
        }
        out << line << "\n";
    }
    out.close();
    in.close();
    remove(filename.c_str());
    rename("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/temp.txt", filename.c_str());
    return;
}


void MainWindow::on_save_add_prob_clicked()
{
    string get_lec,get_date,get_topic;
    get_date= ui->date_prob->text().toStdString();
    get_topic=ui->topic_prob->text().toStdString();
    get_lec = ui->lec_prob->toPlainText().toStdString();
    ofstream out("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/prob.txt",ios::app);

    out<<get_date<<"\t"<<get_topic<<"\t"<<get_lec<< "\n";

    out.close();
}


void MainWindow::on_save_edit_pai_clicked()
{
    ofstream out("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/temp.txt");
    string filename = "C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/pai.txt";
    ifstream in(filename);
    string line;
    QString ftopic = ui->search_edit_topic_pai->text();
    while(getline(in,line)){
        size_t pos = line.find("\t");
        size_t pos1 = line.find("\t", pos+1);
        //size_t pos2 = line.find("\t", pos1+1);
        QString topic = QString::fromStdString(line.substr(pos+1,pos1-pos-1));
        qDebug() << "he";
        if(topic==ftopic){

            string get_lec,get_date,get_topic;
            get_date= ui->edit_date_pai->text().toStdString();
            get_topic=ui->edit_topic_pai->text().toStdString();
            get_lec = ui->edit_lec_pai->toPlainText().toStdString();
            out << get_date << "\t" << get_topic << "\t" << get_lec << "\n";
            continue;
        }
        out << line << "\n";
    }
    out.close();
    in.close();
    remove(filename.c_str());
    rename("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/temp.txt", filename.c_str());
    return;
}


void MainWindow::on_edit_search_prob_clicked()
{
    string filename = "C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/prob.txt";
    ifstream in(filename);
    string line;
    QString ftopic = ui->search_edit_topic_prob->text();
    while(getline(in,line)){
        size_t pos = line.find("\t");
        size_t pos1 = line.find("\t", pos+1);
        size_t pos2 = line.find("\n", pos1+1);
        QString topic = QString::fromStdString(line.substr(pos+1,pos1-pos-1));
        if(topic==ftopic){

            QString date = QString::fromStdString(line.substr(0,pos));
            QString lecture = QString::fromStdString(line.substr(pos1+1,pos2-pos1-1));
            ui->edit_date_prob->setText(date);
            ui->edit_topic_prob->setText(topic);
            ui->edit_lec_prob->insertPlainText(lecture);

            break;
        }

    }

    in.close();
    return;
}


void MainWindow::on_magnifying_glass_pai_clicked()
{
    ifstream in("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/pai.txt");
    string line;
    QString ftopic = ui->search_topic_pai->text();
    while(getline(in,line)){
        size_t pos = line.find("\t");
        size_t pos1 = line.find("\t", pos+1);
        size_t pos2 = line.find("\t", pos1+1);
        QString topic = QString::fromStdString(line.substr(pos+1,pos1-pos-1));
        if(topic==ftopic){
            QString date = QString::fromStdString(line.substr(0,pos));
            QString lecture = QString::fromStdString(line.substr(pos1+1,pos2-pos1-1));
            ui->view_searched_pai->insertPlainText("Date: "+date+"\t\t"+"Topic: " + topic+"\n"+"Lecture"+"\n"+lecture);
        }

    }
    in.close();
    ui->stackedWidget->setCurrentIndex(14);
}


void MainWindow::on_magnifying_glass_prob_clicked()
{
    ifstream in("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/prob.txt");
    string line;
    QString ftopic = ui->search_topic_prob->text();
    while(getline(in,line)){
        size_t pos = line.find("\t");
        size_t pos1 = line.find("\t", pos+1);
        size_t pos2 = line.find("\t", pos1+1);
        QString topic = QString::fromStdString(line.substr(pos+1,pos1-pos-1));
        if(topic==ftopic){
            QString date = QString::fromStdString(line.substr(0,pos));
            QString lecture = QString::fromStdString(line.substr(pos1+1,pos2-pos1-1));
            ui->view_search_lec_prob->insertPlainText("Date: "+date+"\t\t"+"Topic: " + topic+"\n"+"Lecture"+"\n"+lecture);
        }

    }
    in.close();
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_magnifying_glass_mm_clicked()
{
    ifstream in("C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/mm.txt");
    string line;
    QString ftopic = ui->search_topic_mm->text();
    while(getline(in,line)){
        size_t pos = line.find("\t");
        size_t pos1 = line.find("\t", pos+1);
        size_t pos2 = line.find("\t", pos1+1);
        QString topic = QString::fromStdString(line.substr(pos+1,pos1-pos-1));
        if(topic==ftopic){
            QString date = QString::fromStdString(line.substr(0,pos));
            QString lecture = QString::fromStdString(line.substr(pos1+1,pos2-pos1-1));
            ui->view_searched_mm->insertPlainText("Date: "+date+"\t\t"+"Topic: " + topic+"\n"+"Lecture"+"\n"+lecture);
        }

    }
    in.close();
    ui->stackedWidget->setCurrentIndex(25);
}


void MainWindow::on_search_edit_pai_clicked()
{
    string filename = "C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/pai.txt";
    ifstream in(filename);
    string line;
    QString ftopic = ui->search_edit_topic_pai->text();
    while(getline(in,line)){
        size_t pos = line.find("\t");
        size_t pos1 = line.find("\t", pos+1);
        size_t pos2 = line.find("\n", pos1+1);
        QString topic = QString::fromStdString(line.substr(pos+1,pos1-pos-1));
        if(topic==ftopic){

            QString date = QString::fromStdString(line.substr(0,pos));
            QString lecture = QString::fromStdString(line.substr(pos1+1,pos2-pos1-1));
            ui->edit_date_pai->setText(date);
            ui->edit_topic_pai->setText(topic);
            ui->edit_lec_pai->insertPlainText(lecture);

            break;
        }

    }

    in.close();
    return;
}


void MainWindow::on_discrete_search_edit_clicked()
{
    string filename = "C:/Users/HUSSAIN/OneDrive/Documents/DSA_Project_final/discrete.txt";
    ifstream in(filename);
    string line;
    QString ftopic = ui->discrete_search_topic->text();
    while(getline(in,line)){
        size_t pos = line.find("\t");
        size_t pos1 = line.find("\t", pos+1);
        size_t pos2 = line.find("\n", pos1+1);
        QString topic = QString::fromStdString(line.substr(pos+1,pos1-pos-1));
        if(topic==ftopic){

            QString date = QString::fromStdString(line.substr(0,pos));
            QString lecture = QString::fromStdString(line.substr(pos1+1,pos2-pos1-1));
            ui->edit_date_discrete->setText(date);
            ui->edit_topic_discrete->setText(topic);
            ui->edit_lec_discrete->insertPlainText(lecture);

            break;
        }

    }

    in.close();
    return;
}

