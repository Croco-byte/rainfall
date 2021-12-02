#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Il faut que le pointeur contenu par auth, +0x20, ne soit pas égal à 0 pour déclencher SYSTEM

char	*service;				// 0x8049ab0
char	*auth;					// 0x8049aac

int	main(void)
{
	char buff[128];				// [esp + 0x20]
	char *authstr = "auth ";
	char *resetstr = "reset";
	char *servstr = "service";
	char *loginstr = "login";
	int i = 0;
	int k = 0;

	while (1)
	{
		printf("%p, %p\n", service, auth);
		if (fgets(buff, 128, stdin) == 0)
			return (0);
		while (buff[i] == authstr[i] && i < 5)			// AUTH
			i++;
		if (i == 5)
		{
			char *s = malloc(0x4);
			auth = s;
			*s = 0;
			i = 4;
			while (buff[i])
			{
				k++;
				i++;
			}
			if (k <= 0x1e)
				strcpy(auth, &buff[4]);
		}

		i = 0;
		while (buff[i] == resetstr[i] && i < 5)			// RESET
			i++;
		if (i == 5)
			free(auth);

		i = 0;
		while (buff[i] == servstr[i] && i < 7)			// SERVICE
			i++;
		if (i == 7)
			service = strdup(&buff[6]);

		i = 0;							// LOGIN
		while (buff[i] == loginstr[i] && i < 5)
			i++;
		if (i == 5)
		{
			if ((auth + 0x20) != 0x0)
				system("/bin/sh");
			else
				fwrite("Password:\n", 0x1, 0xa, stdout);
		}

	}
	
	return (0);
}
