#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <Calculator.h>
#include <string>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    setFixedSize(246, 320);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MyUpdate(QString const& symbol,
            QString* expression,
            QString* answer,
            QLineEdit* first,
            QLineEdit* second)
{
    (*expression) += symbol;
    first->setText(*expression);
    second->setText(*answer);
}

void MyUpdate(QString const& symbol,
              QString* expression,
              QLineEdit* first)
{
    (*expression) += symbol;
    first->setText(*expression);
}

void ignoreZero(QString& answer)
{
    auto it = answer.rbegin();
    while (*it++ == '0')
    {
        answer.removeLast();
        if(*it == '.')
        {
            answer.removeLast();
            it++;
            break;
        }
    }
    if(answer == "-0")
        answer = "0";
}

void MainWindow::on_txt_input_textChanged(const QString &arg1)
{
    if (expression.isEmpty())
        return;
    if (arg1.back() == '/')
        return;
    try
    {
        answer = std::to_string(calculator::eval(arg1.toStdString())).c_str();
        ignoreZero(answer);
    }
    catch(std::range_error& e)
    {
        this->ui->txt_answer->setText("Деление на ноль");
    }
    catch(...){}
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    switch(index)
    {
    case 0:
        setFixedSize(246, 320);
        answer1 = 0;
        expression1 = "";
        this->ui->txt_input_1->setText(this->expression1);
        this->ui->txt_answer_1->setText(answer1);
        break;
    case 1:
        setFixedSize(310, 300);
        answer = 0;
        expression = "";
        this->ui->txt_input->setText(this->expression);
        this->ui->txt_answer->setText(answer);
        break;
    case 2:
        setFixedSize(310, 240);
        break;
    }
}

void MainWindow::on_btn_plus_released()
{
    MyUpdate("+", &expression, ui->txt_input);
}

void MainWindow::on_btn_minus_released()
{
    MyUpdate("-", &expression, ui->txt_input);
}

void MainWindow::on_btn_mult_released()
{
    MyUpdate("*", &expression, ui->txt_input);
}

void MainWindow::on_btn_div_released()
{
    MyUpdate("/", &expression, ui->txt_input);
}

void MainWindow::on_btn_1_released()
{
    MyUpdate("1", &expression, &answer, ui->txt_input, ui->txt_answer);
}

void MainWindow::on_btn_2_released()
{
    MyUpdate("2", &expression, &answer, ui->txt_input, ui->txt_answer);
}

void MainWindow::on_btn_3_released()
{
    MyUpdate("3", &expression, &answer, ui->txt_input, ui->txt_answer);
}

void MainWindow::on_btn_4_released()
{
    MyUpdate("4", &expression, &answer, ui->txt_input, ui->txt_answer);
}

void MainWindow::on_btn_5_released()
{
    MyUpdate("5", &expression, &answer, ui->txt_input, ui->txt_answer);
}

void MainWindow::on_btn_6_released()
{
    MyUpdate("6", &expression, &answer, ui->txt_input, ui->txt_answer);
}

void MainWindow::on_btn_7_released()
{
    MyUpdate("7", &expression, &answer, ui->txt_input, ui->txt_answer);
}

void MainWindow::on_btn_8_released()
{
    MyUpdate("8", &expression, &answer, ui->txt_input, ui->txt_answer);
}

void MainWindow::on_btn_9_released()
{
    MyUpdate("9", &expression, &answer, ui->txt_input, ui->txt_answer);
}

void MainWindow::on_btn_0_released()
{
    MyUpdate("0", &expression, &answer, ui->txt_input, ui->txt_answer);
}

void MainWindow::on_btn_dot_released()
{
    MyUpdate(".", &expression, ui->txt_input);
}

void MainWindow::on_btn_clear_released()
{
    this->expression.clear();
    this->answer.clear();
    this->ui->txt_input->setText(this->expression);
    this->ui->txt_answer->setText("");
}

void MainWindow::on_btn_percent_released()
{
    if (!expression.isEmpty())
        MyUpdate("%", &expression, &answer, ui->txt_input, ui->txt_answer);
}

void MainWindow::on_btn_delete_released()
{
    this->expression.removeLast();
    this->ui->txt_input->setText(this->expression);
    if (expression.isEmpty())
        this->ui->txt_answer->setText("");
    else
        this->ui->txt_answer->setText(answer);
}


/////////////////////////////////////////////////////////////////////////////


void MainWindow::on_txt_input_1_textChanged(const QString &arg1)
{
    if (expression1.isEmpty())
        return;
    if (arg1.back() == '/')
        return;
    try
    {
        answer1 = std::to_string(calculator::eval(arg1.toStdString())).c_str();
        ignoreZero(answer1);
    }
    catch(std::range_error& e)
    {
        this->ui->txt_answer_1->setText("Деление на ноль");
    }
    catch(...){}
}

void MainWindow::on_btn_00_1_clicked()
{
    MyUpdate("00", &expression1, &answer1, ui->txt_input_1, ui->txt_answer_1);
}

void MainWindow::on_btn_0_1_released()
{
    MyUpdate("0", &expression1, &answer1, ui->txt_input_1, ui->txt_answer_1);
}

void MainWindow::on_btn_1_1_released()
{
    MyUpdate("1", &expression1, &answer1, ui->txt_input_1, ui->txt_answer_1);
}

