#include <stdio.h>
#include <math.h>

int main(){
	while(1){
		int start,finish;
		scanf("%d%d");
		if(start==-1 && finish==-1){
			break;
		}
		int diff = abs(finish-start);
		if(diff > 50){
			printf("%d\n",100-diff);
		} else {
			printf("%d\n",diff);
		}
	}
	return 0;
}