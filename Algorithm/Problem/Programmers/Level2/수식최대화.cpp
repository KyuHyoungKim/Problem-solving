#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

long long solve_the_expression(string& expression, vector<char> operands) {
    string exp = expression;
    for (int op = 0; op < 3; op++) {
        stack<long long> nums;
        stack<char> ops;
        string new_exp, num_str;
        for (int i = 0; i < exp.size(); i++) {
            if (num_str.empty() || isdigit(exp[i])) num_str += exp[i];
            else {
                nums.push(stoll(num_str));
                num_str.clear();
                ops.push(exp[i]);
                if (exp[i] == operands[op]) {
                    num_str += exp[i + 1];
                    i += 2;
                    while (isdigit(exp[i])) {
                        num_str += exp[i];
                        i++;
                    }
                    long long num2 = stoll(num_str);
                    num_str.clear();
                    long long num1 = nums.top();
                    nums.pop();
                    long long num;
                    if (ops.top() == '*') num = num1 * num2;
                    else if (ops.top() == '-') num = num1 - num2;
                    else num = num1 + num2;
                    num_str = to_string(num);
                    ops.pop();
                    i--;
                }
            }
        }
        if (!num_str.empty()) nums.push(stoll(num_str));
        while (!ops.empty()) {
            new_exp = to_string(nums.top()) + new_exp;
            new_exp = ops.top() + new_exp;
            nums.pop();
            ops.pop();
        }
        new_exp = to_string(nums.top()) + new_exp;
        exp = new_exp;
    }

    return abs(stoll(exp));
}

long long solution(string expression) {
    long long answer = 0;
    long long a1 = solve_the_expression(expression, { '*','+','-' });
    long long a2 = solve_the_expression(expression, { '*','-','+' });
    long long a3 = solve_the_expression(expression, { '+','*','-' });
    long long a4 = solve_the_expression(expression, { '+','-','*' });
    long long a5 = solve_the_expression(expression, { '-','*','+' });
    long long a6 = solve_the_expression(expression, { '-','+','*' });
    answer = max({ a1,a2,a3,a4,a5,a6 });
    return answer;
}