// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7414004855074865196
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

// 使用两个栈：一个用于存储操作数（values），另一个用于存储运算符（ops）
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int applyOp(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}
// step1 从左往右遍历表达式中每一个字符
// step2 读取后续字符直到非数字字符，构成纯数字的values栈
// step3

int solution(std::string expression)
{
    // Please write your code here
    std::stack<int> values;
    std::stack<char> ops;
    // we get two stacks: values and ops
    for (int i = 0; i < expression.length(); i++)
    {
        // values stack
        if (isdigit(expression[i]))
        {
            int val = 0;
            while (i < expression.length() && isdigit(expression[i]))
            {
                val = (val * 10) + (expression[i] - '0');
                i++;
            }
            i--;
            values.push(val);
        }
        // ops stack
        // 如果当前字符是左括号(，则直接压入ops栈
        else if (expression[i] == '(')
        {
            ops.push(expression[i]);
        }
        // 如果当前字符是右括号)，则从ops栈中弹出运算符，并从values栈中弹出两个操作数进行计算，直到遇到左括号(。
        else if (expression[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            if (!ops.empty())
                ops.pop();
        }
        // 如果当前字符是运算符（+、-、*、/），则比较当前运算符与ops栈顶运算符的优先级
        else
        {
            // 栈顶运算符优先级较高或相等，则先计算栈顶运算符的操作，并将结果压入values栈。
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i]))
            {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(expression[i]);
        }
    }
    while (!ops.empty())
    {
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = ops.top();                  // 获取栈顶运算符
        ops.pop();                            // 弹出栈顶运算符
        values.push(applyOp(val1, val2, op)); // 传递正确的运算符
    }
    return values.top();
}

int main()
{
    // You can add more test cases here
    std::cout << (solution("1+1") == 2) << std::endl;
    std::cout << (solution("3+4*5/(3+2)") == 7) << std::endl;
    std::cout << (solution("4+2*5-2/1") == 12) << std::endl;
    std::cout << (solution("(1+(4+5+2)-3)+(6+8)") == 23) << std::endl;
    return 0;
}