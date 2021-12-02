#include <stdio.h>
#include <stdlib.h>

int m;

void	v(void)
{
	char s[524];			// [ebp-0x208]
	fgets(s, 0x200, stdin);
	printf(s);

	if (m != 0x40)
	       return ;
	fwrite("Wait what?!\n", 1, 12, stdout);
	system("/bin/sh");
	return ;
}


int	main(void)
{
	v();
	return (0);
}
