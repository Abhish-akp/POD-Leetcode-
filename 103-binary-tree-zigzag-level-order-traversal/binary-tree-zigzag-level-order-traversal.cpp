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
        vector<vector<int>>zig_zag;
        if(root==NULL){
            return zig_zag;
        }
        queue<TreeNode*>q;
        int left_to_right=true;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>lvl(n);
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                int index= left_to_right? i: n-i-1;
                lvl[index]=node->val;
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            left_to_right=!left_to_right;
            zig_zag.push_back(lvl);
        }
        return zig_zag;
    }
};