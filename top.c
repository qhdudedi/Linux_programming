#include<stdlib.h>
#include<stdio.h>
#include <dirent.h>
#include <sys/stat.h>
# include <unistd.h>

int main(int argc, char* argv[]) {
	struct dirent* dent;
	struct stat buf;
	char path[BUFSIZ];

	char* cwd = getcwd(NULL, BUFSIZ);
	printf("Current directory path: %s. \n", cwd);

	DIR *dp = opendir(cwd);
	if (dp == NULL) {
		perror("Error! Can not approach to directory.");
		exit(1);
	}

	while ((dent = readdir(dp))) {
		if (dent->d_name[0] == '.') {
			continue;
		}
		else {
			sprintf(path, "%s/%s", argv[1], dent->d_name);
			stat(path, &buf);
			printf("size : %d \n", (int)buf.st_size);
		}

	}
	closedir(dp);
	return 0;
}
