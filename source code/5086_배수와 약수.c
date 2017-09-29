#include <stdio.h>

int main(void)
{
	int a,b;
	
	while (scanf("%d %d", &a, &b) != EOF)
	{
		if (a == 0 && b == 0)
			return 0;
		else
		{
			if (a > b)
			{
				if (a%b == 0)
					printf("multiple \n");
				else
					printf("neither \n");
			}
			else if (a < b)
			{
				if (b%a == 0)
					printf("factor \n");
				else
					printf("neither \n");
			}
		}
	}

	return 0;
}