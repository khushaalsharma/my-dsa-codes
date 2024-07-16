class Solution {
private:
    int solve(int num1, int num2, char opr) {
        switch (opr) {
            case '+': return num1 + num2;
            case '-': return num1 - num2;
            case '*': return num1 * num2;
            case '/': return num1 / num2;
        }
        return 0; // Default case, should never be reached
    }

    int precedence(char opr) {
        if (opr == '+' || opr == '-') {
            return 1;
        } else if (opr == '*' || opr == '/') {
            return 2;
        }
        return 0;
    }

    void applyOperation(stack<int>& nums, stack<char>& operators) {
        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();
        char opr = operators.top();
        operators.pop();
        nums.push(solve(a, b, opr));
    }

public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> operators;
        int n = s.length();
        int num = 0;
        bool hasNum = false;

        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                hasNum = true;
            } else {
                if (hasNum) {
                    nums.push(num);
                    num = 0;
                    hasNum = false;
                }
                if (s[i] == ' ') {
                    continue;
                } else if (s[i] == '(') {
                    operators.push(s[i]);
                } else if (s[i] == ')') {
                    while (operators.top() != '(') {
                        applyOperation(nums, operators);
                    }
                    operators.pop(); // Pop the '('
                } else {
                    while (!operators.empty() && precedence(operators.top()) >= precedence(s[i])) {
                        applyOperation(nums, operators);
                    }
                    operators.push(s[i]);
                }
            }
        }

        if (hasNum) {
            nums.push(num);
        }

        while (!operators.empty()) {
            applyOperation(nums, operators);
        }

        return nums.top();
    }
};
