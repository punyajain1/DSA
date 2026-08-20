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
    vector<vector<int>>ans;
    void solve(TreeNode* root,int level){
        if(!root) return;
        if(ans.size()==level){
            ans.push_back(vector<int>());
        }
        ans[level].push_back(root->val);
        solve(root->left,level+1);
        solve(root->right,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        solve(root,0);
        return ans;
    }



    //BFS->
    
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     if(root==NULL) return{};
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     q.push(NULL);
    //     vector<vector<int>> ans;
    //     vector<int> v;
    //     while(!q.empty()){
    //         TreeNode* t=q.front();
    //         q.pop();
    //         if(t==NULL){
    //             ans.push_back(v);
    //             v.clear();
    //             if(!q.empty()){
    //                 q.push(NULL);
    //             }
    //         }else{
    //             v.push_back(t->val);
    //             if(t->left){
    //                 q.push(t->left);
    //             }
    //             if(t->right){
    //                 q.push(t->right);
    //             }
    //         }
    //     }
    //     return ans;
    // }
};