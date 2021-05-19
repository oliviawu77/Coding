
int removeElement(int* nums, int numsSize, int val){
    int replace_offset = 0;
    size_t i = 0;
    while (i < numsSize){
        if(*(nums+i) == val)
            replace_offset--;
        else{
            *(nums+i+replace_offset) = *(nums+i);
        }
        i++;
    }
    return numsSize+replace_offset;
}
