#include<stdio.h>

void main(){
    int arr[20], n;
    scanf("%d", &n); //string length input

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]); //string input
    }

    for(int i=0; i<n; i++){
        printf("%d", arr[i]);
    }//input string

    printf("\n");

    int a[20], b[20], idx = 0, cnt = 0;

    for(int i=0; i<n; i++){
        if(arr[i] == 1){
            cnt++;
        }
        else{
            cnt=0;
        }
        if(cnt == 5){
            idx = i;
            break;
        }
    }

    b[0] = 0;

    for(int i=0; i<idx+1; i++){
        a[i] = arr[i];
    }

    int j = idx+1;
    int i = 1;

    while(j < n && i < 20){
        b[i] = arr[j];
        j++;
        i++;
    }

    printf("String stuffed:\n");


    for(int i=0; i<idx+1; i++){
        printf("%d", a[i]);
    }

    for(int i=0; i<n-idx; i++){
        printf("%d", b[i]);
    }
}
