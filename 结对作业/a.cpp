#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

// ��������ɺ���
int RandNum(int max_num)
{
    return rand() % max_num + 1;
}

// ����������������
char RandOperator(vector<char> operators)
{
    int idx = rand() % operators.size();
    return operators[idx];
}

// ����������ʽ
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
        //������
        if (with_parenthesis)
        {
            //�������λ��
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
            //���������λ��
            int re = RandNum(2);
            if (re == 2)
                swap(operators[0], operators[1]);
            out << num1 << " " << operators[0] << " " << num2 << " " << operators[1] << " " << num3 << " = \n";
        }
    }
    else if (operators.size() == 3)
    {
        //������
        if (with_parenthesis)
        {
            //�������λ��
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
        //������
        if (with_parenthesis)
        {
            //�������λ��
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
        // ��С��������£���һ����������С��
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

// ������
int main()
{
    // �������������
    srand((unsigned)time(NULL));

    // �û����ò���
    int num_of_questions;      // ��Ŀ����
    vector<char> operators;    // �����
    bool with_parenthesis;     // �Ƿ������
    bool with_decimal = false; // �Ƿ����С��
    int max_num;               // �����
    string output_type;        // �����ʽ

    cout << "��������Ŀ������";
    cin >> num_of_questions;

    cout << "��ѡ�������������+��-��*��/��������ϣ���";
    string ops_str;
    cin >> ops_str;
    for (int i = 0; i < ops_str.size(); i++)
    {
        operators.push_back(ops_str[i]);
    }

    cout << "�Ƿ���Ҫ�����ţ�������1Ϊ�ǣ�0Ϊ��";
    cin >> with_parenthesis;
    cout << "�Ƿ����С����������1Ϊ�ǣ�0Ϊ��";
    cin >> with_decimal;
    cout << "�������������";
    cin >> max_num;
    cout << "��ѡ�������ʽ������1Ϊ�ļ���0Ϊ����̨����";
    cin >> output_type;

    // ������ļ�
    if (output_type == "1")
    {
        string file_name;
        cout << "�������ļ�����";
        cin >> file_name;
        ofstream fout(file_name.c_str());
        for (int i = 0; i < num_of_questions; i++)
        {
            RandExpression(max_num, with_parenthesis, with_decimal, operators, fout);
        }
        fout.close();
        cout << "��Ŀ��������ļ���" << endl;
    }
    // ���������̨
    else
    {
        for (int i = 0; i < num_of_questions; i++)
        {
            RandExpression(max_num, with_parenthesis, with_decimal, operators, cout);
        }
    }

    return 0;
}