#include<stdio.h>
#include<stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
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
    int input[] = {5,33,99,125,444,25,3049,94983,3094958,38994,75,39291,-1,-2,-3,-4,-5,-6,-7,-8,50,199};
    int target = 75;
    int *returnSize;
    int* answer = twoSum(input, 22, target, &returnSize);
    printf("answer:%d,%d\n",*(answer+0),*(answer+1));
    return 0;
}
