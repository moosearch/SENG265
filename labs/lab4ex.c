#include <stdio.h>
#include <string.h>
#define NUM 500
int main(){
	char buffer[NUM];
	FILE *fp;
	int word_count=0;
	int hobbit_count=0;
	char *token;
	fp= fopen("the-hobbit.in", "r");
	while(fgets(buffer, NUM, fp)!=NULL){
		/*printf("%s",buffer);*/
		token = strtok(buffer, " ");
		while(token!=NULL){
			token = strtok(NULL, " ");
			word_count++;
		}
	}
	fclose(fp);
	printf("The number of words in the document is %d and the number of times that the word hobbit appears is %d\n",word_count,hobbit_count);
	return 0;
}
