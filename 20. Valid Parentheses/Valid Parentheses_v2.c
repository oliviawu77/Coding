
//open brackets are producers
//close brackets are consumers

//create a linked list to record producers type
struct list{
    int data;
    struct list *next;
    struct list *pre;
};

typedef struct list List;
typedef List *ListPtr;

bool isValid(char * s){
    size_t i = 0;

    ListPtr producer_types = NULL;

    ListPtr previous = producer_types;

    while(*(s+i) != '\0'){
        printf("%c\n",*(s+i));
        if (*(s+i) == ')' || *(s+i) == '}' || *(s+i) == ']'){ // consumer is detected
            if(producer_types == NULL){ //no producer
                    return false;
            }
            switch (*(s+i)){ //check whether the last producer is corresponding to the consumer
                case ')':
                    if(producer_types->data == 1){
                        producer_types = producer_types->pre;
                    }
                    else{
                        return false;
                    }
                    break;
                case '}':
                     if(producer_types->data == 2){
                        producer_types = producer_types->pre;
                    }
                    else{
                        return false;
                    }
                    break;
                case ']':
                    if(producer_types->data == 3){
                        producer_types = producer_types->pre;
                    }
                    else{
                        return false;
                    }
                    break;
                default:
                    break;
            }
        }
        else{ // producer (or others) is detected
            if(producer_types == NULL){ //there is no producer
                producer_types = (ListPtr)malloc(sizeof(List));
                producer_types->pre = NULL;
            }
            else{ //there are some producers
                producer_types->next = (ListPtr)malloc(sizeof(List));
                previous = producer_types;
                producer_types = producer_types->next;
                producer_types->pre = previous;
            }
            producer_types->next = NULL;
            switch(*(s+i)){
                case '(':
                    producer_types->data = 1;
                    break;
                case '{':
                    producer_types->data = 2;
                    break;
                case '[':
                    producer_types->data = 3;
                    break;
                default:
                    return false;
                }
        }

        i++;
    }


    return producer_types == NULL?true:false;
}
