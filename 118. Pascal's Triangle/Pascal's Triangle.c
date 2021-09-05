



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int** pascal_tri = (int**) malloc(sizeof(int*) * numRows);
    int i = 0;
    int j = 0;
    
    *returnColumnSizes = (int*) malloc(sizeof(int) * numRows);
    *returnSize = numRows;
    
    //row 1
    (*returnColumnSizes)[i] = i + 1;
    pascal_tri[i] = (int*) malloc(sizeof(int) * (i + 1));
    pascal_tri[i][j] = 1;
    i++;
    //other rows
    for(i; i < numRows; i++){
        
        (*returnColumnSizes)[i] = i + 1; 
        pascal_tri[i] = (int*) malloc(sizeof(int) * (i + 1));
        j = 0;
        pascal_tri[i][j] = 1;
        j++;
    
        for(j; j < i; j++){
            pascal_tri[i][j] = pascal_tri[i-1][j-1] + pascal_tri[i-1][j];
        }
        
        pascal_tri[i][j] = 1;        
    }

    return pascal_tri;
}