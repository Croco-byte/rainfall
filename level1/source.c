#include <stdio.h>

int	main(void)
{
	char buff[76];		// [esp + 0x10]
	gets(buff);
	return (0);
}
