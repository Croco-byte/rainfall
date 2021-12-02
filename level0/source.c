#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int	main(int argc, char **argv)
{
	int a;
	a = atoi(argv[1]);
	
	if (a == 0x1a7)
	{
		char 		*s = strdup("/bin/sh");
		gid_t 		gid = getegid();
		uid_t		uid = geteuid();
		
		setresgid(gid, gid, gid);
		setresuid(uid, uid, uid);
		execv(s, 0);
	}
	else
		fwrite("No !\n", 1, 5, stdout);
	return (0);
}
