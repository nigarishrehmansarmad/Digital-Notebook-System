#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_10_clicked();

    void on_Pai_clicked();

    void on_DS_clicked();

    void on_discrete_clicked();

    void on_mm_clicked();

    void on_prob_clicked();

    void on_add_ds_clicked();

    void on_pushButton_clicked();

    void on_view_ds_clicked();

    void on_manifying_glass_clicked();

    void on_search_ds_clicked();

    void on_search_edit_clicked();

    void on_edit_ds_clicked();

    void on_save_ds_edit_clicked();

    void on_save_ds_clicked();

    void on_add_discrete_clicked();

    void on_discrete_save_clicked();

    void on_back_ds_clicked();

    void on_back_discrete_clicked();

    void on_edit_discrete_clicked();

    void on_search_edit_topic_textEdited(const QString &arg1);

    void on_ds_search_edit_clicked();

    void on_ds_edit_save_clicked();

    void on_ds_lec_view_copyAvailable(bool b);

    void on_back_prob_clicked();

    void on_back_add_discrete_clicked();

    void on_back_search_discrete_clicked();

    void on_back_view_discrete_clicked();

    void on_back_add_ds_clicked();

    void on_back_edit_ds_clicked();

    void on_back_add_mm_clicked();

    void on_back_edit_mm_clicked();

    void on_back_search_mm_clicked();

    void on_back_view_mm_clicked();

    void on_back_add_pai_clicked();

    void on_back_edit_pai_clicked();

    void on_back_search_pai_clicked();

    void on_back_add_prob_clicked();

    void on_back_edit_prob_clicked();

    void on_back_search_prob_clicked();

    void on_back_view_prob_clicked();

    void on_back_mm_clicked();

    void on_view_mm_clicked();

    void on_edit_mm_clicked();

    void on_search_mm_clicked();

    void on_add_pai_clicked();

    void on_view_pai_clicked();

    void on_edit_pai_clicked();

    void on_search_pai_clicked();

    void on_add_prob_clicked();

    void on_view_prob_clicked();

    void on_edit_prob_clicked();

    void on_search_prob_clicked();

    void on_back_search_ds_clicked();

    void on_search_topic_ds_cursorPositionChanged(int arg1, int arg2);

    void on_back_edit_discrete_clicked();

    void on_view_discrete_clicked();

    void on_search_discrete_clicked();

    void on_magnifying_glass_clicked();

    void on_back_view_ds_clicked();

    void on_discrete_edit_save_clicked();

    void on_back_view_pai_clicked();

    void on_save_add_pai_clicked();

    void on_back_pai_clicked();

    void on_add_save_mm_clicked();

    void on_add_mm_clicked();

    void on_edit_search_topic_mm_clicked();

    void on_save_edit_mm_clicked();

    void on_save_add_prob_clicked();

    void on_save_edit_pai_clicked();

    void on_edit_search_prob_clicked();

    void on_magnifying_glass_pai_clicked();

    void on_magnifying_glass_prob_clicked();

    void on_magnifying_glass_mm_clicked();

    void on_search_edit_pai_clicked();

    void on_discrete_search_edit_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
