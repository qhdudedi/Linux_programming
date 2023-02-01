#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	struct dirent *dent;
	struct stat buf;
	char path[BUFSIZ];

	if (argc != 2) {
		printf("Error,출력할 디렉토리명을 입력하세요. \n");
		exit(1);
	}
	if (argc == 2) {

		DIR* dp = opendir(argv[1]);

		if (dp == NULL) {
			perror("Error Can not approach directory.");
			exit(1);
		}

		while ((dent = readdir(dp))) {
			if (dent->d_name[0] == '.') continue;
			else printf("Name : %s\n", dent->d_name);

		}
		closedir(dp);
	}
	return 0;
}
