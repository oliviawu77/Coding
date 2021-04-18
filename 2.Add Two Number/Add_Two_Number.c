/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode NODE;
typedef NODE *NodePtr;

NodePtr addTwoNumbers(NodePtr l1, NodePtr l2){
    int carry = 0;

    NodePtr l3 = (NodePtr)malloc(sizeof(NODE));
    assert(l3 != NULL);

    l3->next = NULL;
    if(l1->val + l2->val < 10){
        l3->val = l1->val + l2->val;
        carry = 0;
    }
    else{
        l3->val = (l1->val + l2->val)%10;
        carry = 1;
    }

    NodePtr l1_current = l1;
    NodePtr l2_current = l2;
    NodePtr l3_current = l3;

    int l1_val, l2_val;

    while(l1_current->next != NULL || l2_current->next != NULL || carry == 1){

        l3_current->next = (NodePtr)malloc(sizeof(NODE));
        l3_current = l3_current->next;
        l3_current->next = NULL; //very important!!

        if (l1_current->next != NULL){
            l1_current = l1_current->next;
            l1_val = l1_current->val;
        }
        else{
            l1_val = 0;
        }

        if (l2_current->next != NULL){
            l2_current = l2_current->next;
            l2_val = l2_current->val;
        }
        else{
            l2_val = 0;
        }

        if(l1_val + l2_val + carry < 10){
            l3_current->val = l1_val + l2_val + carry;
            carry = 0;
        }
        else{
            l3_current->val = (l2_val + l1_val + carry)%10;
            carry = 1;
        }

    }
    return l3;
}
