/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* findMid(ListNode *st, ListNode *end){
        ListNode *slow=st, *fast=st;
        while(fast!=end && fast->next!=end){
            slow= slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    TreeNode* listtoTree(ListNode* st,ListNode* end){
        if(st==end)
            return nullptr;
        ListNode*mid= findMid(st,end);
        TreeNode*root = new TreeNode(mid->val);
        root->left= listtoTree(st,mid);
        root->right= listtoTree(mid->next,end);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return listtoTree(head,nullptr);
    }
};