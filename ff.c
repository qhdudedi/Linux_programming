# include <stdio.h>
# include <fcntl.h> 
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int main(void){
	int rfd,n;
	char buf[256];
	off_t start, cur;
	int count_n = 0;
	
	rfd = open("data2.txt",O_RDONLY);
	if(rfd == -1){
		perror("Open data2.txt");
		exit(1);
	}
	start = lseek(rfd, 0, SEEK_SET);
	n = read(rfd,buf, sizeof(buf));
	for(n = 0; n <strlen(buf); n++){
		if(buf[n]== 'a'){
			count_n++;
		}
	}
	buf[n] = '\0';
	printf("count word =%d\n",count_n);
	close(rfd);	
	return 0;
}
