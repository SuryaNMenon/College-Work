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

    // first fit
    for(int j=0; j<prcCount; j++){
        int first;
        for(int i=0; i<blkCount; i++){
            if(block[i].isallocated == 0 && block[i].size >= prcList[j]){
                first = i;
                printf("Process %d allocated to block %d\n", j, first);
                block[first].isallocated = 1;
                block[first].pallocated = j;
                block[first].frag = block[first].size - prcList[j];
                break;
            }
        }
    }
    printf("\nBlock\tAllocated?\tProcess Allocated\tBlock Size\tProcess Size\tFragment remaining\n");
    for(int i = 0; i < blkCount; i++)
	{
		printf("  %d \t    %d     \t        %d       \t  %d     \t  %d \t   %d   \n",i, block[i].isallocated,  block[i].pallocated, block[i].size, prcList[block[i].pallocated], block[i].frag);
	}
}