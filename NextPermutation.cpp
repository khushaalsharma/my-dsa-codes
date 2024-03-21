//This is the Optimal solution for the next permutation problem Leetcode 31

// We follow following approach take the array: [1,2,3] for eg with solution [1, 3, 2]
// Observation in these case: 
//1)longer prefix match is required 
//2)break point when the element at 0 index of right array has one or more elements greater than itself on its right
// ie a[i] < a[i+1]
//3) Find someone greater than the breakpoint element (in each previous iteration we have an desc order in rigth and asc in left thus when this breaks we have our breakpoint and we need to find teh first element which is just greater than the breakpoint element)
// iteration 1: left: [1,2,3] right: [] -> no possible change
// iteration 2: left: [1,2] right: [3] -> no possible change
// iteration 3: left: [1] right: [2,3] -> possible change : [2,3] and [3,2]
// hence we return [1,3,2]

//CODE:
class Solution {
public:
    void printArray(vector<int> nums){
        for(int i=0; i<nums.size(); i++){
            cout<<nums[i]<<" ";
        }
    }
    bool checkDesc(vector<int> nums, int index){
        //index is the index of the first elemnet of right array
        for(int i=index; i<nums.size()-1; i++){
            if(nums[i] < nums[i+1]){
                return false;
            }
        }

        return true;
    }
    int findTheFirstGreater(vector<int> nums, int last){ //last is the index of element just right to breakpoint element
        if(last == nums.size()-1){
            return last;
        }

        int firstGreaterIndex;
        for(int i=nums.size()-1; i>=last; i--){ //traversing from last as the right array is in desc order
            if(nums[i] > nums[last-1]){
                firstGreaterIndex = i;
                break;
            }
        }

        return firstGreaterIndex;
    }
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2){
            return ;
        }

        if(checkDesc(nums, 0)){
            sort(nums.begin(), nums.end());
            return;
        }

        vector<int> og_nums = nums;

        for(int i=nums.size()-1; i>-1; i--){
            if(!checkDesc(nums, i)){
                cout<<i<<endl;
                int firstGreater = findTheFirstGreater(nums, i+1);
                cout<<nums[firstGreater]<<endl;
                swap(nums[firstGreater], nums[i]);
                printArray(nums);
                sort(nums.begin()+i+1, nums.end());
                break;
            }
        }
    }
};
