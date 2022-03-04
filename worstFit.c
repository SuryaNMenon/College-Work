#include<stdio.h>
#define MAX 30

struct BLOCK{
    int size;
    int isallocated;
    int pallocated;
    int frag;
}block[MAX];

void main(){
    int prcCount, prcList[MAX], blkCount;

    printf("Enter number of processes: ");
    scanf("%d", &prcCount);
    printf("Enter process sizes\n");
    for(int i = 0;i<prcCount; i++){
        printf("Process %d: ", i);
        scanf("%d", &prcList[i]);
    }

    printf("Enter number of blocks: ");
    scanf("%d", &blkCount);
    printf("Enter block sizes\n");
    for(int i = 0; i<blkCount; i++){
        printf("Block %d: ", i);
        scanf("%d", &block[i].size);
        block[i].isallocated = 0;
        block[i].pallocated = -1;
        block[i].frag = block[i].size;
    }

    // Worst fit
    int worst;
    for(int j=0;j<prcCount; j++){
        worst = -1;
        for(int i=0; i<blkCount; i++){
            if(block[i].isallocated == 0 && block[i].size >= prcList[j]){
                if(worst == -1) worst = i;
                else if(block[i].size>block[worst].size) worst = i;
            }
        }
        if(worst != -1){
            printf("Process %d allocated to block %d\n", j, worst);
            block[worst].isallocated = 1;
            block[worst].pallocated = j;
            block[worst].frag = block[worst].size - prcList[j];
        }
        else printf("Process %d must wait for memory to be free\n");
    }
    printf("\nBlock\tAllocated?\tProcess Allocated\tBlock Size\tProcess Size\tFragment remaining\n");
    for(int i = 0; i<blkCount; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i, block[i].isallocated, block[i].pallocated, block[i].size, prcList[block[i].pallocated], block[i].frag);
}
}