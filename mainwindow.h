#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_tabWidget_currentChanged(int index);

    void on_txt_input_textChanged(const QString &arg1);
    void on_txt_input_1_textChanged(const QString &arg1);

    void on_btn_plus_released();
    void on_btn_minus_released();
    void on_btn_mult_released();
    void on_btn_div_released();

    void on_btn_1_released();
    void on_btn_2_released();
    void on_btn_3_released();
    void on_btn_4_released();
    void on_btn_5_released();
    void on_btn_6_released();
    void on_btn_7_released();
    void on_btn_8_released();
    void on_btn_9_released();
    void on_btn_0_released();

    void on_btn_dot_released();
    void on_btn_clear_released();
    void on_btn_percent_released();
    void on_btn_delete_released();

    ///////////////////////////////////////////

    void on_btn_00_1_clicked();
    void on_btn_0_1_released();
    void on_btn_1_1_released();
    void on_btn_2_1_released();
    void on_btn_3_1_released();
    void on_btn_4_1_released();
    void on_btn_5_1_released();
    void on_btn_6_1_released();
    void on_btn_7_1_released();
    void on_btn_8_1_released();
    void on_btn_9_1_released();

    void on_btn_plus_1_released();
    void on_btn_minus_1_released();
    void on_btn_mult_1_released();
    void on_btn_div_1_released();
    void on_btn_percent_1_released();
    void on_btn_fack_clicked();
    void on_btn_degree_clicked();

    void on_btn_dot_1_released();
    void on_btn_clear_1_released();
    void on_btn_delete_1_released();

    void on_btn_e_released();
    void on_btn_pi_clicked();

    void on_btn_open_brace_clicked();
    void on_btn_close_brace_clicked();
    void on_btn_module_clicked();

    void on_btn_sin_clicked();
    void on_btn_cos_clicked();
    void on_btn_tg_clicked();
    void on_btn_ctg_clicked();
    void on_btn_sec_clicked();
    void on_btn_csc_clicked();
    void on_btn_ln_clicked();
    void on_btn_log_clicked();
    void on_btn_sqrt_clicked();
    void on_btn_exp_clicked();

    ///////////////////////////////////////

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString expression;
    QString answer;

    QString expression1;
    QString answer1;
};
#endif // MAINWINDOW_H
