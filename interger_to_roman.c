
#include <stdio.h>
#include <stdlib.h>

char * intToRoman(int num)
{
    int nTemp = 0;
    int nCarry = 1;
    int nLen = 0;
    char wTemp;
    char* sContainer  = calloc(500, sizeof(char));
    char* sCursor = sContainer;

    while (num != 0)
    {
        nTemp = num % 10 * nCarry;
        num /= 10;
        nCarry *= 10;

        // Special cases first:
        if (nTemp == 4)
        {
            *sCursor++ = 'V';
            *sCursor++ = 'I';
            nLen += 2;
        }
        else if (nTemp == 9)
        {
            *sCursor++ = 'X';
            *sCursor++ = 'I';
            nLen += 2;
        }
        else if (nTemp == 40)
        {
            *sCursor++ = 'L';
            *sCursor++ = 'X';
            nLen += 2;
        }
        else if (nTemp == 90)
        {
            *sCursor++ = 'C';
            *sCursor++ = 'X';
            nLen += 2;
        }
        else if (nTemp == 400)
        {
            *sCursor++ = 'D';
            *sCursor++ = 'C';
            nLen += 2;
        }
        else if (nTemp == 900)
        {
            *sCursor++ = 'M';
            *sCursor++ = 'C';
            nLen += 2;
        }
        
        // Then normal cases:
        else if (nTemp >= 1 && nTemp < 5)
        {
            for (int i = 0; i < nTemp; i++)
            {
                *sCursor = 'I';
                sCursor++;
                nLen++;
            }
        }
        else if (nTemp >= 5 && nTemp < 10)
        {
            for (int i = 0; i < nTemp - 5; i++)
            {
                *sCursor = 'I';
                sCursor++;
                nLen++;
            }
            *sCursor = 'V';
            sCursor++;
            nLen++;
        }
        else if (nTemp >= 10 && nTemp < 50)
        {
            for (int i = 10; i <= nTemp; i += 10)
            {
                *sCursor = 'X';
                sCursor++;
                nLen++;
            }
        }
        else if (nTemp >= 50 && nTemp < 100)
        {
            for (int i = 50; i < nTemp; i += 10)
            {
                *sCursor = 'X';
                sCursor++;
                nLen++;
            }
            *sCursor = 'L';
            sCursor++;
            nLen++;
        }
        else if (nTemp >= 100 && nTemp < 500)
        {
            for (int i = 100; i <= nTemp; i += 100)
            {
                *sCursor = 'C';
                sCursor++;
                nLen++;
            }
        }
        else if (nTemp >= 500 && nTemp <1000)
        {
            for (int i = 500; i < 1000; i += 100)
            {
                *sCursor = 'C';
                sCursor++;
                nLen++;
            }
            *sCursor = 'D';
            sCursor++;
            nLen++;
        }

        // Finally, numbers larger than 1000:
        else
        {
            for (int i = 1000; i <= nTemp; i += 1000)
            {
                *sCursor = 'M';
                sCursor++;
                nLen++;
            }
        }
    }
    
    sCursor--;
    printf("Container:%s, cursor:%s\n", sContainer,sCursor);
    
    for (int i = 0; i < nLen; i++)
    {
        wTemp = *sCursor;
        *sCursor = *(sContainer + i);
        *(sContainer + i) = wTemp;
        sCursor--;
        nLen--;
    }
    return sContainer;
}


int main()
{
    char * ans = intToRoman(69);
    printf("Ans:%s\n", ans);
    free(ans);
    return 0;
}