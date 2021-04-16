#include<stdio.h>
#include<stdlib.h>

int* twoSum(int* nums, int numsSize, int target){
    int* tmp = NULL;
    tmp = (int*)malloc(2 * sizeof(int));

    for(size_t i = 0; i < numsSize/2; i++){
        for(size_t j = i; j < numsSize; j++){
            if((nums[i] + nums[j]) == target){
                tmp[0] = i;
                tmp[1] = j;
                return tmp;
            }
        }
    }
    return 0;
}

int main(){
    int input[] = {2,9,11,15};
    int* answer = twoSum(input, 4, 20);
    printf("%d,%d\n",*(answer+0),*(answer+1));
    return 0;
}
