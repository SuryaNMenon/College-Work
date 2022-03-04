#include<stdio.h>
#define MAX 30

struct BLOCK{
    int size;
    int isallocated;
    int pallocated;
    int frag;
}block[MAX];

void main(){
    int prcCount, blkCount, prcList[MAX];
    
    printf("Enter number of processes: ");
    scanf("%d", &prcCount);
    printf("Enter size of each process\n");
    for(int i = 0; i<prcCount; i++){
        printf("Process %d: ", i);
        scanf("%d", &prcList[i]);
    }

    printf("Enter number of blocks: ");
    scanf("%d", &blkCount);
    printf("Enter size of each block\n");
    for(int i = 0; i<blkCount; i++){
        printf("Block %d: ", i);
        scanf("%d", &block[i].size);
        block[i].isallocated = 0;
        block[i].pallocated = -1;
        block[i].frag = block[i].size;    
    }

    // Best Fit
    int best;
    for(int j=0; j<prcCount; j++){
        best = -1;
        for(int i = 0; i<blkCount; i++){
            if(block[i].isallocated == 0 && block[i].size >= prcList[j]){
                if(best == -1){
                    best = i;
                }
                else if(block[i].size < block[best].size){
                    best = i;
                }
            }
        }

        if(best != -1){
            printf("\nProcess %d allocated to block %d", j, best);
            block[best].isallocated = 1;
            block[best].pallocated = j;
            block[best].frag = block[best].size - prcList[j];
            }
        else{
            printf("Process needs to wait for memory to be free");
        }
    }
    for(int i = 0; i<blkCount; i++){
        printf("\nBlock\tAllocated?\tProcess Allocated\tBlock Size\tProcess Size\tFragment remaining");
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\n", i, block[i].isallocated, block[i].pallocated, block[i].size, prcList[block[i].pallocated], block[i].frag);
    }
}
