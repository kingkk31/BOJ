#include <stdio.h>
int main(void)
{
	int m, n;
	scanf("%d %d", &m, &n);
	
    if(m>n) 
        printf("%lld\n",(long long)(n-1)*2+1);
	else 
        printf("%lld\n",(long long)(m-1)*2);
	
    if (m==n)
    {
		if(m%2==1) 
            printf("%d %d",(m-1)/2+1,(m-1)/2+1);
		else 
            printf("%d %d",(m)/2+1,(m)/2);
	}
	else
    {
		if(n>m)
        {
			if(m%2==0) 
                printf("%d %d",(m)/2+1,(m)/2);
			else 
                printf("%d %d",(m-1)/2+1,(m-1)/2+1+n-m);
		}
		else
        {
			if(n%2==0) 
                printf("%d %d",(n)/2+1,(n)/2);
			else 
                printf("%d %d",(n-1)/2+1+m-n,(n-1)/2+1);
		}
	}
    
    return 0;
}