# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int main(int argc, char* argv[]){
int rfd, wfd, n;
	char buf[100]; 
	
	if( argc != 2 && argc != 3){
		printf("Error, write down 'file name'\n");
		exit(1);
	}
	rfd = open(argv[1],O_RDONLY);
	if(rfd == -1){
		perror("Fail to open"); 
		exit(1);
	}	
	if( argc == 2) {
		while(read(rfd,buf,sizeof(buf))) 
			printf("파일 출력 : %s\n", buf);
			close(rfd);
	}
	if( argc == 3) {
		wfd = open(argv[2],O_CREAT | O_WRONLY | O_TRUNC,0644);
		if( wfd == -1){
			perror("Fail to open second file");  
			return 1;	
		}
		while ((n = read(rfd, buf, sizeof(buf))) > 0){
			write(wfd, buf, n);
		}
		close(rfd);	
		close(wfd);
	}
	return 0;	
} 
