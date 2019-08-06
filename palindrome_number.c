#include <stdio.h>


bool isPalindrome(int x) {
	if (x < 0)
	{
		return false;
	}
	if (x == 0)
	{
		return true;
	}

	int pContainer[11] = { 0 };
	int* pCursor = pContainer;
	int nlen = 0;

	while (x)
	{
		*pCursor = x % 10;
		x /= 10;
		pCursor++;
		nlen++;
	}

	for (int i = 0; i <= nlen / 2; i++)
	{
		if (pContainer[i] != pContainer[nlen - i - 1])
		{
			return false;
		}
	}

	return true;
}



int main()
{
	printf("test if all true: %d, %d, %d\n", \
		isPalindrome(0) == true, \
		isPalindrome(-123) == false, \
		isPalindrome(12321) == true);
}