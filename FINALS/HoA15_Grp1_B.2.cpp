#include <iostream> 
 
void fWaitingTime(int *processes, int n, int *bt, int *wt, int quantum){ 
    int rem_bt[n]; 
    for(int i = 0; i < n; i++){ 
        rem_bt[i] = bt[i]; 
    } 
 
    int t = 0; 
 
    while(1){ 
        bool done = true; 
        for(int i = 0; i < n; i++){ 
            if(rem_bt[i] > 0){ 
                done = false; 
                if(rem_bt[i] > quantum){ 
                    t += quantum; 
                    rem_bt[i] -= quantum; 
                } else { 
                    t = t + rem_bt[i]; 
                    wt[i] = t - bt[i]; 
                    rem_bt[i] = 0; 
                } 
            } 
        } 
        if(done == true) 
        break; 
    } 
} 
 
void fTurnAroundTime(int *processes, int n, int *bt, int *wt, int *tat){ 
    for(int i = 0; i < n; i++){ 
        tat[i] = bt[i] + wt[i]; 
    } 
} 
 
void findavgTime(int *processes, int n, int *bt, int quantum){ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
 
    fWaitingTime(processes, n, bt, wt, quantum); 
    fTurnAroundTime(processes, n, bt, wt, tat); 
 
    std::cout 
    << "Processes" 
    << " Burst time" 
    << " Waiting time" 
    << " Turn around time\n"; 
 
    for(int i = 0; i < n; i++){ 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        std::cout 
        << " " << i+1 << "\t\t" 
        << bt[i] << "\t " 
        << wt[i] << "\t\t" 
        << tat[i] 
        << std::endl; 
    } 
 
    std::cout << "Average waiting time = " << (float)total_wt / (float)n << std::endl; 
    std::cout << "Average turn around time = " << (float)total_tat / (float)n << 
std::endl; 
} 
 
int main(){ 
    int processes[] = { 1, 2, 3,4}; 
    int x = sizeof processes / sizeof processes[0]; 
 
    int burst_time[] = {21, 3, 6, 2}; 
 
    int quantum = 2; 
    findavgTime(processes, x, burst_time, quantum); 
    return 0; 
}