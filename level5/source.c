#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	o(void)
{
	char const *cmd = "/bin/sh";
	system(cmd);
	_exit(1);
}

void	n(void)
{
	char buff[528];
	fgets(buff, 0x200, stdin);
	printf(buff);
	exit(1);
}

int	main(void)
{
	n();
	return (0);
}
