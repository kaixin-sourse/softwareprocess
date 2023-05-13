#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

// 随机数生成函数
int RandNum(int max_num)
{
    return rand() % max_num + 1;
}

// 随机生成整数运算符
char RandOperator(vector<char> operators)
{
    int idx = rand() % operators.size();
    return operators[idx];
}

// 生成随机表达式
void RandExpression(int max_num, bool with_parenthesis, bool with_decimal, vector<char> operators, ostream &out)
{
    double num1 = RandNum(max_num);
    double num2 = RandNum(max_num);
    double num3 = RandNum(max_num);
    double num4 = RandNum(max_num);
    double num5 = RandNum(max_num);
    if (with_decimal)
    {
        double tt = RandNum(100);
        num1 += tt / 100;
        tt = RandNum(100);
        num2 += tt / 100;
        tt = RandNum(100);
        num3 += tt / 100;
        tt = RandNum(100);
        num4 += tt / 100;
        tt = RandNum(100);
        num5 += tt / 100;
    }
    char op = RandOperator(operators);
    if (operators.size() == 1)
    {
        out << num1 << " " << *operators.begin() << " " << num2 << " = \n";
    }
    else if (operators.size() == 2)
    {
        //有括号
        if (with_parenthesis)
        {
            //随机括号位置
            int re = RandNum(2);
            if (re == 1)
            {
                out << "(" << num1 << " " << operators[0] << " " << num2 << ") " << operators[1] << " " << num3 << " = \n";
            }
            else
            {
                out << num1 << " " << operators[0] << " (" << num2 << " " << operators[1] << " " << num3 << ") = \n";
            }
        }
        else
        {
            //随机操作符位置
            int re = RandNum(2);
            if (re == 2)
                swap(operators[0], operators[1]);
            out << num1 << " " << operators[0] << " " << num2 << " " << operators[1] << " " << num3 << " = \n";
        }
    }
    else if (operators.size() == 3)
    {
        //有括号
        if (with_parenthesis)
        {
            //随机括号位置
            int re = RandNum(2);
            if (re == 1)
                out << "(" << num1 << " " << operators[0] << " " << num2 << ") " << operators[1] << " " << num3 << " " << operators[2] << " " << num4 << " = \n";
            else
            {
                out << "(" << num1 << " " << operators[0] << " " << num2 << " " << operators[1] << " " << num3 << ") " << operators[2] << " " << num4 << " = \n";
            }
        }
        else
        {
            int re = RandNum(2);
            if (re == 1)
            {
                swap(operators[0], operators[1]);
            }
            else
            {
                swap(operators[1], operators[2]);
            }
            out << num1 << " " << operators[0] << " " << num2 << " " << operators[1] << " " << num3 << " " << operators[2] << " " << num4 << " = \n";
        }
    }
    else
    {
        //有括号
        if (with_parenthesis)
        {
            //随机括号位置
            int re = RandNum(3);
            if (re == 1)
            {
                swap(operators[0], operators[1]);
                out << num1 << " " << operators[0] << " (" << num2 << " " << operators[1] << " " << num3 << ") " << operators[2] << " " << num4 << " " << operators[3] << " " << num5 << " = \n";
            }
            else if (re == 2)
            {
                swap(operators[1], operators[2]);
                out << num1 << " " << operators[0] << " " << num2 << " " << operators[1] << " (" << num3 << " " << operators[2] << " " << num4 << ") " << operators[3] << " " << num5 << " = \n";
            }
            else
            {
                swap(operators[2], operators[3]);
                out << num1 << " " << operators[0] << " (" << num2 << " " << operators[1] << " " << num3 << ") " << operators[2] << " " << num4 << " " << operators[3] << " " << num5 << " = \n";
            }
            // out << "(" << num1 << " " << operators[0] << " " << num2 << " " << operators[1] << " " << num3 << ") " << operators[2] << " " << num4 << " " << operators[3] << " " << num5 << " = \n";
        }
        else
        {
            int re1 = RandNum(4) - 1;
            int re2 = RandNum(4) - 1;
            swap(operators[re1], operators[re2]);
            re1 = RandNum(4) - 1;
            re2 = RandNum(4) - 1;
            swap(operators[re1], operators[re2]);
            out << num1 << " " << operators[0] << " " << num2 << " " << operators[1] << " " << num3 << " " << operators[2] << " " << num4 << " " << operators[3] << " " << num5 << " = \n";
        }
    }
    /*
    if (with_decimal && rand() % 2 == 0)
    {
        // 有小数的情况下，有一定概率生成小数
        double decimal_num = (double)RandNum(max_num) / 10.0;
        num = (int)(decimal_num * 10.0);
    }

    if (with_parenthesis && rand() % 2 == 0)
    {
        out << "(";
        with_parenthesis = false;
    }
    out << num;
    if (with_parenthesis && rand() % 2 == 0)
    {
        out << ")";
    }
    out << " " << op << " ";
    if (with_parenthesis && rand() % 2 == 0)
    {
        out << "(";
    }
    num = RandNum(max_num);
    if (with_decimal && rand() % 2 == 0)
    {
        double decimal_num = (double)RandNum(max_num) / 10.0;
        num = (int)(decimal_num * 10.0);
    }
    out << num;
    if (with_parenthesis && rand() % 2 == 0)
    {
        out << ")";
    }
    out << " = " << endl;
    */
}

// 主函数
int main()
{
    // 设置随机数种子
    srand((unsigned)time(NULL));

    // 用户设置参数
    int num_of_questions;      // 题目数量
    vector<char> operators;    // 运算符
    bool with_parenthesis;     // 是否带括号
    bool with_decimal = false; // 是否包含小数
    int max_num;               // 最大数
    string output_type;        // 输出方式

    cout << "请输入题目数量：";
    cin >> num_of_questions;

    cout << "请选择运算符（输入+，-，*，/中任意组合）：";
    string ops_str;
    cin >> ops_str;
    for (int i = 0; i < ops_str.size(); i++)
    {
        operators.push_back(ops_str[i]);
    }

    cout << "是否需要带括号？（输入1为是，0为否）";
    cin >> with_parenthesis;
    cout << "是否包含小数？（输入1为是，0为否）";
    cin >> with_decimal;
    cout << "请输入最大数：";
    cin >> max_num;
    cout << "请选择输出方式（输入1为文件，0为控制台）：";
    cin >> output_type;

    // 输出到文件
    if (output_type == "1")
    {
        string file_name;
        cout << "请输入文件名：";
        cin >> file_name;
        ofstream fout(file_name.c_str());
        for (int i = 0; i < num_of_questions; i++)
        {
            RandExpression(max_num, with_parenthesis, with_decimal, operators, fout);
        }
        fout.close();
        cout << "题目已输出到文件！" << endl;
    }
    // 输出到控制台
    else
    {
        for (int i = 0; i < num_of_questions; i++)
        {
            RandExpression(max_num, with_parenthesis, with_decimal, operators, cout);
        }
    }

    return 0;
}