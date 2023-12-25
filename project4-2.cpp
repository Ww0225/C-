//#include <stdio.h>
//#include <string.h>
//// 比较两个串的大小，若 s > t，返回 1；若 s < t，返回 -1；否则返回 0
//int comparestrings(char* s, char* t) {
//    int len_s = strlen(s);
//    int len_t = strlen(t);
//    int min_len = (len_s < len_t) ? len_s : len_t;
//    for (int i = 0; i < min_len; ++i) {
//        if (s[i] > t[i]) {
//            return 1; // s > t
//        }
//        else if (s[i] < t[i]) {
//            return -1; // s < t
//        }
//    }
//    if (len_s > len_t) {
//        return 1; // s > t
//    }
//    else if (len_s < len_t) {
//        return -1; // s < t
//    }
//    return 0; // s == t
//}
//int main() {
//    char s[] = "hello";
//    char t[] = "hello world";
//    int result = comparestrings(s, t);
//    if (result == 1) {
//        printf("s is greater than t.\n");
//    }
//    else if (result == -1) {
//        printf("s is less than t.\n");
//    }
//    else {
//        printf("s is equal to t.\n");
//    }
//    return 0;
//}