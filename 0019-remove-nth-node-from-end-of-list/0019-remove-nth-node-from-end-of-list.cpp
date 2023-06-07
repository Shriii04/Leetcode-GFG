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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* p=head;
    ListNode* q=head;
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    int m = count-n;
    if(m==0){
        p=head;
        head=head->next;
    }
    else{
        p=head;
        for(int i=0;i<m;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
    }
    return head;
    }
};