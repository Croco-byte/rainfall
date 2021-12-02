#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0;
	FILE	*file;						// [esp+0x9c]
	char	buffer[132];					// [esp+0x18]

	file = fopen("/home/user/end/.pass", "r");
	while (i < 132)
		buffer[i++] = '\0';
	if (file == 0 || argc != 2)
		return (255);
	
	fread(buffer, 1, 66, file);
	buffer[65] = '\0';
	buffer[atoi(argv[1])] = 0x0;
	
	fread(&buffer[66], 1, 65, file);
	fclose(file);

	if (strcmp(buffer, argv[1]) == 0)
		execl("/bin/sh", "sh", 0);
	else
		puts(&buffer[66]);
	return (0);
}
