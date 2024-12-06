#include<stdio.h>

int main(){


 int array[10];
  int sum=0;
  printf("Give us The 10 Values \n");

    for(int i=0;i<10;i++){

        printf("Give us %d value : ", i+1);
        scanf("%d",&array[i]);

    }


    for(int i=0;i<10;i++){

        if(array[i]%2==0){
            sum += array[i];
        }


    }

    printf("\nThe Total Sum of Even Numbers = %d",sum);

    return 0;


}
