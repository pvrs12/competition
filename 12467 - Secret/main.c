#include <stdio.h>
#include <string.h>
#include <malloc.h>

void reverse(const char* s, char* rev, int len){
	int i;
	for(i=0;i<len;++i){
		rev[len-i-1]=s[i];
	}
	rev[len]='\0';
}

int main() {
	setbuf(stdout, NULL);
	int T,i;
	scanf("%d",&T);
	for(i=0;i<T;++i){
		char s[1000002];
		scanf("%1000001s",s);
		int j;
		for(j=strlen(s)-1;j>0;++j){
			char rev[1000002];
			memcpy( rev, &s[0], j );
			rev[j] = '\0';
			reverse(s,rev,j);
			fprintf(stderr,"%s\n",rev);
			char* loc = strstr(s,rev);
			if(!loc){
				continue;
			} else {
				//we found one
				printf("%s\n",rev);
				break;
			}
			free(rev);
		}
	}
	return 0;
}