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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
         function(root,diameter);
         return diameter;
    }
private:
    int function(TreeNode* root,int &diameter){
        if(root==NULL){
            return 0;
        }
        int lf=function(root->left,diameter);
        int rt=function(root->right,diameter);
         diameter = max(diameter,lf+rt);
        return max(lf,rt)+1;
    }
};