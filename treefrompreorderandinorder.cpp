class Solution {
private:
    TreeNode* buildTreeHelper(int& preorderIndex, vector<int>& preorder, unordered_map<int, int>& inorderMap, int inorderStart, int inorderEnd) {
        if (inorderStart > inorderEnd) {
            return nullptr;
        }
        
        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);
        
        int inorderIndex = inorderMap[rootValue];
        
        root->left = buildTreeHelper(preorderIndex, preorder, inorderMap, inorderStart, inorderIndex - 1);
        root->right = buildTreeHelper(preorderIndex, preorder, inorderMap, inorderIndex + 1, inorderEnd);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        
        int preorderIndex = 0;
        return buildTreeHelper(preorderIndex, preorder, inorderMap, 0, inorder.size() - 1);
    }
};
