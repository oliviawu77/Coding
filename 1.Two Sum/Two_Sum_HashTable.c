#include<stdio.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize=2;
    size_t i, j;

    int **Trav = (int**)malloc(10 * sizeof(int*)); //create a 2D travesal table
    //the pointer point to an array of ten arrays, and these arrays record data we have passed by
    //record rule: assume a data x, if x%10 = c (x / 10 = ?...c), then the data will be put in the array[c].
    //array[c] will store all data we have passed by which its remainder is c

    int *Trav_size = (int*)malloc(10 * sizeof(int)); //create an array to record each array's size

    int **Trav_Location = (int**)malloc(10 * sizeof(int*)); //create a 2D array to record elements's origin location


    //initialize
    for(i = 0; i < 10; i++){
        *(Trav+i) = (int*)malloc(numsSize * sizeof(int));
        *(Trav_Location+i) = (int*)malloc(numsSize * sizeof(int));
        *(Trav_size+i) = 0;
    }

    int* ans = (int*)malloc(2 * sizeof(int)); //the answer to return

    int obj_index = 0, obj = 0;

    for( i = 0; i < numsSize; i++){
        int loc = abs(nums[i]%10);
        *(*(Trav+loc)+*(Trav_size+loc)) = nums[i]; //record the data
        *(*(Trav_Location+loc)+*(Trav_size+loc)) = i; //record the data's position
        *(Trav_size+loc) = *(Trav_size+loc) + 1; //increment that array's size, because we just add one element to that array

        obj = target - nums[i]; // the objective we want to find
        obj_index = abs(obj%10); //the objective will locate is this array, or it not exist in the table

        printf("Objective:%d\n",obj);
        //traverse the array which the current objective may locate
        for(j = 0; j < *(Trav_size+obj_index); j++){
            if(*(*(Trav + obj_index)+j) == obj){ //objective is found
                if (i == *(*(Trav_Location + obj_index)+j)){ //if they are the same element, which means their origin position is the same
                    continue;
                }
                printf("%d found\n",*(*(Trav + obj_index)+j));
                ans[0] = *(*(Trav_Location + obj_index)+j); //the object's origin position
                ans[1] = i;

                //deallocate arrays
                for(i = 0; i < 10; i++){
                    free(*(Trav+i));
                    free(*(Trav_Location+i));
                }
                free(Trav);
                free(Trav_Location);
                free(Trav_size);
                return ans;
            }
        }
    }

    return ans;
}
int main(){
    int input[] = {5,33,99,125,444,25,3049,94983,3094958,38994,75,39291,-1,-2,-3,-4,-5,-6,-7,-8,50,199};
    int target = 75;
    int *returnSize;
    int* answer = twoSum(input, 22, target, &returnSize);
    printf("answer:%d,%d\n",*(answer+0),*(answer+1));
    return 0;
}
