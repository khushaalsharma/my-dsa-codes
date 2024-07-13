/*
Control the corners as we circle through the whole matrix.

We can store the indices of the corners and using ‘if’ conditions we can traverse in circle. Once we’re back to the element at [0][0], we can shrink the matrix by 1 by manipulating the corner indices.
I might have not done great job in naming the variables in the code. Here are the variables I used to make it easier to understand.

r_min -> Index of the first row
r_max -> Index of the last row
c_min -> Index of the first column
c_max -> Index of the last column
r and c are the indices of current element to be returned.

*/

class Solution {
public:
    vector spiralOrder(vector<vector>& matrix) {
        int r_min = 0, c_min = 0;
        int r_max = matrix.size()-1, c_max = matrix[0].size()-1;
        vector result;

        for(int i=0, r = 0, c = 0; i<matrix.size()*matrix[0].size(); i++)
        {
            result.push_back(matrix[r][c]);

            if     (r==r_min && c!=c_max) c++;
            else if(r!=r_max && c==c_max) r++;
            else if(r==r_max && c!=c_min) c--;
            else if(r!=r_min && c==c_min) r--;

            if(r==r_min && c==c_min) r++, c++, r_min++, c_min++, r_max--, c_max--;
        }
        return result;
    }
};
