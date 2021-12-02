#include <stdio.h>
#include <unistd.h>
#include <string.h>

void	p(char *s, char *sep)
{
	puts(sep);
	char buffer[0x1008];
	read(0, buffer, 0x1000);
	char *nl = strchr(buffer, '\n');
	*nl = '\0';
	strncpy(s, buffer, 20);
	return ;
}


void	pp(char *s)				// [ebp+0x8]
{
	char s2[20];				// [ebp-0x30]
	p(s2, " - ");
	char s3[20];				// [ebp-0x1c]
	p(s3, " - ");
	strcpy(s, s2);
	
	int i = 0;
	while (s[i])
		i++;
	s[i] = ' ';
	strcat(s, s3);
	return ;
}

int	main(void)
{
	char	s[54];		
	pp(s);
	puts(s);
	return (0);
}
