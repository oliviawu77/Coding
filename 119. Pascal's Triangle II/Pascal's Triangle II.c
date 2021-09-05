

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex + 1;
    
    int* result = (int*) malloc((rowIndex + 1) * sizeof(int));
    
    result[0] = 1;
    result[rowIndex] = 1;
    
    if (rowIndex <= 1){
        return result;
    }
    
    int** tmp_result = (int**) malloc((rowIndex) * sizeof(int*));
    int row = 0;
    int col = 0;
    tmp_result[row] = (int*) malloc((row + 1) * sizeof(int));
    
    tmp_result[col][col] = 1;
    
    
    for(row = 1; row < rowIndex; row++){
        
        tmp_result[row] = (int*) malloc((row + 1) * sizeof(int));
        col = 0;
        
        tmp_result[row][col] = 1;
        tmp_result[row][row] = 1;
        
        col ++;
        
        for(col; col < row; col++){
            tmp_result[row][col] = tmp_result[row - 1][col - 1] + tmp_result[row - 1][col];
        }
        
    }

    for(col = 1; col < row; col++){
         result[col] = tmp_result[row - 1][col - 1] + tmp_result[row - 1][col];
    }
    
    return result;
}
