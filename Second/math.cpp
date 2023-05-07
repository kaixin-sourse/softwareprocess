#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
// 随机生成范围内的整数
int random_int(int min_value, int max_value)
{
    return rand() % (max_value - min_value + 1) + min_value;
}

// 生成加法运算符
char generate_add_operator()
{
    return '+';
}

// 生成减法运算符
char generate_sub_operator()
{
    return '-';
}

// 生成乘法运算符
char generate_mul_operator()
{
    return '*';
}

// 生成除法运算符
char generate_div_operator()
{
    return '/';
}

// 随机生成给定范围内的运算符
char generate_operator(int grade)
{
    if (grade == 1)
    {
        // 只生成加法或减法运算式
        return random_int(0, 1) ? generate_add_operator() : generate_sub_operator();
    }
    else if (grade == 2)
    {
        // 生成加法和减法混合运算式
        return random_int(0, 1) ? generate_add_operator() : generate_sub_operator();
    }
    else if (grade == 3)
    {
        // 生成加法、减法和乘法混合运算式
        int operator_id = random_int(0, 2);
        switch (operator_id)
        {
        case 0:
            return generate_add_operator();
        case 1:
            return generate_sub_operator();
        case 2:
            return generate_mul_operator();
        }
    }
    else
    {
        // 生成随机的三个运算符
        char operator1 = generate_add_operator();
        char operator2 = generate_sub_operator();
        char operator3 = generate_mul_operator();
        if (grade > 4)
        {
            // 添加除法运算符
            operator3 = random_int(0, 1) ? operator3 : generate_div_operator();
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

// 生成指定位数的自然数
int generate_number(int num_digits)
{
    int min_value = num_digits == 1 ? 1 : (int)pow(10, num_digits - 1);
    int max_value = (int)pow(10, num_digits) - 1;
    return random_int(min_value, max_value);
}

// 生成四则运算表达式
void generate_expression(int grade, int num_operands)
{
    char operator1;
    int result, operand1, operand2, operand3;

    if (grade == 1)
    {
        // 只含有两个操作数的加减法运算
        while (num_operands--)
        {
            operand1 = generate_number(1);
            operand2 = generate_number(1);
            if (operator1 == '-')
            {
                if (operand1 < operand2)
                {
                    int temp = operand1;
                    operand1 = operand2;
                    operand2 = temp;
                }
            }
            operator1 = generate_operator(grade);
            printf("%d %c %d = \n", operand1, operator1, operand2);
        }
    }
    else if (grade == 2)
    {
        // 混合加减法运算
        while (num_operands--)
        {
            operand1 = generate_number(1);
            operand2 = generate_number(1);
            if (operator1 == '-')
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
                operator1 = generate_add_operator();
            }
            else
            {
                operator1 = generate_sub_operator();
                if (operand1 < operand2)
                {
                    int temp = operand1;
                    operand1 = operand2;
                    operand2 = temp;
                }
            }
            printf("%d %c %d = \n", operand1, operator1, operand2);
        }
    }
    else if (grade == 3)
    {
        // 包含乘法的混合运算
        while (num_operands--)
        {
            if (random_int(0, 1))
            {
                operand1 = generate_number(1);
                operand2 = generate_number(1);
                operator1 = generate_operator(grade);
                printf("%d %c %d = \n", operand1, operator1, operand2);
            }
            else
            {
                operand1 = generate_number(1);
                operand2 = generate_number(1);
                operand3 = generate_number(1);
                operator1 = generate_operator(grade);
                int flag = random_int(0, 1);
                if (flag == 0)
                {
                    printf("%d %c %d = \n", operand1, operator1, operand2);
                    printf("%d %c %d = \n", result = operand1 * operand2, operator1, operand3);
                }
                else
                {
                    printf("%d %c %d = \n", operand2, operator1, operand3);
                    printf("%d %c %d = \n", result = operand1 * operand2, operator1, operand3);
                }
            }
        }
    }
    else
    {
        // 含括号的混合运算
        while (num_operands--)
        {
            operand1 = generate_number(1);
            operand2 = generate_number(1);
            operand3 = generate_number(1);
            operator1 = generate_operator(grade);
            int flag1 = random_int(0, 1);
            if (flag1 == 0)
            {
                int flag2 = random_int(0, 1);
                if (flag2 == 0)
                {
                    printf("(%d %c %d) %c %d = \n", operand1, operator1, operand2, operator1, operand3);
                }
                else
                {
                    printf("%d %c (%d %c %d) = \n", operand1, operator1, operand2, operator1, operand3);
                }
            }
            else
            {
                if (random_int(0, 1))
                {
                    printf("%d %c %d %c %d = \n", operand1, operator1, operand2, operator1, operand3);
                }
                else
                {
                    printf("%d %c (%d %c %d) = \n", operand1, operator1, operand2, operator1, operand3);
                }
            }
        }
    }
}

// 主函数
int main()
{
    int grade, num_operands;
    srand(time(NULL)); // 初始化随机数生成器
    printf("请输入年级（1~6）：");
    scanf("%d", &grade);
    printf("请输入题目数量：");
    scanf("%d", &num_operands);
    printf("\n生成的 %d 道 %d 年级数学题目如下：\n\n", num_operands, grade);
    generate_expression(grade, num_operands);
    return 0;
}
