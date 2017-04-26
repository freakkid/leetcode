// 1006. Team Rankings 
// 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 从ABCDE的全排序中找出一个diatance最小的排序
char permutation_rank[150][6];  // ABCDE全排序为5!=120
int count = 0;                  // 计算全排序数量

void swap(char *a, char *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
// 获得全排序
void get_permutation(char *a, int first, int last) {
    if (first == last) {
        strcpy(permutation_rank[count++], a);
    }
    else {
        for (int i = first; i <= last; i++) {
            swap(&a[i], &a[first]);
            get_permutation(a, first + 1, last);
            swap(&a[i], &a[first]);
        }
    }
}

void test() {
    int n;
    char teams[] = "ABCDE";
    get_permutation(teams, 0, 4);

    while (scanf("%d", &n)) {
        if (n == 0)
            break;

        char input_rank[101][6];
        for (int i = 0; i < n; i++) {
            scanf("%s", input_rank[i]);
        }

        int min = 65536;
        char *result = NULL;
        // 遍历全排序
        for (int i = 0; i < count; i++) {
            // 遍历输入的样例      
            int value = 0;
            for (int j = 0; j < n; j++) {
                // 遍历全排序中某一排序的每一个字符
                for (int k = 0; k < 5; k++) {
                    // 在输入样例中找到该字符的位置
                    int pos = strchr(input_rank[j], permutation_rank[i][k]) - input_rank[j];
                    // 检查该字符位置前面是否有位置超前的字符
                    // eg. ABCDE C<D 与输入样例：ABDCE D<C
                    // 检查输入样例中ABDCE的C的时候，
                    // ABCDE中的C>D，与ABDCE中的D<C相反
                    // value++
                    for (int m = 0; m < pos; m++) {
                        if (strchr(permutation_rank[i], permutation_rank[i][k]) < strchr(permutation_rank[i], input_rank[j][m])) {
                            ++value;
                        }
                    }
                }
            }
            
            if (value < min) {
                result = permutation_rank[i];
                min = value;
            }
        }
        printf("%s is the median ranking with value %d.\n", result, min);
   }
}

int main() {
    test();
}