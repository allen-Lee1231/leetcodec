#include <stdio.h>


int romanToInt(char * s){
    char* pCursor = s;
    int nAns = 0;
    int nLen = 0;
    while (*pCursor != 0)
    {
        nLen++;
        pCursor++;
    }
    pCursor = s;
    
    while (nLen > 0)
    {
        // Special cases first:
        if (*pCursor == 'I')
        {
            if (nLen > 1 && *(pCursor + 1) == 'V')
            {
                nAns += 4;
                pCursor += 2;
                nLen -= 2;
            }
            else if (nLen > 1 && *(pCursor + 1) == 'X')
            {
                nAns += 9;
                pCursor += 2;
                nLen -= 2;
            }
            else
            {
                nAns ++;
                pCursor++;
                nLen--;
            }
        }
        else if (*pCursor == 'X')
        {
            if (nLen > 1 && *(pCursor + 1) == 'L')
            {
                nAns += 40;
                pCursor += 2;
                nLen -= 2;
            }
            else if (nLen > 1 && *(pCursor + 1) == 'C')
            {
                nAns += 90;
                pCursor += 2;
                nLen -= 2;
            }
            else
            {
                nAns += 10;
                pCursor++;
                nLen--;
            }
        }
        else if (*pCursor == 'C')
        {   
            if (nLen > 1 && *(pCursor + 1) == 'D')
            {
                nAns += 400;
                pCursor += 2;
                nLen -= 2;
            }
            else if (nLen > 1 && *(pCursor + 1) == 'M')
            {
                nAns += 900;
                pCursor += 2;
                nLen -= 2;
            }
            else
            {
                nAns += 100;
                pCursor++;
                nLen --;
            }
        }

        // Now normal cases:
        else if (*pCursor == 'V')
        {
            nAns += 5;
            pCursor++;
            nLen --;
        }
        else if (*pCursor == 'L')
        {
            nAns += 50;
            pCursor++;
            nLen --;
        }
        else if (*pCursor == 'D')
        {
            nAns += 500;
            pCursor++;
            nLen --;
        }
            else if (*pCursor == 'M')
        {
            nAns += 1000;
            pCursor++;
            nLen --;
        }
    }
    return nAns;
}   


int main()
{
    char* szRoman = "MCMXCIV";
    printf("Roman: %s\nTo int: %d\n", szRoman, romanToInt(szRoman));
    return 0;
}