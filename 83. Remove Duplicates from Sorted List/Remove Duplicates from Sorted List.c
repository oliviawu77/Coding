/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* pre = head;
    struct ListNode* cur = head;
    if(cur == NULL){
        return head;
    }
    while(cur->next!=NULL){
        printf("%d, %d\n",pre->val, cur->val);
        pre = cur;
        cur = cur->next;
        while (pre->val == cur->val){
            if(cur->next == NULL){
                break;
            }
            cur = cur->next;
        }
        pre->next = cur;
    }
    if(pre->val == cur->val){
        pre->next = NULL;
    }
    
    return head;
}