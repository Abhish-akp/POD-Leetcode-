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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int>res;
        // queue<TreeNode*>q;
        // q.push(root);
        // while(!q.empty()){
        //     int size=q.size();
        //     for(int i=0;i<size;i++){
        //         TreeNode* node = q.front();
        //         q.pop();
        //         if(i==size-1){
        //             res.push_back(node->val);
        //         }
        //         if(node->left!=NULL){
        //             q.push(node->left);
        //         }
        //         if(node->right!=NULL){
        //             q.push(node->right);
        //         }
        //     }
        // }
        function(root,1,res);
        return res;
    }
private:
    void function(TreeNode* root,int value,vector<int>&res){
        if(root==NULL){
            return ;
        }
        if(res.size()<value){
            res.push_back(root->val);
        }
        function(root->right,value+1,res);
         function(root->left,value+1,res);
    }
};