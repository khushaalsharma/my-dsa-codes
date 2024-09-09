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


//SPIRAL MATRIX IV LEETCODE:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Create matrix of size m x n initialized to -1
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        if (head == NULL) {
            return matrix;  // return matrix if the linked list is empty
        }

        int r_min = 0, r_max = m - 1, c_min = 0, c_max = n - 1;
        ListNode* node = head;

        while (r_min <= r_max && c_min <= c_max && node != NULL) {
            // Fill top row (left to right)
            for (int c = c_min; c <= c_max && node != NULL; ++c) {
                matrix[r_min][c] = node->val;
                node = node->next;
            }
            ++r_min;

            // Fill right column (top to bottom)
            for (int r = r_min; r <= r_max && node != NULL; ++r) {
                matrix[r][c_max] = node->val;
                node = node->next;
            }
            --c_max;

            // Fill bottom row (right to left)
            for (int c = c_max; c >= c_min && node != NULL; --c) {
                matrix[r_max][c] = node->val;
                node = node->next;
            }
            --r_max;

            // Fill left column (bottom to top)
            for (int r = r_max; r >= r_min && node != NULL; --r) {
                matrix[r][c_min] = node->val;
                node = node->next;
            }
            ++c_min;
        }

        return matrix;
    }
};

