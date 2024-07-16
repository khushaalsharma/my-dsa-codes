/*
When the algorithm encounters a digit, it parses the digits as a number and pushes the number onto the stack.
When the algorithm encounters an operator, it pops two numbers off the stack, performs the operation, and pushes the result back onto the stack.
When the algorithm encounters a left parenthesis, it pushes the current state of the stack onto a new stack.
When the algorithm encounters a right parenthesis, it pops the top stack, performs the operations on the numbers on the top of the stack, and pushes the result back onto the stack.
After iterating over the entire string, the algorithm pops the top number off the stack and returns it as the result of the expression.
Complexity
Time complexity: O(S)
Space complexity: O(S)
*/


class Solution {
public:
    int calculate(string s) {
        long long int sum = 0;
        int sign = 1;
        stack<pair<int,int>> st;

        for(int i=0; i<s.size();i++){
            if(isdigit(s[i])){
                long long int num = 0;
                while(i<s.size() && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                sum += num * sign;
                sign = 1;
            }
            else if(s[i] == '('){
                st.push({sum, sign});
                sum = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                sum = st.top().first + (st.top().second * sum);
                st.pop();

            }
            else if(s[i] == '-'){
                sign = -1 * sign;
            }
        }
        return sum;
    }
};
