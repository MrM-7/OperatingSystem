#include<stdio.h>
#include<string.h>

void print(int frames[], int n){
    for(int i=0; i<n; i++)
        printf("%d ", frames[i]);
    printf("\n");
}

int main(){
    printf("Enter total no of pages: ");
    int n;
    scanf("%d",&n);

    printf("Enter page sequence: ");
    int pages[n];
    for(int i=0; i<n; i++) scanf("%d",&pages[i]);

    printf("Enter total no of frames: ");
    int no_of_frames;
    scanf("%d", &no_of_frames);

    int frames[no_of_frames];
    memset(frames,-1,no_of_frames*sizeof(int));

    int indx=-1;
    int pageFaults=0;

    for(int i=0; i<n; i++){
        int flag=0;

        for(int j=0; j<no_of_frames; j++){
            if(pages[i] == frames[j]){
                print(frames,no_of_frames);
                flag=1;
                break;
            }
        }

        if(flag == 0){
            indx = (indx+1)%no_of_frames;
            frames[indx] = pages[i]; 
            pageFaults++;
            print(frames,no_of_frames);
        }
    }

    printf("Page Hits: %d\n", n-pageFaults);
    printf("Page Faults: %d\n", pageFaults);
    printf("Page Fault Ratio: %.2f",(float)pageFaults/n);

    return 0;
}