char * longestCommonPrefix(char ** strs, int strsSize){
    size_t counter = 0;
    size_t i,j = 0;
    size_t stop = 0;

    while (*(*(strs+0)+j) != '\0'){
        for(i = 0; i < strsSize; i++){
            if(*(*(strs+0)+j) != *(*(strs+i)+j)){
                stop = 1;
                break;
            }
        }
        if (stop == 1){
            break;
        }
        printf("%c\n",*(*(strs+0)+j));
        j++;
    }

    char* result = (char*)malloc((j+1) * sizeof(char));

    for(i = 0;i < j; i++){
        *(result+i) = *(*(strs+0)+i);
    }
    *(result+j)='\0';

    return result;
}
