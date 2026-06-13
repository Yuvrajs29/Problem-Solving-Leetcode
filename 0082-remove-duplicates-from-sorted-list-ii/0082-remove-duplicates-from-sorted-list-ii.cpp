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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* nxt= curr->next;
            bool flag=false;
            while(nxt!=nullptr && curr->val == nxt->val){
                nxt = nxt->next;
                flag=true;
            }
            if(flag==true){
                if(prev==nullptr)
                    head=nxt;
                else
                    prev->next = nxt;
            }
            else{
                prev = curr;
            }
            curr=nxt;
        }
        return head;
    }
};