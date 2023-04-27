#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Process {
    int id;
    int execTime;
    int turnoverTime;
    int priority;
} Process;

void table(Process processes[], int n) {
    cout << endl << "Process\tTurnTime ExecTime WaitTime" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P" << processes[i].id << "\t" << processes[i].turnoverTime << "\t " << processes[i].execTime << "\t  " << processes[i].turnoverTime - processes[i].execTime << endl;
    }
    cout << endl;
}

bool compare(Process p1, Process p2) {
    return p1.priority < p2.priority;;
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
        processes[i].id = i+1;
        processes[i].execTime = time;
    }
    for (int i = 0; i < n; i++) {
        cout << "Priority of process #" << i+1 << "? ";
        cin >> processes[i].priority;
    }
    sort(processes, processes + n, compare);
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        currentTime += processes[i].execTime;
        processes[i].turnoverTime = currentTime;
    }

    int totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].turnoverTime - processes[i].execTime;
    }
    table(processes, n);
    cout << "Average waiting time is " << (float)totalWaitingTime / n << "s" << endl;

    return 0;
}