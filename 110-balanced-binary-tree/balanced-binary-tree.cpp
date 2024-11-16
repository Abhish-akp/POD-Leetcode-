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
    bool isBalanced(TreeNode* root) {
        return checker(root)!=-1;
    }
private:
  int checker(TreeNode* root){
    if(root == NULL){
            return 0;
        }
        int lf = checker(root->left);
        if(lf == -1) return -1;
        int rt = checker(root->right);
        if(rt == -1) return -1;
        return abs(lf-rt)>1? -1: max(lf,rt)+1;
  }
};