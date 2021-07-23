

int searchInsert(int* nums, int numsSize, int target){
    int start = 0;
    int end = numsSize-1;
    int middle = (start+end) / 2;
    int index = 0;

    if(target == *(nums + middle)){
        index = middle;
        return index;
    }

    if(target < *(nums + middle)){ //target may in the left list
        end = middle - 1;
        index = BinarySearch(nums, start, end, target);
    }
    else if(target > *(nums + middle)){ //target may in the right list
        start = middle + 1;
        index = BinarySearch(nums, start, end, target);
    }
    
    return index;
}

int BinarySearch(int *nums, int start, int end, int target){
    int index = 0;
    int middle = (start + end)/ 2;
    
    if(end < start){
        index = start;
        return index;
    }
    
    if(target == *(nums + middle)){
        index = middle;
        return index;
    }

    if(target < *(nums + middle)){ //target may in the left list
        end = middle - 1;
        index = BinarySearch(nums, start, end, target);
    }
    else if(target > *(nums + middle)){ //target may in the right list
        start = middle + 1;
        index = BinarySearch(nums, start, end, target);
    }
    
    return index;
}