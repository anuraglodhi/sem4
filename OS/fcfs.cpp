#include <iostream>
using namespace std;

typedef struct Process {
    int execTime;
    int turnaroundTime;
} Process;

void table(Process processes[], int n) {
    cout << endl << "Process\tTurnTime ExecTime WaitTime" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t" << processes[i].turnaroundTime << "\t " << processes[i].execTime << "\t  " << processes[i].turnaroundTime - processes[i].execTime << endl;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Number of processes? ";
    cin >> n;
    cout << endl;
    Process processes[n];
    for (int i = 0; i < n; i++) {
        cout << "Execution time of process #" << i+1 << "? ";
        int time = 0;
        cin >> time;
        processes[i].execTime = time;
    }
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        currentTime += processes[i].execTime;
        processes[i].turnaroundTime = currentTime;
    }

    int totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].turnaroundTime - processes[i].execTime;
    }
    table(processes, n);
    cout << "Average waiting time is " << (float)totalWaitingTime / n << "s" << endl;

    return 0;
}
