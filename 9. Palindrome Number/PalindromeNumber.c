struct Node{
    int data;
    struct Node *next;
    struct Node *pre;
};

typedef struct Node NODE;
typedef struct Node *NODEPtr;

// traverse the array forward, then travese the array backward

bool isPalindrome(int x){
    bool equal = 1;
    if(x < 0){
        return !equal;
    }
    int counter = 0;
    NODEPtr head, current, previous, tail;
    head = (NODEPtr)malloc(sizeof(NODE));
    current = head;
    previous = head;

    head->data = x % 10;
    head->next = NULL;
    head->pre = NULL;
    tail = current;
    counter = 1;
    x = x / 10;
    //create the linked list
    while(x){
        //malloc new space, and updata pointer current
        current->next = (NODEPtr)malloc(sizeof(NODE));
        current = current->next;
        //setup current element's each field
        current->data = x % 10 ;
        current->next = NULL;
        current->pre = previous;
        //setup the tail
        tail = current;
        //update pointer previous to current
        previous = current;
        //update the value
        x = x / 10;
        //update the counter
        counter++;
    }

    NODEPtr Current_Forward, Current_Backward;
    Current_Forward = head;
    Current_Backward = tail;
    for(size_t i = 0; i < counter/2; i++){
        if (Current_Forward->data != Current_Backward->data){
        while(tail -> pre != NULL){
            NODEPtr cur = tail;
            tail = tail->pre;
            free(cur);
            cur = NULL;
        }
            return !equal;
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


    return equal;
}
