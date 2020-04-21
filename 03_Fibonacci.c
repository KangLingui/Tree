#include<stdio.h>
#include<stdlib.h>

int Fibonacci(int n)
{
	if(n < 0)
	{
		exit(1);
	}
	else
	{
		if(n == 0)return 0;
		if(n == 1 || n == 2)return 1;

		return Fibonacci(n-1)+Fibonacci(n-2);
	}
}

int Fibonacci2(int n)
{
	if(n < 0)
	{
		exit(1);
	}
	else
	{
		if(n == 0)return 0;
		if(n == 1 || n == 2)return 1;

		int i = 3;
		int fn;
		int fn_1 = 1;
		int fn_2 = 1;
		for(i = 3;i<=n;i++)
		{
			fn = fn_1+fn_2;

			fn_2 = fn_1;
			fn_1 = fn;
		}
		return fn;
	}
}
	


int main()
{
	int n;
	n = Fibonacci2(50);
	printf("%d\n",n);
	return 0;
}
