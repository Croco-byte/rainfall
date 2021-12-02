#include <stdio.h>
#include <stdint.h>
#include <string.h>

void	p(void)
{
	fflush(stdout);
	char s[80];		// [ebp - 0x4c]	
	gets(s);

	if ((int)__builtin_return_address(0) & 0xb0000000 != 0xb0000000)
	{
		printf("(%p)\n", (void *)__builtin_return_address(0));
		exit(1);
	}
	else
	{
		puts(s);
		strdup(s);
	}
	return ;
}

int	main(void)
{
		p();
		return (0);
}
