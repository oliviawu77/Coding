#define max_lenght 200

char * longestCommonPrefix(char ** strs, int strsSize){
    size_t i,j = 0;
    char* result = (char*)malloc((max_lenght+1) * sizeof(char));

    while (*(*(strs+0)+j) != '\0'){
        for(i = 0; i < strsSize; i++){
            if(*(*(strs+0)+j) != *(*(strs+i)+j)){
                *(result+j)='\0';
                return result;
            }
        }
        *(result+j) = *(*(strs+0)+j);
        j++;
    }
    *(result+j)='\0';
    return result;
}
