#include<stdio.h>

int main(){
    int n, m;  // n=no of process  m=no of resource

    printf("Enter total no of processes: ");
    scanf("%d",&n);
    printf("Enter total no of resources: ");
    scanf("%d",&m);

    // int allocated[][3] = { { 0, 1, 0 }, { 2, 0, 0 },{ 3, 0, 2 }, { 2, 1, 1 }, { 0, 0, 2 } };

    // int max[][3] = { { 7, 5, 3 }, { 3, 2, 2 },{ 9, 0, 2 },{ 2, 2, 2 },{ 4, 3, 3 } };

    // int avail[3] = { 3, 3, 2 };

    int allocated[n][m];
    int max[n][m];
    int avail[m];

    printf("Enter Allocation Matrix: ");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            scanf("%d",&allocated[i][j]);
    }

    printf("Enter MAX Matrix: ");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            scanf("%d",&max[i][j]);
    }

    printf("Enter Available Resources: ");
    for(int i=0; i<m; i++)
        scanf("%d",&avail[i]);

    int need[n][m];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }

    int finish[n];
    for(int i=0; i<n; i++){
        finish[i] = 0;
    }

    int sequence[n];
    int indx=0;

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            if(finish[i] == 0){
                int flag=0;
                for(int j=0; j<m; j++){
                    if(need[i][j] > avail[j]){
                        flag=1;
                        break;
                    }
                }

                if(flag==0){
                    finish[i] = 1;
                    sequence[indx++]=i;
                    for(int j=0; j<m; j++){
                        avail[j] += allocated[i][j];
                    }
                }
            }
        }
    }

    int flag=0;
    for(int i=0; i<n; i++){
        if(finish[i] == 0){
            printf("System is not safe\n");
            flag=1;
            break;
        }
    }

    if(flag==0){
        printf("System is safe\n");
        printf("Safe sequence: ");
        for(int i=0; i<n; i++)
            printf("P%d ",sequence[i]);
    }
    return 0;
}