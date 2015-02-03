#include <stdio.h>
#include <malloc.h>

int main(){
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;++i){
		int m;
		scanf("%d",&m);
		int j;
		int data[] = malloc(sizeof(int)*m);
		for(j=0;j<m;++j){
			scanf("%d",&data[j]);

		}
	}
}
