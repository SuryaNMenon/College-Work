#include<stdio.h>
#define process 5
#define resource 3

int main(){
    int allocated[process][resource], maxNeed[process][resource], needMatrix[process][resource];
    int available[resource], deadlockFlags[process], safeSequence[process];
    int flag = 0, index = 0;

    printf("Enter allocated resources");
    for(int i=0; i<process;i++){
        for(int j=0;j<resource;j++){
            scanf("%d", &allocated[i][j]);
        }
    }

    printf("Enter maximum resource needs");
    for(int i=0; i<process;i++){
        for(int j=0;j<resource;j++){
            scanf("%d", &maxNeed[i][j]);
        }
    } 

    printf("Enter available resources");
    for(int i=0;i<resource;i++){
        scanf("%d", &available[i]);
    }

    for(int i=0;i<process;i++){
        for(int j=0;j<resource;j++){
            needMatrix[i][j] = maxNeed[i][j] - allocated[i][j];
        }
    }

    for(int i=0; i<process;i++){
        deadlockFlags[i] = 0;
    }

    for(int k=0; k<process; k++){
        for(int i=0; i<process;i++){
            if(deadlockFlags[i] == 0)
            {
                int flag = 0;
                    for(int j=0;j<resource;j++){
                        if(needMatrix[i][j] > available[j]){
                            flag = 1;
                            break;
                        }
                    if(flag == 0){
                        deadlockFlags[i] = 1;
                        safeSequence[index] = i;
                        index++;
                        for(int x = 0; x<resource; x++){
                            available[x] += allocated[i][x];
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i<resource; i++){
        if(deadlockFlags[i] == 0){
            printf("System is not safe from deadlock!");
            return 0;
        }
    }
    printf("System is safe from deadlock. The safe sequence is: ");
    for(int i = 0; i<process-1; i++){
        printf("P%d --> ", safeSequence[i]);
    }
    printf("P%d", safeSequence[process-1]);

}