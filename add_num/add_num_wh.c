int getSum(int a, int b) {
	
	int carry = 0;//进位
	/*
		因为(a + b) == ((a & b) << 1) + (a ^ b)
		每一次循环都能确保(a + b)的值不变
		而每一次a因为carry的左移而在最低位增加一个0
		sizeof(int) * 8次循环后就能确保a为全0
		也就是完成了所有的进位
		此时（a + b) == (0 + b)
		b就是结果
	*/
	for (int i = 0; i < sizeof(a) * 8; i++) {

		carry = a & b;

		b = a ^ b;

		a = carry << 1;
	}

	return b;
}