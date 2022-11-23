int strStr(char * haystack, char * needle){
    int index = 0;
    int isMatch = 0;
    while(haystack[index] != '\0') {
        int offset = 0;
        isMatch = 0;
        while(needle[offset] != '\0') {
            char current = haystack[index + offset];
            if(current != '\0' && current == needle[offset]) {
                offset++;
                isMatch = 1;
            }
            else {
                isMatch = 0;
                break;
            }
        }
        if(isMatch == 1) {
            return index;
        }
        index++;
    }
    return -1;
}