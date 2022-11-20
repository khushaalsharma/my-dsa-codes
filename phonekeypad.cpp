#include <string.h>
class Solution {
public:
    void solve(map<char, string> nums, string digits, vector<string>& ans, string output, int i){
        if(i>=digits.length()){
            ans.push_back(output);
            return ;
        }
        char ch = digits[i];
        string str = nums[ch];
        for(int j=0;j<str.length();j++){
            output.push_back(str[j]);
            solve(nums, digits, ans, output, i+1);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        map<char, string> nums;
        nums.insert(std::pair<char, string>('2',"abc"));
        nums.insert(std::pair<char, string>('3',"def"));
        nums.insert(std::pair<char, string>('4',"ghi"));
        nums.insert(std::pair<char, string>('5',"jkl"));
        nums.insert(std::pair<char, string>('6',"mno"));
        nums.insert(std::pair<char, string>('7',"pqrs"));
        nums.insert(std::pair<char, string>('8',"tuv"));
        nums.insert(std::pair<char, string>('9',"wxyz"));
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string output = "";
        int i = 0 ;
        solve(nums, digits, ans, output, i);
        return ans;
    }
};
