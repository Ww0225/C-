//#include <stdio.h>
//#include <string.h>
//// ģʽƥ���㷨�������Ӵ��������еĵ�һ��ƥ��λ�ã�����ƥ���򷵻� -1
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
//            return i; // ƥ��ɹ�������ƥ��λ��
//        }
//    }
//    return -1; // ��ƥ��
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