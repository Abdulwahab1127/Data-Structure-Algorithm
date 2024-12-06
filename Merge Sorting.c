#include<stdio.h>

void mergingFunction(int Array[],int LeftSide, int Mid, int RightSide){

    int i= 0,j=0,k= LeftSide;


    int side1 = Mid - LeftSide +1 ;
    int side2 = RightSide - Mid;


    //Creating Temporary Arrays to store Values

    int TempLeft[side1];
    int TempRight[side2];


    //Storing The Data in Temp Array
    for (i = 0; i < side1; i++)
        TempLeft[i] = Array[LeftSide + i];

    for (j = 0; j < side2; j++)
        TempRight[j] = Array[Mid + 1 + j];

     i = 0;
    j = 0;

    //Merging Back the Temp

    while(i < side1 && j < side2){
    //if the left side is smaller or equal to Right
        if(TempLeft[i] <= TempRight[j])
        {
                Array[k]= TempLeft[i];

                //Moving to next Value
                i++;

        }else{
     //Otherwise store the right side
                Array[k]= TempRight[j];
                j++;

        }
                k++;
    }
//In-case any leftover Values, we'll use the loop again
    while(i < side1){

                Array[k]= TempLeft[i];

                //Moving to next Value
                i++;
                k++;

            }

    while(j < side2){

                Array[k]= TempRight[j];

                //Moving to next Value
                j++;
                k++;
            }
}

void mergeSorting(int Array[],int LeftSide, int RightSide){

    if(LeftSide < RightSide){

        //Finding the middle point of array
        int Mid = (LeftSide + RightSide) / 2;

        //Recursive Function on Left Side till the array is sorted
        mergeSorting(Array, LeftSide,Mid);


        //Recursive Function on Left Side till the array is sorted
        mergeSorting(Array,Mid + 1,RightSide);

        //As we Sorted, Now we will merge both sorted parts together

       mergingFunction(Array,LeftSide,Mid,RightSide);

    }

}
int main(){

    int Array[6];
    printf("\nGive 6 Elements For Merge Sorting: \n");

    for(int i=0;i<6;i++){
        printf("Value %d :",i+1);
        scanf("%d",&Array[i]);

    }

    int ArrayLength = sizeof(Array) / sizeof(Array[0]);

    //Printing Given Array
    printf("\nOriginal Array:\n");
    for (int i = 0; i < 6; i++)
        printf("%d ", Array[i]);
    printf("\n");

    mergeSorting(Array,0, ArrayLength - 1);

    //Printing Sorted Array Using Merge Sort
    printf("\nSorted Array:\n");
    for (int i = 0; i < 6; i++)
        printf("%d ", Array[i]);
    printf("\n");

    return 0;

}

