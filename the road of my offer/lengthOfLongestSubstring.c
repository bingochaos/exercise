int lengthOfLongestSubstring(char* s) {
     int len = 0;
    char *end = s,*temp;
    char* addressTable[128] = {NULL};//字符转int
    while(*end){
        temp = addressTable[*end];
        addressTable[*end] = end;
        if(temp >= s){
        len = end - s > len ? end - s : len;
        s = temp + 1;
        }
        end++;
    }
    len = end - s > len ? end - s : len;
    return len;
}

int lengthOfLongestSubstring(char* s) {
    int min = 0;
    int i = 0;
    int start = 0;
    char *tmp = s;
    int first = 0;
    while(*tmp++ != '\0')
    {
        i++;
        for(int j = start; j < i; j++)
        {
            if(s[i] == s[j])
            {
                if(first == 0){
                    min = (j + 1) > (i - start) ? (j + 1) : (i - start);
                    first = 1;
                } else if(min < (i - start))
                {
                    min = i - start;
                }
                start = j + 1;
            }
        }
    }
    if((i - start) > min)
    return i - start ;
    
    return min;
}