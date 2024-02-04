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
 void LeafNodes(TreeNode* root , vector<int>& v) {
    if (root == nullptr) {
        return;
    }

    // Check if the current node is a leaf node
    if (root->left == nullptr && root->right == nullptr) {
       v.push_back(root->val);  
    }

    // Recursively traverse the left and right subtrees
    LeafNodes(root->left , v);
    LeafNodes(root->right, v);
}
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        LeafNodes(root1 , v1);
        LeafNodes(root2 , v2);
        if(v1 == v2 ) return true;
        else return false;
    }
};