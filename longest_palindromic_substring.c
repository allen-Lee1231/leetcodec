#include <string.h>
#include <stdio.h>

// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.


char * longestPalindrome(char * s){
    if (s==NULL || *s=='\0' || *(s+1)=='\0') return s;
    if (*(s + 2) == '\0' && s[0] == s[1]) return s;
    
    char *container = (char*) calloc(1001, sizeof(char));
    char* p = s, *end = s;
    int len = 0, offset = 1, border = 0, left = 0, max = 1, ext = 1;
    while (*end++ != '\0') len++;
    end--;
    while (p != end-1){
        while (offset <= border && *(p - offset) == *(p+offset)){
            if (offset == 1) ext = 1;
            ext += 2;
            offset++;
        }
        if (max < ext) {
            memcpy(container, p - offset + 1, ext);
            max = ext;
        }
        offset = 1, ext = 1;
        while (offset <= border && *(p - offset) == *(p + offset - 1)){
            if (offset == 1) ext = 0;
            ext += 2;
            offset++;
        }
        if (max < ext) {
            memcpy(container, p - offset + 1, ext);
            max = ext;
        }
        offset = 1, ext = 1;
        while (offset <= border && *(p - offset + 1) == *(p + offset)){
            if (offset == 1) ext = 0;
            ext += 2;
            offset++;
        }
        if (max < ext) {
            memcpy(container, p - offset + 2, ext);
            max = ext;
        }
        offset = 1, ext = 1;
        p++;
        left++;
        (left * 2 > len)? (border = len - left): (border = left);
    }
    
    if (max == 1) memcpy(container, s, 1);
    return container;
}


int main(){
    char test[1000] = {0};
    strcpy(test, "acbabcba");
    char *output = longestPalindrome(test);
    printf("ans: %s\n", output);
    free(output);
    return 0;
}