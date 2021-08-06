int fib(int n){
    if (n < 2){
        return n;
    }
    int number = 0;
    int n_0 = 0;
    int n_1 = 1;
    for(int i = 2; i <= n; i++){
        number = n_0 + n_1;
        n_0 = n_1;
        n_1 = number;
    }
    return number;
}