int reverse(int x){
    long long number = x % 10; // because it have to deal with overflow number.
    while(x = x / 10){
        number = number * 10 + x % 10;
    }
    return (number>INT_MAX||number<INT_MIN)?0:number;
}
