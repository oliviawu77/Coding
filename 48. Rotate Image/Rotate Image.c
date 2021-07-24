void swap(int* a, int* b);
void up_to_right(int** matrix, int start, int end);
void right_to_bottom(int** matrix, int start, int end);
void bottom_to_left(int** matrix, int start, int end);

static int tmp = 0;
static int swap_t = 0;
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int end = matrixSize - 2;
    int start = 0;
    for(start = 0; start <= end; start++){
        printf("%d, %d\n",start, end);
        up_to_right(matrix, start, end);
        right_to_bottom(matrix, start, end);
        bottom_to_left(matrix, start, end);      
        end--;
    }
}

void swap(int* a, int* b){
    swap_t = *a;
    *a = *b;
    *b = swap_t;
}

void up_to_right(int** matrix, int start, int end){
    for(size_t i = 0; start + i <= end; i++){
        swap(&matrix[start][start + i], &matrix[start + i][end + 1]);
    }
}
void right_to_bottom(int** matrix, int start, int end){
    for(size_t i = 0; start + i <= end; i++){
        swap(&matrix[start][start + i], &matrix[end + 1][end - i + 1]);
    }
}
void bottom_to_left(int** matrix, int start, int end){
    for(size_t i = 0; start + i <= end; i++){
        swap(&matrix[start][start + i], &matrix[end - i + 1][start]);
    }    
}
