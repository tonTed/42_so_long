
#include <stdio.h>

int main(int argc, char const *argv[])
{
	char flag = 0x0;

	printf("%d\n", flag);
	flag |= 0x1;
	printf("%d\n", flag & 0x1);
	flag |= 0x2;
	flag |= 0x2;
	printf("%d\n", flag);
	printf("%d\n", flag & 0x2);

	return 0;
}
