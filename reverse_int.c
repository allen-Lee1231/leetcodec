#include <stdio.h>
//Given a 32-bit signed integer, reverse digits of an integer.

int reverse(int x) 
{
	int e(int i) {
		int c = 1;
		while (--i) c *= 10;
		return c;
	}

	int digit = 0, M = 2147483641;
	int ans = x;

	while (ans) {
		digit++;
		ans /= 10;
	}

	if (digit >= 10 && abs(x % 10) > 2) return 0;

	while (x) {
		M -= abs(e(digit) * (x % 10));
		if (M < 0) return 0;
		ans += e(digit)*(x % 10);
		digit--;
		x /= 10;
		//printf("Ans: %d\n", ans);
	}
	return ans;
}


int main(int argc, char*argv)
{
	int test=12345;
	if (argc)
	{
		test = atoi(argv[1]);
	}
	printf("interger: %d\treversed: %d\n", test, reverse(test));
	getchar();
	return 0;
}