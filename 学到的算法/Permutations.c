// 全排列
// 参考：http://blog.csdn.net/hackbuteer1/article/details/6657435
#include <stdio.h>

// 就是递归算法
// 一位数字，直接输出
// 两位数字 1, 2        1/2{一位数字}
// 三位数字 1,2,3       1/2/3 {两位数字}
// 四位数字 1,2,3,4     1/2/3/4{三位数字}

void swap(char *a, char *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void permutation(char *a, int first, int last) {
    if (first == last) {
        // 一位数字，直接输出
        for (int i = 0; i <= last; i++) {
            printf("%c", a[i]);
        }
        putchar('\n');
    }
    else {
        // 从头遍历所有的字符
        for (int i = first; i <= last; i++) {
            // 交换成为第一个字符
            swap(&a[i], &a[first]);
            permutation(a, first + 1, last);
            swap(&a[i], &a[first]);
        }
    }
}

void test() {
    printf("---test1---\n");
    char str1[] = "1";
    permutation(str1, 0, 0);

    printf("---test2---\n");
    char str2[] = "12";
    permutation(str2, 0, 1);

    printf("---test3---\n");
    char str3[] = "123";
    permutation(str3, 0, 2);

    printf("---test4---\n");
    char str4[] = "1234";
    permutation(str4, 0, 3);

    printf("---test5---\n");
    char str5[] = "1234567";
    permutation(str5, 0, 6);


    printf("Done!\n");
}

int main() {
    test();
}