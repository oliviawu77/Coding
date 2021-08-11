/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int carry = 1; //plus 1
    int tmp = 0;
    for(int i = digitsSize-1; i >= 0; i--){
        tmp = digits[i] + carry;
        digits[i] = tmp % 10;
        carry = tmp / 10;
    }
    digitsSize = digitsSize + carry;
    *returnSize = digitsSize;
    if (carry){
        digits = (int*)realloc(digits, (digitsSize) * sizeof(int));
        memmove(digits+1, digits, (digitsSize-1) * sizeof(int));
        digits[0] = carry;
    }
    return digits;
}