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
    int l3_val = 0;

    NodePtr l3 = (NodePtr)malloc(sizeof(NODE));

    l3->next = NULL;

    l3_val = l1->val + l2->val;
    l3->val = l3_val % 10;
    carry = l3_val / 10;

    NodePtr l3_current = l3;

    while(l1->next != NULL || l2->next != NULL || carry){

        l3_current->next = (NodePtr)malloc(sizeof(NODE));
        l3_current = l3_current->next;
        l3_current->next = NULL; //very important!!
        l3_current->val = 0;

        if (l1->next != NULL){
            l1 = l1->next;
            l3_current->val += l1->val;
        }

        if (l2->next != NULL){
            l2 = l2->next;
            l3_current->val += l2->val;
        }

        l3_current->val += carry;

        l3_val = l3_current->val;

        l3_current->val = l3_current->val % 10;
        carry = l3_val / 10;
        }

    return l3;
}
