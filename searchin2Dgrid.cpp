// We have three approaches here:
//1) We can use the brute force way nested loops - O(nm) [Brute Force]
//2) We can use binary search over a row which is selected - O(mlogn) [Decent Sol]
//3) We will set row at 0 and col at m-1 if m[row][col] > target ie the element can't be in that column thus col-- else it can't be in this row thus row++ - O(n+m) [Efficient Sol]

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size()-1;
        
        int m = matrix.size();
        
        while(row < m && col >= 0){
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] > target){
                col--; //Element won't be in this column as columns are in ascending order
            }
            else{
                row++; //element won't be in this row as they are too in ascending order
            }
        }
        
        return false;
    }
};
