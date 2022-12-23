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
        totalHeadMoment += abs(requests[i] - head);
        head = requests[i];
    } 

    printf("Total head moment is %d \n", totalHeadMoment);
    return 0;
}