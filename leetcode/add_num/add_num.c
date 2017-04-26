#include <stdio.h>

int main() {
	
	while (1) {
		int a, b;
		scanf("%d %d", &a, &b);

		int num1, num2;
		int i;

		for ( i = 0; i < sizeof(int) * 8; i ++) {
			num1 = a & b;
			num2 = a ^ b;
			num1 <<= 1;
			a = num1;
			b = num2;
		}
		printf("%d\n", num2);
	}

}