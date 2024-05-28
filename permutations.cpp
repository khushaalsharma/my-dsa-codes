class Solution {
public:
    
    void permutations(vector<vector<int>> &solution, vector<int> &nums, int begin){
        if(begin == nums.size()){
            solution.push_back(nums);
            return;
        }
        
        for(int i = begin; i < nums.size(); i++){
            swap(nums[begin], nums[i]);
            permutations(solution, nums, begin+1);
            swap(nums[begin], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> solution;
        
        permutations(solution, nums, 0);
        
        return solution;
    }
};