void MainWindow::on_btn_2_1_released()
{
    MyUpdate("2", &expression1, &answer1, ui->txt_input_1, ui->txt_answer_1);
}

void MainWindow::on_btn_3_1_released()
{
    MyUpdate("3", &expression1, &answer1, ui->txt_input_1, ui->txt_answer_1);
}

void MainWindow::on_btn_4_1_released()
{
    MyUpdate("4", &expression1, &answer1, ui->txt_input_1, ui->txt_answer_1);
}

void MainWindow::on_btn_5_1_released()
{
    MyUpdate("5", &expression1, &answer1, ui->txt_input_1, ui->txt_answer_1);
}

void MainWindow::on_btn_6_1_released()
{
    MyUpdate("6", &expression1, &answer1, ui->txt_input_1, ui->txt_answer_1);
}

void MainWindow::on_btn_7_1_released()
{
    MyUpdate("7", &expression1, &answer1, ui->txt_input_1, ui->txt_answer_1);
}

void MainWindow::on_btn_8_1_released()
{
    MyUpdate("8", &expression1, &answer1, ui->txt_input_1, ui->txt_answer_1);
}

void MainWindow::on_btn_9_1_released()
{
    MyUpdate("9", &expression1, &answer1, ui->txt_input_1, ui->txt_answer_1);
}

void MainWindow::on_btn_plus_1_released()
{
    MyUpdate("+", &expression1, ui->txt_input_1);
}

void MainWindow::on_btn_minus_1_released()
{
    MyUpdate("-", &expression1, ui->txt_input_1);
}

void MainWindow::on_btn_mult_1_released()
{
    MyUpdate("*", &expression1, ui->txt_input_1);
}

void MainWindow::on_btn_div_1_released()
{
    MyUpdate("/", &expression1, ui->txt_input_1);
}

void MainWindow::on_btn_dot_1_released()
{
    MyUpdate(".", &expression1, &answer1, ui->txt_input_1, ui->txt_answer_1);
}

void MainWindow::on_btn_clear_1_released()
{
    this->expression1.clear();
    this->answer1.clear();
    this->ui->txt_input_1->setText(this->expression1);
    this->ui->txt_answer_1->setText("");
}

void MainWindow::on_btn_percent_1_released()
{
    if (!expression1.isEmpty())
        MyUpdate("%", &expression1, &answer1, ui->txt_input_1, ui->txt_answer_1);
}

void MainWindow::on_btn_delete_1_released()
{
    this->expression1.removeLast();
    this->ui->txt_input_1->setText(this->expression1);
    if (expression1.isEmpty())
        this->ui->txt_answer_1->setText("");
    else
        this->ui->txt_answer_1->setText(answer1);
}

void MainWindow::on_btn_e_released()
{
    MyUpdate("e", &expression1, &answer1, ui->txt_input_1, ui->txt_answer_1);
}

void MainWindow::on_btn_pi_clicked()
{
    MyUpdate("pi", &expression1, &answer1, ui->txt_input_1, ui->txt_answer_1);
}

void MainWindow::on_btn_fack_clicked()
{
    MyUpdate("!", &expression1, &answer1, ui->txt_input_1, ui->txt_answer_1);
}

void MainWindow::on_btn_open_brace_clicked()
{
    MyUpdate("(", &expression1, &answer1, ui->txt_input_1, ui->txt_answer_1);
}

void MainWindow::on_btn_close_brace_clicked()
{
    MyUpdate(")", &expression1, ui->txt_input_1);
}

void MainWindow::on_btn_degree_clicked()
{
    MyUpdate("^", &expression1, ui->txt_input_1);
}

void MainWindow::on_btn_sin_clicked()
{
    MyUpdate("sin(", &expression1, ui->txt_input_1);
}

void MainWindow::on_btn_cos_clicked()
{
    MyUpdate("cos(", &expression1, ui->txt_input_1);
}

void MainWindow::on_btn_tg_clicked()
{
    MyUpdate("tg(", &expression1, ui->txt_input_1);
}

void MainWindow::on_btn_ctg_clicked()
{
    MyUpdate("ctg(", &expression1, ui->txt_input_1);
}

void MainWindow::on_btn_sec_clicked()
{
    MyUpdate("sec(", &expression1, ui->txt_input_1);
}

void MainWindow::on_btn_csc_clicked()
{
    MyUpdate("csc(", &expression1, ui->txt_input_1);
}

void MainWindow::on_btn_ln_clicked()
{
    MyUpdate("ln(", &expression1, ui->txt_input_1);
}

void MainWindow::on_btn_log_clicked()
{
    MyUpdate("log(", &expression1, ui->txt_input_1);
}

void MainWindow::on_btn_sqrt_clicked()
{
    MyUpdate("sqrt(", &expression1, ui->txt_input_1);
}

void MainWindow::on_btn_exp_clicked()
{
    MyUpdate("exp(", &expression1, ui->txt_input_1);
}

void MainWindow::on_btn_module_clicked()
{
    MyUpdate("|", &expression1, &answer1, ui->txt_input_1, ui->txt_answer_1);
}

void MainWindow::on_pushButton_clicked()
{
    std::string begin = ui->txt_num->text().toStdString();
    long a = strtol(begin.c_str(), nullptr, stoi(ui->txt_begin->text().toStdString()));

    char buffer[33];
    ui->txt_ans->setText(itoa(a, buffer, stoi(ui->txt_end->text().toStdString())));
}
