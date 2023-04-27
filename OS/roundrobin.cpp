#include <iostream>
using namespace std;

typedef struct Process {
    int execTime;
    int turnoverTime;
    int processTime;
} Process;

void table(Process processes[], int n) {
    cout << endl << "Process\tTurnTime ExecTime WaitTime" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t" << processes[i].turnoverTime << "\t " << processes[i].execTime << "\t  " << processes[i].turnoverTime - processes[i].execTime << endl;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Number of processes? ";
    cin >> n;
    cout << endl;
    Process processes[n];
    int totalExecTime = 0;
    for (int i = 0; i < n; i++) {
        cout << "Execution time of process #" << i+1 << "? ";
        int time = 0;
        cin >> time;
        processes[i].execTime = time;
        processes[i].processTime = 0;
        totalExecTime += time;
    }

    int time = 0;
    int i = 0;
    int quantum;
    cout << "Enter time quantum: ";
    cin >> quantum;
    while (totalExecTime) {
        if (processes[i].execTime - processes[i].processTime > quantum) {
            processes[i].processTime += quantum;
            time += quantum;
            totalExecTime -= quantum;
        }
        else {
            if (processes[i].processTime == processes[i].execTime) {
                i = (i+1) % n;
                continue;
            }
            int remaining = processes[i].execTime - processes[i].processTime;
            totalExecTime -= remaining;
            time += remaining;
            processes[i].turnoverTime = time;
            processes[i].processTime = processes[i].execTime;
        }
        i = (i+1) % n;
    }

    int totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].turnoverTime - processes[i].execTime;
    }
    table(processes, n);
    cout << "Average waiting time is " << (float)totalWaitingTime / n << "s" << endl;
}