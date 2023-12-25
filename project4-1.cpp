//#include <stdio.h>
//#include <string.h>
//// 模式匹配算法，返回子串在主串中的第一个匹配位置，若无匹配则返回 -1
//int match(char* str, char* pattern) {
//    int len_str = strlen(str);
//    int len_pattern = strlen(pattern);
//    for (int i = 0; i <= len_str - len_pattern; ++i) {
//        int j;
//        for (j = 0; j < len_pattern; ++j) {
//            if (str[i + j] != pattern[j]) {
//                break;
//            }
//        }
//        if (j == len_pattern) {
//            return i; // 匹配成功，返回匹配位置
//        }
//    }
//    return -1; // 无匹配
//}
//
//int main() {
//    char str[] = "This is a sample text for pattern matching.";
//    char pattern[] = "sample";
//    int pos = match(str, pattern);
//    if (pos != -1) {
//        printf("Pattern found at position: %d\n", pos);
//    }
//    else {
//        printf("Pattern not found.\n");
//    }
//    return 0;
//}