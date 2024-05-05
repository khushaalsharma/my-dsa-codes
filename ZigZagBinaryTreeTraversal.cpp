// LeetCode question

// Runtime: 3ms
// memory usage: 13.2 MB

// used a single queue to keep the track of current level and next level
// current level limit is set by finding the queue size beforing adding nodes of next level

// code:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> solution;
        
        if(root == NULL){
            return solution;
        }
        
        bool leftToRight = true;
        queue<TreeNode*> levels;
        levels.push(root);
        
        while(!levels.empty()){
            
            int size = levels.size();
            vector<int> level(size);
            
            for(int i=0; i<size; i++){
                TreeNode* currNode = levels.front();
                levels.pop();
                
                int index = leftToRight ? i : size - i - 1; //determining index according to direction in zigzag
                
                level[index] = currNode->val;
                
                if(currNode->left){
                    levels.push(currNode->left);
                }
                if(currNode->right){
                    levels.push(currNode->right);
                }
            }
            
            solution.push_back(level);
            leftToRight = !leftToRight;
        }
        
        return solution;
    }
};
