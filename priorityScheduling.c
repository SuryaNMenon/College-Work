#include<stdio.h>
#define MAX 30

int main(){
    int size, proclist[MAX], bTime[MAX], priority[MAX],
    waitingTime[MAX], turnaroundTime[MAX];
    float avgWait = 0.0, avgTurnaround = 0.0;
    printf("Enter number of processes: ");
    scanf("%d", &size);
    printf("Enter process details\n");
    for(int i = 0;i<size;i++){
        printf("Process ID: ");
        scanf("%d", &proclist[i]);
        
        printf("Burst time: ");
        scanf("%d", &bTime[i]);

        printf("Priority: ");
        scanf("%d", &priority[i]);
    }
    int temp = 0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1-i;j++){
            if(priority[j]<priority[j+1]){
                temp = priority[j];
                priority[j] = priority[j+1];
                priority[j+1] = temp;

                temp = bTime[j];
                bTime[j] = bTime[j+1];
                bTime[j+1] = temp;

                temp = proclist[j];
                proclist[j] = proclist[j+1];
                proclist[j+1] = temp;
            }
        }
    }
    printf("PID\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0;i<size;i++){
        waitingTime[i] = 0;
        for(int j = 0; j<i; j++){
            waitingTime[i] += bTime[j];
        }
        turnaroundTime[i] = waitingTime[i] + bTime[i];
        avgWait += waitingTime[i];
        avgTurnaround += turnaroundTime[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t%d\n",proclist[i],priority[i],bTime[i],waitingTime[i],turnaroundTime[i]);
    }

    avgWait /= size;
    avgTurnaround /= size;
    printf("Average Wait: %f\n", avgWait);
    printf("Average Turnaround: %f", avgTurnaround);
    return 0;
}