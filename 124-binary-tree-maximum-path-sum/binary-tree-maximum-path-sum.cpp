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
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        function(root,sum);
        return sum;
    }
private:
    int function(TreeNode* root,int &sum){
        if(root==NULL){
            return 0;
        }
        int lf=max(0,function(root->left,sum));
        int rt=max(0,function(root->right,sum));
         sum = max(sum,lf+rt+root->val);
        return max(lf,rt)+root->val;
    } 
};