#include <stdlib.h>

void	n(void)
{
	system("/bin/cat /home/user/level7/.pass");
}

void	m(void)
{
	puts("Nope");
}

int	main(void)
{
	char	*a;			// [esp + 0x1c]
	void 	(*b)(void);		// [esp + 0x18]

	a = malloc(0x40);
	b = malloc(0x4);

	b = &m;
	strcpy(a, argv[1]);
	(*b)();


	return (0);
}
