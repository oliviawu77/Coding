

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize){
    int* nums_array = (int*)malloc(1000* sizeof(int));
    int digit = 0;
    int remain_digit = 0;
    int flag = 1;
    int size = 0;
    for(int i = left; i <= right; i++){
        flag = 1;
        remain_digit = i;
        while( remain_digit != 0){
            digit = remain_digit % 10;
            if(digit == 0){
                flag = 0;
                break;
            }
            if(i % digit != 0){
                flag = 0;
                break;
            }
            remain_digit = remain_digit / 10;
        }
        if(flag == 1){
            nums_array[size] = i;
            size++;
            printf("%d\n", i);
        }
    }
    *returnSize = size;
    return nums_array;
}