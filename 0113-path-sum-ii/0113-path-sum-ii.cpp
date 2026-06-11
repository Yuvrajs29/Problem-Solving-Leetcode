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
    void solve(TreeNode* root,int target, vector<int> path, vector<vector<int>>&ans) {
        if(root==nullptr)
            return;
        path.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr && root->val==target){
            ans.push_back(path);
            return;
        }
        solve(root->left,target-root->val,path,ans);
        solve(root->right,target-root->val,path,ans);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(root,targetSum,path,ans);
        return ans;
    }
};