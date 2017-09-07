#include <stdio.h>

int check(int n, int k, int &ch, int cp)
{
	ch += (cp / k);
	cp = (cp%k) + (cp / k);

	if (cp >= k)
		check(n, k, ch, cp);

	return ch;
}

int main(void)
{
	int n, k;
	while (scanf("%d %d", &n, &k) != EOF)
	{
		int ch = n, cp = n;

		printf("%d \n", check(n, k, ch, cp));
	}

	return 0;
}