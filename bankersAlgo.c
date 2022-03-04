#include<stdio.h>
#define process 5
#define resource 3

void main(){
    int allocated[process][resource], maxNeed[process][resource], needMatrix[process][resource],
    available[resource], deadlockFlags[process], safeSeq[process];
    int index = 0;

    printf("Enter allocated resources\n");
    for(int i = 0; i<process; i++){
        for(int j= 0; j<resource; j++){
            scanf("%d", &allocated[i][j]);
        }
    }

    printf("Enter maximum resource needs\n");
    for(int i = 0; i<process; i++){
        for(int j= 0; j<resource;j++){
            scanf("%d", &maxNeed[process][resource]);
        }
    }

    printf("Enter available resources");
    for(int i = 0; i<resource; i++){
        scanf("%d", &available[i]);
    }

    for(int i=0; i<process; i++){
        for(int j = 0; j<resource; j++){
            maxNeed[i][j] = maxNeed[i][j] - allocated[i][j];
        }
    }

    for(int i = 0; i<process; i++){
        deadlockFlags[i] = 0;
    }

    for(int k = 0; k<process; k++){
        for(int i = 0; i<process; i++){
            if(deadlockFlags[i] == 0){
                int flag = 0;
                for(int j=0; j<resource; j++){
                    if(needMatrix[i][j] > available[j]){
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0){
                    safeSeq[index] = i;
                    index++;
                    for(int x = 0; x<resource; x++){
                        available[x] += allocated[i][x];
                    }
                    deadlockFlags[i] = 1;
                }
            }
        }
    }
    int isSafe = 1;
    for(int i = 0; i<process; i++){
        if(deadlockFlags[i] == 0){
            isSafe = 0;
            printf("System is not safe");
            break;
        }
    }
    if(isSafe == 1){
        printf("System is safe from deadlock. ");
        printf("Safe sequence is: ");
        for(int i = 0; i<process-1; i++){
            printf("P%d ->", safeSeq[i]);
        }
        printf(" P%d", safeSeq[process-1]);
    }
}