#include<stdio.h>

int main() {


    int array [10];
    int minimun = array[0];
    int secondmini = array[1];

    printf("Give us The 10 Values \n");

    for(int i=0;i<10;i++){

        printf("Give us %d value : ", i+1);
        scanf("%d",&array[i]);

    }

    for(int i=0;i<10;i++){


        if(array[i]<minimun)
        {
            minimun=array[i];

        }


       if(array[i]<secondmini && array[i]<minimun)
        secondmini = array[i];

    }




    printf("\nThe First Minimum is = %d",minimun);

    printf("The second Minimum is = %d",secondmini);



return 0;

}
