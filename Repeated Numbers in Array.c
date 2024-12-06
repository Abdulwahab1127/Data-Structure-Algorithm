#include <stdio.h>

int main(){
    int arr[10];
    int freq[10];

    printf("Enter elements of aray: ");
    for(int i=0;i<10;i++){
        scanf("%d", &arr[i]);
    }
    int counted=-1;

    for(int i=0;i<10;i++){
        int count=1;
        for(int j=i+1;j<10;j++){
            if(arr[i]==arr[j]){
                count ++;
                freq[j]=counted;
            }
        }
        if(freq[i] != counted){
            freq[i]=count++;
        }
    }


    //Display
    for(int i=0;i<10;i++){
        if(freq[i] != counted){
            printf("\n '%d' Repeated %d Times",arr[i],freq[i]);
        }
    }
    printf("\n\n");
}
