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
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(l1==nullptr)
            return l2;
        if(l2==nullptr)
            return l1;
        if(l1->val < l2->val){
            l1->next = merge(l1->next,l2);
            return l1;
    }
        else {
            l2->next = merge(l1,l2->next);
            return l2;
        }

    }
    ListNode* mergesort(vector<ListNode*>& arr, int low ,int high){
        if(low==high){
            return arr[low];
        }
        int mid= low+(high-low)/2;
        ListNode* list1=mergesort(arr,low,mid);
        ListNode* list2=mergesort(arr,mid+1,high);
        return merge(list1,list2);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return nullptr;
        if(lists.size()==1)
            return lists[0];
        return mergesort(lists,0,lists.size()-1);
    }
};