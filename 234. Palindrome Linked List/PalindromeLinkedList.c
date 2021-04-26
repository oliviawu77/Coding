/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct Node{
    int data;
    struct Node *next;
    struct Node *pre;
};

typedef struct Node NODE;
typedef struct Node *NODEPtr;

typedef struct ListNode *ListNodePtr;
bool isPalindrome(ListNodePtr head){

    int counter = 0;

    ListNodePtr current;
    current = head;
    NODEPtr head_new, current_new, previous, tail;
    head_new = (NODEPtr)malloc(sizeof(NODE));
    current_new = head_new;
    previous = head_new;

    head_new->data = head->val;
    head_new->next = NULL;
    head_new->pre = NULL;
    tail = current_new;
    counter = 1;

    while(current->next != NULL){
        current = current->next;
        current_new->next = (NODEPtr)malloc(sizeof(NODE));
        current_new = current_new->next;

        current_new->data = current->val;
        current_new->next = NULL;
        current_new->pre = previous;

        tail = current_new;
        previous = current_new;
        counter++;
        printf("list:%d\n",current_new->data);
    }

    NODEPtr Current_Forward, Current_Backward;
    Current_Forward = head_new;
    Current_Backward = tail;
    for(size_t i = 0; i < counter/2; i++){
        if (Current_Forward->data != Current_Backward->data){
            return 0;
        }
        Current_Forward = Current_Forward -> next;
        Current_Backward = Current_Backward -> pre;
    }


    while(tail -> pre != NULL){
        NODEPtr cur = tail;
        tail = tail->pre;
        free(cur);
        cur = NULL;
    }

    return 1;
}
