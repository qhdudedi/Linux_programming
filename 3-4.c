#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h> 
int main(int argc, char* argv[]) {
	struct dirent* dent;
	if (argc != 2) {
		printf("Error,확인할 디렉토리명을 입력해주세요.\n");
		exit(1);
	}
	if (argc == 2) {

	DIR *dp = opendir(argv[1]);
	if (dp == NULL) {
		perror("Fail to  open directory");
		exit(1);
	}

	closedir(dp);
	if(rmdir(argv[1]) == -1){
		printf("%s 디렉토리는 비어있지 않습니다.\n",argv[1]);
	}
	else
	{
		printf("%s 디렉토리가 비어있어 해당 디렉토리를 삭제합니다.\n",argv[1]);
	} 
	return 0;
}	
}
