//Job Sequencing Problem (Greedy)
#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;  
};

bool compare(Job a, Job b) {
    return (a.profit > b.profit);
}

void jobSequencing(Job jobs[], int n) {
    sort(jobs, jobs + n, compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    int slot[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        slot[i] = -1;
    }

    char result[maxDeadline];

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;           
                result[j] = jobs[i].id; 
                break;
            }
        }
    }

    cout << "Selected jobs sequence: ";
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i] != -1)
            cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    Job jobs[] = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencing(jobs, n);

    return 0;
}
