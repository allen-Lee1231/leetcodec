//@Author Allen Li  10/19/2019
#include <stdio.h>
#include <stdlib.h>

/*Given a string containing digits from 2-9 inclusive, 
return all possible letter combinations that the number could represent.
Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

https://leetcode.com/problems/letter-combinations-of-a-phone-number/solution/ */


int positivePow(int num, int p)
{
    while (p > 0)
    {
        num *= num;
        p --;
    }
    return num;
}

int strLen(char* sz)
{
    //count input length
    int nDigitLen = 0;
    while (*sz != 0)
    {
        nDigitLen++;
        sz++;
    }
    return nDigitLen;
}

int ctoi(char c)
{
    int nBuffer;
    nBuffer = c - '0';
    if (nBuffer < 0 || nBuffer > 9)
    {
        printf("Wrong char: %c, nBuffer: %d\n", c, nBuffer);
        return -1;
    }
    return nBuffer;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int * returnSize){
    if (digits == NULL || *digits == 0)
    {
        *returnSize = 0;
        return 0;
    }
    
    //the only hard-code part
    char *apb[9] = {0, "abc", "def",
                    "ghi", "jkl", "mno",
                    "pqrs", "tuv", "wxyz"
                    };

    //initialize answer container
    int nIdx0 = 1;
    int nIdx1 = strLen(digits);
    int nTemp;
    for (char* pTemp=digits; *pTemp!=0; pTemp++)
    {
        nTemp = ctoi(*pTemp) - 1;
        nIdx0 *= strLen(apb[nTemp]);
    }

    char **ppContainer = (char**) malloc(sizeof(char*) * nIdx0);
    for (int i=0; i<nIdx0; i++)
    {
        ppContainer[i] = (char*) calloc(sizeof(char), nIdx1 + 1);
    }
    
    //begin mapping
    int nApbStrLen;
    int nDuplicate = nIdx0;
    int nCursor = 0;
    int nLayer = 0;
    int nEnd;
    while (*digits != 0)
    {   
        nTemp = ctoi(*digits) - 1;
        nApbStrLen = strLen(apb[nTemp]);
        nDuplicate /= nApbStrLen;
        nEnd = nDuplicate;

        while (nEnd < nIdx0)
        {
            for (int i=0; i<nApbStrLen; i++)
            {
                while (nCursor < nEnd)
                {
                    ppContainer[nCursor][nLayer] = apb[nTemp][i];
                    nCursor++;
                }
                nEnd += nDuplicate;
            }
        }
        digits++;
        nLayer++;
        nCursor = 0;
    }
    *returnSize = nIdx0;

    //uncomment to printf what's inside the container
    /**/
    for (int i=0; i<nIdx0; i++)
    {
        printf("Container[%d] %s\n", i, ppContainer[i]);
    }
    /**/
    return ppContainer;
}


int main()
{
    char *sTest = "239";
    int returnSize;
    char **_ = letterCombinations(sTest, &returnSize);
    return 0;
}