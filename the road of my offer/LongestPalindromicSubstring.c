char* longestPalindrome(char* s) {
    char *p = s;
    int index = 0;
    int maxlen = 0;
    int i = 1;
    char *maxindex = s;
    while (*s != '\0')
    {
        i = 1;
        p = s;
        if(*p == *(p+1))//中间相同
        {
            while(*(p-i+1) == *(p+i) && *(p+i) != '\0' && i <= index+1)
            {

              if(maxlen < 2*i)
              {
                 maxlen = 2*i ;
                 maxindex = p - i + 1 ;
               }i++;
            }
        }
        i = 1;
        if(*(p-1) == *(p+1))//中间不同
        {
            while(*(p-i) == *(p+i) && *(p+i) != '\0' && i <= index+1)
            {

                if(maxlen < 2*i + 1)
                {
                    maxlen = 2*i + 1;
                    maxindex = p - i  ;
                }i++;
            }
        }
        index++;
        s++;
    }
    char *result = (char *)malloc(1001*sizeof(char));
    char *tmp = result;
    if(maxlen == 0)
    {
        maxlen = 1;
    }
    for(int j = 0; j < maxlen; j++)
    {
        *(tmp++) = *(maxindex++);
    }
    *tmp = '\0';

    return result;
}