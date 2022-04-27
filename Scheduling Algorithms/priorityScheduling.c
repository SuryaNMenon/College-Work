#include<stdio.h>
#define max 10

void main(){
    int proclist[max], btime[max], atime[max], priority[max], waittime[max], turnaround[max], comptime[max];
    int exectime;
    float avgwait = 0.0, avgtat = 0.0;

    int size;
    printf("Number of processes: ");
    scanf("%d", &size);
    for(int i=0;i<size;i++){
        printf("Process ID: ");
        scanf("%d", &proclist[i]);

        printf("Burst: ");
        scanf("%d", &btime[i]);

        printf("Arrival: ");
        scanf("%d", &atime[i]);

        printf("Priority: ");
        scanf("%d", &priority[i]);
    }
    int temp;
    for(int i=0;i<size-1;i++){
        for(int j=i+1; j<size; j++){
            if(atime[i] > atime[j]){
                temp = proclist[i];
                proclist[i] = proclist[j];
                proclist[j] = temp;

                temp = btime[i];
                btime[i] = btime[j];
                btime[j] = temp;

                temp = atime[i];
                atime[i] = atime[j];
                atime[j] = temp;

                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
            }
        }
    }

    waittime[0] = 0;
    turnaround[0] = waittime[0] + btime[0];
    comptime[0] = btime[0];

    for(int i=1; i<size; i++){
        exectime = comptime[i-1];
        for(int j=i; j<size; j++){
            if(exectime >= atime[j] && priority[j] < priority[i]){
                temp = proclist[i];
                proclist[i] = proclist[j];
                proclist[j] = temp;

                temp = btime[i];
                btime[i] = btime[j];
                btime[j] = temp;

                temp = atime[i];
                atime[i] = atime[j];
                atime[j] = temp;

                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
            }
        }
        waittime[i] = comptime[i-1] - atime[i];
        turnaround[i] = waittime[i] + btime[i];
        comptime[i] = comptime[i-1] + btime[i];
        avgwait += waittime[i];
        avgtat += turnaround[i];
    }
    printf("\nPID\tBurst\tArrival\tPriority\tWait\tTurnaround\tCompletion\n");
    for(int i=0;i<size;i++){
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n", proclist[i], btime[i], atime[i], priority[i], waittime[i], turnaround[i], comptime[i]);
    }
    printf("Avg Wait: %f", (avgwait/size));
    printf("Avg TAT: %f", (avgtat/size));
}