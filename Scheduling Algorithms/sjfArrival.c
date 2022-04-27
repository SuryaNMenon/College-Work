#include<stdio.h>
#define max 10
void main(){
    int proclist[max], atime[max], btime[max];
    int waittime[max], turnaround[max], comptime[max];
    int exectime = 0;
    float avgwait = 0.0, avgtat = 0.0;

    int size;
    printf("Enter number of processes: ");
    scanf("%d", &size);
    for(int i=0; i<size; i++){
        printf("Process ID: ");
        scanf("%d", &proclist[i]);

        printf("Burst: ");
        scanf("%d", &btime[i]);

        printf("Arrival: ");
        scanf("%d", &atime[i]);
    }
    int temp;
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(atime[i] > atime[j]){
                temp = atime[i];
                atime[i] = atime[j];
                atime[j] = temp;

                temp = btime[i];
                btime[i] = btime[j];
                btime[j] = temp;

                temp = proclist[i];
                proclist[i] = proclist[j];
                proclist[j] = temp;
            }
        }
    }
    
    waittime[0] = 0;
    turnaround[0] = btime[0];
    comptime[0] = atime[0] + btime[0];
    for(int i=1;i<size;i++){
        exectime = comptime[i-1];
        for(int j=i; j<size; j++){
            if(exectime >= atime[j] && btime[i] > btime[j]){
                temp = atime[i];
                atime[i] = atime[j];
                atime[j] = temp;

                temp = btime[i];
                btime[i] = btime[j];
                btime[j] = temp;

                temp = proclist[i];
                proclist[i] = proclist[j];
                proclist[j] = temp;
            }
        }
        waittime[i] = comptime[i-1] - atime[i];
        turnaround[i] = btime[i] + waittime[i];
        comptime[i] = comptime[i-1] + btime[i];
        avgwait += waittime[i];
        avgtat += turnaround[i];
    }
    printf("\nPID\tBurst\tArrival\tWait\tTurnaround\tCompletion\n");
    for(int i=0;i<size;i++){
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", proclist[i], btime[i], atime[i], waittime[i], turnaround[i], comptime[i]);
    }
    printf("Average Wait: %f", avgwait/size);
    printf("Average TAT: %f", avgtat/size);
}