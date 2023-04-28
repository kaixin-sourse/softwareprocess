#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// 随机生成范围内的整数
int random_int(int l, int r)
{
    return rand() % (r - l + 1) + l;
}

char add()
{
    return '+';
}

char sub()
{
    return '-';
}

char mul()
{
    return '*';
}

char divv()
{
    return '/';
}

char generate_operator(int grade)
{
    if (grade == 1)
    {
        return random_int(0, 1) ? add() : sub();
    }
    else if (grade == 2)
    {
        return random_int(0, 1) ? add() : sub();
    }
    else if (grade == 3)
    {
        int operator_id = random_int(0, 2);
        switch (operator_id)
        {
        case 0:
            return add();
        case 1:
            return sub();
        case 2:
            return mul();
        }
    }
    else
    {
        char operator1 = add();
        char operator2 = sub();
        char operator3 = mul();
        if (grade > 4)
        {
            operator3 = random_int(0, 1) ? operator3 : divv();
        }
        // 随机选择三个运算符中的两个组合成运算式
        int operator_id = random_int(0, 2);
        switch (operator_id)
        {
        case 0:
            return operator1;
        case 1:
            return operator2;
        case 2:
            return operator3;
        }
    }
}

int generate_number(int num_digits)
{
    int l = num_digits == 1 ? 1 : (int)pow(10, num_digits - 1);
    int r = (int)pow(10, num_digits) - 1;
    return random_int(l, r);
}

void generate_expression(int grade, int num_operands)
{
    char operator;
    int result, operand1, operand2, operand3;

    if (grade == 1)
    {
        while (num_operands--)
        {
            operand1 = generate_number(1);
            operand2 = generate_number(1);
            if (operator== '-')
            {
                if (operand1 < operand2)
                {
                    int temp = operand1;
                    operand1 = operand2;
                    operand2 = temp;
                }
            }
            operator= generate_operator(grade);
            printf("%d %c %d = \n", operand1, operator, operand2);
        }
    }
    else if (grade == 2)
    {
        while (num_operands--)
        {
            operand1 = generate_number(2) % 50;
            operand2 = generate_number(2) % 50;
            if (operator== '-')
            {
                if (operand1 < operand2)
                {
                    int temp = operand1;
                    operand1 = operand2;
                    operand2 = temp;
                }
            }
            int flag = random_int(0, 1);
            if (flag == 0)
            {
                operator= add();
            }
            else
            {
                operator= sub();
                if (operand1 < operand2)
                {
                    int temp = operand1;
                    operand1 = operand2;
                    operand2 = temp;
                }
            }
            printf("%d %c %d = \n", operand1, operator, operand2);
        }
    }
    else if (grade == 3)
    {
        while (num_operands--)
        {
            if (random_int(0, 1))
            {
                operand1 = generate_number(3) % 1000;
                operand2 = generate_number(3) % 1000;
                operator= generate_operator(grade);
                printf("%d %c %d = \n", operand1, operator, operand2);
            }
            else
            {
                operand1 = generate_number(3) % 1000;
                operand2 = generate_number(3) % 1000;
                operand3 = generate_number(2) % 1000;
                operator= generate_operator(grade);
                int flag = random_int(0, 1);
                if (flag == 0)
                {
                    printf("%d %c %d = \n", operand1, operator, operand2);
                    printf("%d %c %d = \n", result = operand1 * operand2, operator, operand3);
                }
                else
                {
                    printf("%d %c %d = \n", operand2, operator, operand3);
                    printf("%d %c %d = \n", result = operand1 * operand2, operator, operand3);
                }
            }
        }
    }
    else
    {
        // 含括号的混合运算
        while (num_operands--)
        {
            operand1 = generate_number(3);
            operand2 = generate_number(3);
            operand3 = generate_number(3);
            operator= generate_operator(grade);
            int flag1 = random_int(0, 1);
            if (flag1 == 0)
            {
                int flag2 = random_int(0, 1);
                if (flag2 == 0)
                {
                    printf("(%d %c %d) %c %d = \n", operand1, operator, operand2, operator, operand3);
                }
                else
                {
                    printf("%d %c (%d %c %d) = \n", operand1, operator, operand2, operator, operand3);
                }
            }
            else
            {
                if (random_int(0, 1))
                {
                    printf("%d %c %d %c %d = \n", operand1, operator, operand2, operator, operand3);
                }
                else
                {
                    printf("%d %c (%d %c %d) = \n", operand1, operator, operand2, operator, operand3);
                }
            }
        }
    }
}

int main()
{
    int grade, num_operands;
    srand(time(NULL));
    printf("请输入年级（1~6）：");
    scanf("%d", &grade);
    printf("请输入题目数量：");
    scanf("%d", &num_operands);
    printf("\n生成的 %d 道 %d 年级数学题目如下：\n\n", num_operands, grade);
    generate_expression(grade, num_operands);
    return 0;
}
