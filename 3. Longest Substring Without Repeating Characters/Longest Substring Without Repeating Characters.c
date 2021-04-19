

int lengthOfLongestSubstring(char * s){
    size_t i = 0, j = 0;
    size_t counter = 0;
    size_t lenght = 0;

    if(*(s+i) == '\0'){ // s is null string
        return 0;
    }

    while(*(s+i) != '\0'){
        printf("Current Char:%c\n", *(s+i));

        //traverse current substring
        for(j = i - counter; j < i; j++){
            if(*(s+i) == *(s+j)){ //if same char is found is previous chars, then cut off the substring, and break current traversal
                printf("Same Char Found(%c)\n", *(s+i));
                counter = i - j ; //reset counter
                break;
            }
            else{ // different char is found.
                printf("%c Found\n", *(s+j));
            }
        }

        if (j == i){ // the traversal is completed.
            counter++;
        }

        if (lenght < counter){ // if longer lenght is found, then update the lenght.
            lenght = counter;
        }

        printf("Current Counter:%d\n", counter);
        printf("Current Lenght:%d\n", lenght);
        i++;
    }
    return lenght;
}
