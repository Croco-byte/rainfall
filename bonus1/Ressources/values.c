#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	printf("As hex			-->	0x%08x\n", n*4, n*4);
	printf("As signed int		-->	%d\n", n*4, n*4);
	printf("As unsigned int		-->	%zu\n", n*4,n*4);
	return (0);
}
