#include<stdio.h>
#include<stdlib.h>

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

    int totalHeadMoment=0;

    for(int i=0; i<n; i++){
        int min=1000, diff=0, index=0;

        for(int j=0; j<n; j++){
            if(requests[j] == -1) continue;

            diff = abs(head-requests[j]);
            if(min > diff){
                min = diff;
                index = j;
            }
        }

        totalHeadMoment += min;
        head = requests[index];
        requests[index] = -1;
    }

    printf("Total head movement is %d",totalHeadMoment);
    return 0;
}