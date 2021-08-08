#define max(a,b)(a>b?a:b)
#define min(a,b)(a>b?b:a)

char* decimal_to_binary(int n);

char* decimal_to_binary(int n){
    char* digit = (char*)malloc(sizeof(char));
    digit[0] = '\0';
    int number = n;
    int size = 1;
    while (number != 0){
        digit = (char*)realloc(digit, (size+1) * sizeof(char));
        digit[size-1] = number % 2 == 0 ? '0' : '1';
        digit[size] = '\0';
        number = number / 2;
        size++;
    }
    
    return digit;
}
int hammingDistance(int x, int y){
    char* x_binary = decimal_to_binary(x);
    char* y_binary = decimal_to_binary(y);
    int hd = 0;
    int i = 0;
    for(i = 0; i < min(strlen(x_binary),strlen(y_binary)); i++){
        hd += x_binary[i] ^ y_binary[i];
    }
    char t0, t1;
    for(i = min(strlen(x_binary),strlen(y_binary)); i < max(strlen(x_binary),strlen(y_binary)); i++){
        t0 = (i < strlen(x_binary)? x_binary[i] : '0');
        t1 = (i < strlen(y_binary)? y_binary[i] : '0');
        hd += t0 ^ t1;
    }
    free(x_binary);
    free(y_binary);
    
    return hd;
}