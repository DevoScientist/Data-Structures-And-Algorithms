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
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>num_table(10);
        int count = 0;
        printPathsRecur(root, num_table ,count);
        return count;
    }
private:
    void printPathsRecur(TreeNode* node,  vector<int>& num_table,int& count) 
    { 
        
        if (node == NULL) 
            return ; 
        
        /* append this node to the path map */
        num_table[node->val] = ! num_table[node->val] ;

               
        
        /* it's a leaf, do operation on the path that lead to here */
        if (node->left == NULL && node->right == NULL) 
        { 
            int z = accumulate(num_table.begin(),num_table.end(),0);
            
            if(z == 0 || z==1) count ++;
        } 
        else
        { 
            /* otherwise try both subtrees */
            printPathsRecur(node->left, num_table, count); 
            printPathsRecur(node->right, num_table, count); 
        }
        num_table[node->val]= ! num_table[node->val] ;
    } 
 
 
  
    
};