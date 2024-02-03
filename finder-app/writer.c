#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
	openlog(NULL, 0, LOG_USER);
	
	if (argc < 2) {
		syslog(LOG_ERR, "Invalid number of arguments %d\n", argc);
		return 1;
	}

	char *path = argv[1];

	int fd = open(path, O_RDWR | O_CREAT, 0777);
	if (fd == -1) {
		syslog(LOG_ERR, "Failed to open file\n");
		return 1;
	}

	char *text = argv[2];

syslog(LOG_DEBUG, "Writing %s to %s", text, path);

	write(fd, text, strlen(text));

	close(fd);

	return 0;
}
