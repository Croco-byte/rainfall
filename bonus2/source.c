#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int language = 0;						// 0x8049988

int	greetuser(char *arg)					// arg max length : 72
{
	int i = 0;
	char str[72];						// [ebp-0x48]

	if (language == 0)
	{
		char *hey = "Hello ";
		while (i < 6)
		{
			str[i] = hey[i];
			i++;
		}
		str[i] = 0;
	}
	else if (language == 1)
	{
		char *hey = "Hyvää päivää ";			// encoded on 2 bytes ; 0xa4c3
		while (i < 18)					// 18 instead of 13 here to account for it
		{
			str[i] = hey[i];
			i++;
		}
		str[i] = 0;
	}
	else if (language == 2)
	{
		char *hey = "Goedemiddag! ";
		while (i < 13)
		{
			str[i] = hey[i];
			i++;
		}
		str[i] = 0;
	}
	strcat(str, arg);
	return (puts(str));
}


int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	
	char	buffer[73];					// [esp+0x50]
	char	*lang;						// [esp+0x9c]

	int i = 0;
	while (i < 73)
		buffer[i++] = '\0';
	strncpy(buffer, argv[1], 40);
	strncpy(buffer+40, argv[2], 32);
	lang = getenv("LANG");
	if (lang != 0)
	{
		if (memcmp(lang, "fi", 0x2) == 0)
			language = 0x1;
		else if (memcmp(lang, "nl", 0x2) == 0)
			language = 0x2;
	}
	
	char	arg[73];					// [esp+0x0]
	i = 0;
	while (i < 73)
	{
		arg[i] = buffer[i];
		i++;
	}
	return(greetuser(arg));
}
