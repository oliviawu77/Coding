/***檢討:***/
//1. 善用 strlen()函式
//2. 試著不要建立另外的數字陣列來處理和儲存
//3. 善用 realloc
/**********/
#define Maximum 1000

char * addBinary(char * a, char * b){
    int size_a = 0, size_b = 0, size_ans = 0;
    int *list_a = (int*)malloc(Maximum*sizeof(int));
    int *list_b = (int*)malloc(Maximum*sizeof(int));

    while(a[size_a] != '\0'){
        list_a[size_a] = (a[size_a] == '1'?1:0);
        size_a++;
    }
    while(b[size_b] != '\0'){
        list_b[size_b] = (b[size_b] == '1'?1:0);
        size_b++;
    }

    int* ans_num = (int*)malloc(Maximum*sizeof(int));

    int index_a = size_a - 1, index_b = size_b - 1, index_ans = 0;

    int carry = 0;
    while(index_a != -1 && index_b != -1){
        ans_num[index_ans] = list_a[index_a] ^ list_b[index_b] ^ carry;
        carry = (list_a[index_a] & list_b[index_b]) | (list_a[index_a] & carry) | (carry & list_b[index_b]);
        index_ans++;
        index_a--;
        index_b--;
    }
    while(index_a != -1){
        ans_num[index_ans] = list_a[index_a] ^  carry;
        carry = (list_a[index_a] & carry);
        index_ans++;
        index_a--;
    }
    while(index_b != -1){
        ans_num[index_ans] = list_b[index_b] ^ carry;
        carry = (carry & list_b[index_b]);
        index_ans++;
        index_b--;
    }
    if(carry){
        ans_num[index_ans] = carry;
        size_ans = index_ans + 1;
    }
    else{
        size_ans = index_ans;
    }

    char *ansList = (char*)malloc((size_ans+1) * sizeof(char));
    int ptr;
    for(ptr = 0; ptr < size_ans; ptr++){
        ansList[ptr] = (ans_num[size_ans - ptr - 1] == 1?'1':'0');
    }
    ansList[ptr] = '\0';

    free(list_a);
    free(list_b);
    free(ans_num);
    return ansList;
}
