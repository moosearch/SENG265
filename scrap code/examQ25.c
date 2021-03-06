#include<stdio.h>
#include<stdlib.h>

int *shrink_array(int *a){
	
	int max_size = 0;
	int counter = 0;	
	int i = 0;
	int *list;
	int *temp;
	
	list = malloc(sizeof(int));
	if(list==NULL){
		exit(1);
	}
	max_size = 1;
	
	while(*(a+i) >= 0){
	
		/*Realloc if needed*/
		if(counter >= max_size) {
			
			temp = realloc(list,sizeof(int)*(max_size+1));
			if(temp==NULL){
				exit(1);
			}else{
				list = temp;
				max_size++;
			}
		}/*end if*/
		
		/*If a[i] == 0, skip; otherwise, copy into new list*/
		if(*(a+i) == 0){
			i++;
			continue;
		}else{
			*(list+counter) = *(a+i);
			counter++;
			i++;
		}
	}/*end while*/
	
	/*Exiting out of while loop implies that we hit a negative value*/
	if(counter >= max_size) {
		temp = realloc(list,sizeof(int)*(1+max_size));
		if(temp==NULL){
			exit(1);
		}
	}
	*(list+counter) = *(a+i); /*put negative element in thing*/
	
	return list;
	
}


int main(){
	int *b;
	int i=0;
	int a[] = {1,2,3,0,0,1,2,6,3,7,3,5,0,5,8,5,-1};
	int *c = a;
	b=shrink_array(c);
	while(*(b+i)>0){
		printf("%d\n",*(b+i));
		i++;
	}
	printf("%d\n",*(b+i));
	
	return 0;
}
