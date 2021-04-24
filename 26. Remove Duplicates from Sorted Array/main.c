#include <stdio.h>
#include <stdlib.h>

#define SKIP 1

int removeDuplicates(int* nums, int numsSize){
    int counter = 0;
    int offset = 0;
    int i = 0;
    int target = 0;

    if(numsSize <= 1){
        return numsSize;
    }

    while (i < numsSize){
        target = *(nums+i);
        offset = same_number(nums, i+1, target, numsSize);
        *(nums+counter) = *(nums+i);
        counter++;
        if(offset == 0){  // there is 2 situation that will fall into this condition.
            break;        // 1. the last number is a different number .
        }                 // 2. the last number not a different number (which means it have to be removed).
        i = i + offset;
    }

    if(*(nums+i) == *(nums+counter-2)){ //if the 2. happens, it means the counter should decrease one
        counter--;
    }

    return counter;
}

int same_number(int *nums, int current, int target, int numsSize){
    if(current >= numsSize){ //the travesal exceed the range of the array
        return 0;
    }
    return *(nums+current)!=target?1:(SKIP+same_number(nums, current+1, target, numsSize));
}

int main(){
    int a[10] = {0,0,1,1,1,2,2,3,3,4};
    int numsSize = 10;

    int count = removeDuplicates(a,numsSize);

    return 0;
}
