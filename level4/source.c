#include <stdio.h>
#include <stdlib.h>

int m;

void	p(char *buff)
{
	printf(buff);
	return ;
}

void	n(void)
{
	char	buff[528];

	fgets(buff, 0x200, stdin);
	p(buff);
	if (m != 0x1025544)
		return ;
	system("/bin/cat /home/user/level5/.pass");
	return ;
}

int	main(void)
{
	n();
	return (0);
}
