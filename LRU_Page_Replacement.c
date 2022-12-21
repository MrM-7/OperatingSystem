#include<stdio.h>
#include<string.h>

int position(int time[], int n){
    int min=time[0];
    int pos=0;

    for(int i=1; i<n; i++){
        if(time[i] < min){
            min = time[i];
            pos = i;
        }
    }

    return pos;
}

int main(){
    int no_of_pages, no_of_frames;
    printf("Enter no of pages: ");
    scanf("%d",&no_of_pages);

    printf("Enter page sequence: ");
    int pages[no_of_pages];
    for(int i=0; i<no_of_pages; i++) scanf("%d",&pages[i]);

    printf("Enter no of frames: ");
    scanf("%d",&no_of_frames);
    int frames[no_of_frames];

    memset(frames,-1,no_of_frames*sizeof(int));
    int pageFaults=0;
    int time[no_of_frames];
    int counter=0;

    for(int i = 0; i < no_of_pages; ++i){
            int flag1,flag2;
            flag1 = flag2 = 0;
            
            //if its a page hit
            for(int j = 0; j < no_of_frames; ++j){
                if(frames[j] == pages[i]){
                    counter++;
                    time[j] = counter;
                    flag1 = flag2 = 1;
                    break;
                }
            }
            
            //page missing but space is available in frame
            if(flag1 == 0){
                for(int j = 0; j < no_of_frames; ++j){
                    if(frames[j] == -1){
                        counter++;
                        pageFaults++;
                        frames[j] = pages[i];
                        time[j] = counter;
                        flag2 = 1;
                        break;
                    }
                }    
            }
            
            //page missing and all frames are full, so use lru to replace
            if(flag2 == 0){
                int pos = position(time, no_of_frames);
                counter++;
                pageFaults++;
                frames[pos] = pages[i];
                time[pos] = counter;
            }
            
            for(int j = 0; j < no_of_frames; ++j){
                printf("%d ", frames[j]);
            }
            printf("\n");
    }

    printf("Page Hits: %d\n", no_of_pages-pageFaults);
    printf("Page Faults: %d\n", pageFaults);
    printf("Page Fault Ratio: %.2f",(float)pageFaults/no_of_pages);

    return 0;
}