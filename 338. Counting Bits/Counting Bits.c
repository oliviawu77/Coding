#define min(a,b) (a<b?a:b)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
    *returnSize = n+1;
    int* result = (int*)malloc( (*returnSize) * sizeof(int) );
    memset(result, 0, (*returnSize) * sizeof(int));
    int j = 0;
    for(int i = 1; i < (*returnSize); i = i + j){
        for(j = 0; j < min(i,(*returnSize)-i); j++){
            result[i+j] = result[j]+1;
        }
    }
    return result;
}