// time taken : 114 ms
// memory taken : 17.4MB
class info{
    public:
    int data;
    int row;
    int col;
    
    info(int d, int r, int c){
        data = d;
        row = r;
        col = c;
    }
};

class cmp{
    public:
    bool operator()(info* a, info* b){
        return a->data > b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans;
        priority_queue<info*, vector<info*>, cmp> minheap;
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            mini = min(mini,nums[i][0]);
            maxi = max(maxi,nums[i][0]);
            info* node = new info(nums[i][0],i,0);
            minheap.push(node);
        }
        int start = mini, end = maxi;
        while(!minheap.empty()){
            info* temp = minheap.top();
            mini = temp->data;
            minheap.pop();
            if(end-start>maxi-mini){
                start = mini;
                end = maxi;
            }
            if(temp->col != nums[temp->row].size()-1){
                info* node = new info(nums[temp->row][temp->col+1],temp->row, temp->col+1);
                minheap.push(node);
                maxi = max(maxi,node->data);
            }
            else{
                break;
            }
            //len = maxi-mini;
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};
