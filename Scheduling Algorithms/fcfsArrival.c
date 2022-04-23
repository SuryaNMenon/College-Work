#include <stdio.h>

int waitingTime(int size, int proclist[], int btime[], int atime[], int waittime[]){
    int totalBurst[size];
    //totalBurst[0] = btime[0];
    waittime[0] = 0;
    for(int i=1;i<size;i++){
        //totalBurst[i] = totalBurst[i-1] + btime[i];
        waittime[i] = (atime[i-1] + btime[i-1] + waittime[i-1]) - atime[i];
    }
    return 0;
}

int turnaroundTime(int size, int proclist[], int btime[], int atime[], int waittime[], int turnaround[]){
    for(int i=0;i<size;i++){
        turnaround[i] = btime[i] + waittime[i];
    }
    return 0;
}

int avgtime(int size, int proclist[], int btime[], int atime[]){
    int waittime[size], turnaround[size], total_wait = 0, total_tat = 0;
    waitingTime(size, proclist, btime, atime, waittime);
    turnaroundTime(size, proclist, btime, atime, waittime, turnaround);

    printf("Process Data\n");
    printf("Process ID\tBurst Time\tArrival Time\tWaiting time\tTurnaround Time\tCompletion Time\n");
    for(int i=0; i<size; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proclist[i], btime[i], atime[i], waittime[i], turnaround[i], (turnaround[i] + atime[i]));
        total_wait += waittime[i];
        total_tat += turnaround[i];
    }
    printf("Total Wait: %d", total_wait);
    printf("Total Turnaround: %d", total_tat);
    return 0;
}

int main(){
    printf("Enter number of processes: ");
    int size; 
    scanf("%d", &size);
    int proclist[size], btime[size], atime[size];
    printf("Enter process details\n");
    for(int i=0;i<size;i++){
        printf("Process ID: ");
        scanf("%d", &proclist[i]);
        
        printf("Burst Time: ");
        scanf("%d", &btime[i]);

        printf("Arrival Time: ");
        scanf("%d", &atime[i]);
    }
    avgtime(size, proclist, btime, atime);
}