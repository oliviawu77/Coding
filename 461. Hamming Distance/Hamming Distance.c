int hammingDistance(int x, int y){
    int result = x^y;
    int count = 0;
    for(int i = 0; i < 32; i++){
        count+=result%2;
        result = result >> 1;
    }
    return count;
}
