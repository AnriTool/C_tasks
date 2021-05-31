#include <stdio.h>
#include <stdlib.h>

int primary(int n)
{
	if 	(n > 0) {
		printf("%d ", n%10);
		primary(n/10);
	}
}

int finaly(int n)
{
	if 	(n > 0) {
		finaly(n/10);
		printf("%d ", n%10);
	}

}


int main(int argc, char *argv[])
{
	int n;
	scanf("%d",&n);
	primary(n);
	printf("\n");
	finaly(n);
	return 0;
}
