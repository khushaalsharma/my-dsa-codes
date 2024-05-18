class Solution {
private:
    void parenthesis(vector<string> &solution, string &str, int open, int close){
        if(open == close && open == 0){
            solution.push_back(str);
            return;
        }
        
        if(open > 0){
            str.push_back('(');
            parenthesis(solution, str, open-1, close);
            str.pop_back();
        }
        if(close > open){
            str.push_back(')');
            parenthesis(solution, str, open, close-1);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> solution;
        string str = "";
        
        parenthesis(solution, str, n, n);
        
        return solution;
    }
};
