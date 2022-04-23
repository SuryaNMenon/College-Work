#include<stdio.h>
#define MAX 30

int main(){
    int size, btime[MAX], atime[MAX], remainBurst[MAX];
    int waitingTimeInter, turnAroundTimeInter;
    float avgWait = 0.0, avgTurnaround = 0.0;
    int time = 0, timeQuantum = 0, isCompleted = 0;

    printf("Enter number of processes: ");
    scanf("%d", &size);
    printf("Enter Time Quantum: ");
    scanf("%d", &timeQuantum);
    printf("Enter process data\n");
    for(int i = 0; i<size; i++){
        printf("Burst Time: ");
        scanf("%d", &btime[i]);
        remainBurst[i] = btime[i];
        printf("Arrival Time: ");
        scanf("%d", &atime[i]);
    }
    int completed = 0;
    printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\t Turnaround Time\n");
    for(int i = 0; completed!=size;){
        // First check process completion by comparing burst w/ quantum
        // Case 1 - Burst time lesser than time quantum
        if(remainBurst[i] <= timeQuantum && remainBurst[i] > 0){
            time+= remainBurst[i];
            remainBurst[i] = 0;
            isCompleted = 1;
        }

        // Case 2 - Burst time greater than time quantum
        else if(remainBurst[i]>timeQuantum && remainBurst[i] > 0){
            time += timeQuantum;
            remainBurst[i] -= timeQuantum;
        }

        // Second perform steps in case a process has completed
        if(remainBurst[i] == 0 && isCompleted == 1){
            completed++;
            waitingTimeInter = time - atime[i] - btime[i];
            turnAroundTimeInter = time - atime[i];
            avgWait += waitingTimeInter;
            avgTurnaround += turnAroundTimeInter;
            isCompleted = 0;
            printf("%d\t\t%d\t\t%d\t\t%d\t%d\n",i+1,btime[i],atime[i],waitingTimeInter,turnAroundTimeInter);
        }

        // Finally perform steps to change value of i
        // Case 1 - i is the index of last process
        if(i == size-1) 
            i=0;

        // Case 2 - i is any process other than last one
        // Here a atime[i] < time => a process has arrived 
        // in the time that current process has finished it's
        // time quantum/completed entirely/
        else if(atime[i+1]<=time) 
            i++;

        // Case 3 - no new process has arrived in the time
        // that current process finished it's time quantum
        // or completed entirely. Returning to first process. 
        else i = 0;
    }
    avgWait /= size;
    avgTurnaround /= size;
    printf("Average Wait: %f\n", avgWait);
    printf("Average Turnaround: %f\n", avgTurnaround);
    return 0;
}

