include <stdio.h>

int main()
{
        int n;
        int sum;
        printf("Input an element: ");
        scanf("%d",&n);
        sum = fib(n);
        printf("\nThe sum is %d.\n",sum);
        return 0;
}

int fib(n)
{
        int list[n];
        int i;
        int sum;
        if(n==1){
                printf("Elements: 0");
                return 0;
        }else if(n==2){
                printf("Elements: 0, 1");
                return 1;
        }else{
                printf("Elements: 0, 1, ");
                list[0] = 0;
                list[1] = 1;
                sum=1;
                for(i=2; i<n; i++){
                        list[i]=list[i-1]+list[i-2];
                        sum += list[i];
                        if(i!=(n-1)){
                                printf("%d, ",list[i]);
                        }else{
                                printf("%d ",list[i]);
                        }
                }
        }
        return sum;
}

