#include <stdio.h>
#include <stdlib.h>


int isMatch(char * s, char * p)
{
    int forward = 1;
    int flagForward = 0;

    if (*p == 0)
    {
        return *s == 0;
    }
    
    if (*(p+1) == '*')
    {
        forward = 0;
        if (isMatch(s, p+2))
        {
            return 1;
        }
    }
    
    if (*s && *p == '.' || *p == *s)
    {
        return isMatch(s+1, p+forward) || flagForward;
    }
    return 0;
}


int main()
{
    char* s = "aa";
    char* p = ".*a*";
    printf("%d\n", isMatch(s, p));
    return 0;
}