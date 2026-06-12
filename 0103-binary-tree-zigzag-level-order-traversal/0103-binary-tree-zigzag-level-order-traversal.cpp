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
    int height(TreeNode *root){
        if(root==nullptr)
            return 0;
        return max(height(root->left),height(root->right)) + 1;
    }
    void rightToleft(TreeNode* root, int level , vector<int> & temp){
        if(root==nullptr)
            return ;
        if(level==1){
            temp.push_back(root->val);
            return;
        }
        rightToleft(root->right,level-1,temp);
        rightToleft(root->left,level-1,temp);
    }
    void leftToright(TreeNode *root, int level, vector<int> & temp){
        if(root==nullptr)
            return;
        if(level==1){
            temp.push_back(root->val);
            return;
        }
        leftToright(root->left, level-1,temp);
        leftToright(root->right,level-1,temp);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int level = height(root);
        vector<vector<int>> ans;
        bool reverse = false;
        for(int i=1;i<= level;i++){
            vector<int> temp;
            if(reverse==false)
                leftToright(root,i,temp);
            else
                rightToleft(root,i,temp);
            reverse=!reverse;
            ans.push_back(temp);
        }
        
    return ans ;    
    }
    
};