#include <stdio.h>
#include <unistd.h>

int main(){
	int f = (int)fork();

	if (f == 0) {	
		execl("./eje1", (char*)NULL);
	} else {
		printf("%d\n", (int)getpid());
		execl("./eje1", (char*)NULL);
	}
}
