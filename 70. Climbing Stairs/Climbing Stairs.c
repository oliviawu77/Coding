
int climbStairs(int n){
    if (n <= 2){
        return n;
    }
    int number = 0;
    int n_1 = 2;
    int n_2 = 1;
    for(int i = 3; i <= n; i++){
        number = n_1 + n_2;
        n_2 = n_1;
        n_1 = number;
    }
    return number;
}

