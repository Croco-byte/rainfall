#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char c[64];								// 0x8049960

typedef struct		s_struct
{
	int		index;
	char		*str;
}			t_struct;

void	m(void)
{
	printf("%s - %d\n", c, time(0));
	return ;
}

int	main(int argc, char **argv)
{
	t_struct *struct_1 = malloc(sizeof(t_struct));			// 0x804a008 - [esp+0x1c]
	struct_1->index = 0x1;
	struct_1->str = malloc(0x8);					// 0x804a018

	t_struct *struct_2 = malloc(sizeof(t_struct));			// 0x804a028 - [esp+0x18]
	struct_2->index = 0x2;
	struct_2->str = malloc(0x8);					// 0x804a038

	strcpy(struct_1->str, argv[1]);
	strcpy(struct_2->str, argv[2]);

	FILE *file = fopen("/home/user/level8/.pass", "r");		// [esp+0x8]
	fgets(c, 0x44, file);
	puts("~~");
	return (0);
}
