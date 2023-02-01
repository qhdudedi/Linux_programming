#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	struct dirent* dent;
	char* cwd = getcwd(NULL, BUFSIZ);
	printf("Current directory path: %s. \n", cwd);

		DIR* dp = opendir(cwd);
		if (dp == NULL) {
			perror("Error! Can not approach to directory.");
			exit(1);
		}
	while ((dent = readdir(dp))) {
		if (dent->d_name[0] == '.') continue;

		else printf("Name : %s\n", dent->d_name);

	}
	closedir(dp);
	return 0;
}
