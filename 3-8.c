#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
	struct dirent* dent;
	struct stat buf;
	int kind;
	char path[BUFSIZ];

	if (argc != 2) {
		printf("Error, Can not open directory.");
		exit(1);
	}
	if (argc == 2) {
	    DIR* dp = opendir(argv[1]);

	    if (dp == NULL) {
		    perror("Error Can not approach directory.");
		    exit(1);
	    }
	    while (dent = readdir(dp))
	    {
		    if (dent->d_name[0] == '.'){
			    continue;
		    }
		    else {
			    sprintf(path,"%s/%s",argv[1],dent->d_name);
			    stat(path,&buf);
			    kind = buf.st_mode & S_IFMT;

			    switch (kind)
			    {
			    case S_IFDIR:
				    printf("%s is Directory.\n",dent->d_name);
				    break;
		 	    case S_IFREG:	
				    printf("%s is File.\n",dent->d_name);
				    break;
			    }
		    }
	    }
	closedir(dp);
    }
	return 0;

}
