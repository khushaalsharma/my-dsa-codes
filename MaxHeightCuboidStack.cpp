/*
  This problem is solved using tabulation method of DP in LIS problem (longest inc subseq)
  Steps to solve:
  1) Sort the dimensions of cuboids
  2) sort cuboids according to first dimension(width)
  3) Apply LIS problem solution
*/

class Solution {
public:
    bool cmp(vector<int>& a, vector<int>& b){
        return (a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2]);
    }

    int solve(int n, vector<vector<int>> &cuboids){
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr = n-1; curr >= 0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){
                int included = 0;
                if(prev == -1 || cmp(cuboids[prev], cuboids[curr])){
                    included = cuboids[curr][2] + nextRow[curr+1];
                }
                
                int excluded = nextRow[prev+1];

                currRow[prev+1] = max(included, excluded);
            }
            nextRow = currRow;
        }

        return currRow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {

        for(int i=0; i<cuboids.size(); i++){
            sort(cuboids[i].begin(), cuboids[i].end());
        }//sorting the dimensions of all cuboids

        sort(cuboids.begin(), cuboids.end());

        return solve(cuboids.size(), cuboids);
    }
};
