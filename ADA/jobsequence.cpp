#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Job {
  int id;
  int profit;
  int deadline;
} Job;

bool compare(Job j1, Job j2) {
  return j1.profit > j2.profit;
}

int main() {
  int n;
  cout << "Enter the number of jobs: ";
  cin >> n;
  
  Job jobs[n];
  for (int i = 0; i < n; i++) {
    cout << "Enter profit and deadline for job #" << i+1 << ": ";
    cin >> jobs[i].profit;
    cin >> jobs[i].deadline;
    jobs[i].id = i+1;
  }

  sort(jobs, jobs + n, compare);

  int maxDeadline = max_element(jobs, jobs + n, [](Job j1, Job j2) -> bool {return j1.deadline < j2.deadline;})->deadline;
  
  int answer[maxDeadline];
  for (int i = 0; i < n; i++) {
    answer[i] = 0;
  }

  for (int i = 0; i < maxDeadline; i++) {
    int deadline = jobs[i].deadline - 1;
    while(answer[deadline] != 0) deadline--;
    answer[deadline] = jobs[i].id;
  }

  for (int a: answer) {
    cout << "Job#" << a << " -> ";
  } cout << endl;

  return 0;
}

