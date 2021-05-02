
//open brackets are producers
//close brackets are consumers

bool isValid(char * s){
    size_t i = 0;
    int type_1_valid = 0;
    int type_2_valid = 0;
    int type_3_valid = 0;
    int last_type[10000];
    for(i = 0; i < 10000; i++){
        last_type[i] = 0;
    }
    int last_type_counter = 0;
    i = 0;

    while(*(s+i) != '\0'){
        switch (*(s+i)){
            case '(':
                type_1_valid++;
                last_type[last_type_counter] = 1;
                last_type_counter++;
                break;
            case '{':
                type_2_valid++;
                last_type[last_type_counter] = 2;
                last_type_counter++;
                break;
            case '[':
                type_3_valid++;
                last_type[last_type_counter] = 3;
                last_type_counter++;
                break;
            case ')':
                if (type_1_valid == 0){
                    return false;
                }
                if (last_type[last_type_counter-1] == 1){
                    type_1_valid--;
                    last_type_counter--;
                }
                else{
                    return false;
                }
                break;
            case '}':
                if (type_2_valid == 0){
                    return false;
                }
                if (last_type[last_type_counter-1] == 2){
                    type_2_valid--;
                    last_type_counter--;
                }
                else{
                    return false;
                }
                break;
            case ']':
                if (type_3_valid == 0){
                    return false;
                }
                if (last_type[last_type_counter-1] == 3){
                    type_3_valid--;
                    last_type_counter--;
                }
                else{
                    return false;
                }
                break;
        }
        i++;
    }

    return type_1_valid == 0 && type_2_valid == 0 && type_3_valid == 0?true:false;
}
