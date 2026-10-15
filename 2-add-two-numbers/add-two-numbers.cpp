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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        ListNode* current=dummy;
        int sm=0,carry=0;
        while(l1!=nullptr||l2!=nullptr){
            int lv=l1!=nullptr?l1->val:0;
            int rv=l2!=nullptr?l2->val:0;
            sm=(lv+rv+carry)%10;
            carry=(lv+rv+carry)>9?1:0;
            current->next=new ListNode(sm);
            current=current->next;
            if(l1!=nullptr)l1=l1->next;
            if(l2!=nullptr)l2=l2->next;
        }
        if(carry>0)current->next=new ListNode(carry);
        return dummy->next;
    }
};