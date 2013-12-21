#include <stdio.h>

void process(int *m, int *n, int r, int s){
	*m = r;
	*n = s;
}

int main(){
    int p[4] = {15,25,30,55};
    int b = 2000;
    int *p1 = &b;
    int *p2 = p;
    int *p3 = &p[3];
    
    printf("%d %d %d %d %d %d %d %d %d\n",p[0],p[1],p[2],p[3],b,*p1,*p2,*p2,*p3);
    
    process(p1,p3,3000,4000);
    printf("%d %d %d %d %d %d %d %d %d\n",p[0],p[1],p[2],p[3],b,*p1,*p2,*p2,*p3);
    
    p[0] = 4321;
    process(&p[3], &p[2], p[1],p[0]);
    printf("%d %d %d %d %d %d %d %d %d\n",p[0],p[1],p[2],p[3],b,*p1,*p2,*p2,*p3);
    
    *(p2+3) = 1234;
    p[0] = 333;
    printf("%d %d %d %d %d %d %d %d %d\n",p[0],p[1],p[2],p[3],b,*p1,*p2,*p2,*p3);
    
    exit(0);

}
