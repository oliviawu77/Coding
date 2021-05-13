/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode NODE;
typedef NODE *NodePtr;

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    NodePtr result = (NodePtr)malloc(sizeof(NODE));
    NodePtr cur = result;
    cur->next = NULL;
    if (l1 == NULL && l2 == NULL){ //l1 and l2 are NULL
        result = NULL;
        return result;
    }
    else if(l1 == NULL){ //l1 or l2 are NULL
        cur->val = l2->val;
        l2 = l2->next;
    }
    else if(l2 == NULL){
        cur->val = l1->val;
        l1 = l1->next;
    }
    else if(l1->val >= l2->val){ //l1 and l2 are not NULL
        cur->val = l2->val;
        l2 = l2->next;
    }
    else{
        cur->val = l1->val;
        l1 = l1->next;
    }

     while (l1 != NULL || l2 != NULL){
        while(l1 == NULL){ //l1 reaches its end
            while(l2 != NULL){
                cur->next = (NodePtr)malloc(sizeof(NODE));
                cur = cur->next;
                cur->val = l2->val;
                cur->next = NULL;
                l2 = l2->next;
            }
            return result;
        }
        while(l2 == NULL){ //l2 reaches its end
            while(l1 != NULL){
                cur->next = (NodePtr)malloc(sizeof(NODE));
                cur = cur->next;
                cur->val = l1->val;
                cur->next = NULL;
                l1 = l1->next;
            }
            return result;
        }

        cur->next = (NodePtr)malloc(sizeof(NODE));
        cur = cur->next;

        if(l1->val >= l2->val){
            cur->val = l2->val;
            l2 = l2->next;
        }
        else{
            cur->val = l1->val;
            l1 = l1->next;
        }
        cur->next = NULL;
    }



     return result;
}
