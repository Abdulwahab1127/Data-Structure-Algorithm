#include <stdio.h>

//Pending Question Use Switch and Functions

int main(){





    int rows = 3;
    int cols = 3;
    int array1 [3][3];
    int array2 [3][3];



    //First 2-D Array input
    printf("Enter Values For 1st 2D Array :\n");
    for(int i=0;i<rows;i++){

        for(int j=0;j<cols;j++){
            printf("Enter: ");
            scanf("%d",&array1[i][j]);
            printf("\n");


        }
    }

    printf("\nEnter Values For 2nd 2D Array :\n");
    for(int i=0;i<rows;i++){

        for(int j=0;j<cols;j++){
            printf("Enter: ");
            scanf("%d",&array2[i][j]);
            printf("\n");


        }
    }



    //For Some
    int sum[3][3];
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){

            sum[i][j] = array1[i][j] + array1[i][j];
        }

     }

    //For Subtraction
     int sub[3][3];
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){

            sub[i][j] = array1[i][j] - array1[i][j];
        }

     }

    //For Multiplication
    int multi[3][3];
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
           multi [i][j]=0;

           for(int k=0;k<3;k++){

            multi[i][j] += array1[i][k] * array1[k][j];

           }


        }

     }


     //Display Mulltiplication
















return 0;
}
