//#include <stdio.h>
///*Without using Hashing map.
//  Runtime: 8 ms, faster than 70.97% of C online submissions for Longest Substring Without Repeating Characters.
//  Memory Usage: 7.8 MB, less than 12.12% of C online submissions for Longest Substring Without Repeating Characters.
//  */
//
//
//int lengthOfLongestSubstring(char * s){
//    char* cur = s;
//    int len = 0, max = 0, i = 0, l;
//    while (*(cur++)!='\0') len++;
//    if (!len) return 0;
//    if (len == 1) return 1;
//    if (len == 2){
//        if (s[0] == s[1]){
//            return 1;
//        }
//        else return 2;
//    }
//    //int container[3] = {0};
//    int *container = calloc(len, sizeof(int));
//    cur = s;
//
//    while (*s != '\0'){
//        cur = s;
//        l = 0;
//        while (*++cur != '\0'){
//            l++;
//            if (*cur == *s){
//                container[i] = l;
//                break;
//            }
//        }
//        if (*cur == '\0') container[i] = l+1;
//        //printf("container %d: %d\n", i, container[i]);
//        i++;
//        s++;
//    }
//    for (i = len-2; i >= 0; i--){
//        if (container[i] - container[i+1] > 1){
//            container[i] = container[i+1] + 1;
//        }
//    }
//
//    for (i = 0; i < len; i++){
//        if (max<container[i]) max = container[i];
//    }
//    free(container);
//    return max;
//}
//
//
//int main()
//{
//    char* test="abcbda";
//    printf("Longest length: %d\n", lengthOfLongestSubstring(test));
//    getchar();
//    return 0;
//}