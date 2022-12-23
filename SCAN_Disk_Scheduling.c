#include<stdio.h>
#include<stdlib.h>

void sort(int requests[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(requests[j] > requests[j+1]){
                int temp = requests[j];
                requests[j] = requests[j+1];
                requests[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the number of Requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the Requests sequence: ");
    for(int i=0; i<n; i++)
        scanf("%d", &requests[i]);

    printf("Enter initial position: ");
    int head;
    scanf("%d", &head);

    printf("Enter maximum size of disk: ");
    int size;
    scanf("%d",&size);

    printf("Enter the head movement direction for high 1 and for low 0: ");
    int move;
    scanf("%d", &move);

    sort(requests,n);
    int index=0;
    for(int i=0; i<n; i++){
        if(requests[i] > head){
            index=i;
            break;
        }
    }

    int totalHeadMoment=0;

    // towards right(or greater value)
    if(move==1){
        for(int i=index; i<n; i++){
            totalHeadMoment += abs(head-requests[i]);
            head = requests[i];
        }

        totalHeadMoment += abs(head - size-1);
        head = size-1;

        for(int i=index-1; i>=0; i--){
            totalHeadMoment += abs(head-requests[i]);
            head = requests[i];
        }
    }

    //towards left(or low value)
    else{
        for(int i=index-1; i>=0; i--){
            totalHeadMoment += abs(head-requests[i]);
            head = requests[i];
        }

        totalHeadMoment += abs(head-0);
        head=0;

        for(int i=index; i<n; i++){
            totalHeadMoment += abs(head-requests[i]);
            head = requests[i];
        }
    }

    printf("Total head movement is %d", totalHeadMoment);
    return 0;
}