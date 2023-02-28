#include <iostream>
#include <queue>
#include <stack>
#include <time.h>
using namespace std;
typedef struct process
{
    int pid;
    int arrival_time;
    int burst_time;
} Process;

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
int main()
{
    queue<Process *> q;
    int n;
    int t = 0;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        Process *p = (Process *)malloc(sizeof(Process));

        cin >> p->pid;
        cin >> p->arrival_time;
        cin >> p->burst_time;
        q.push(p);
    }
    while (!q.empty())
    {
        if (t >= q.front()->arrival_time)
        {
            Process *p = q.front();
            q.pop();
            cout << "Process: " << p->pid << " started on time: " << t << endl;

            t += p->burst_time;
            delay(p->burst_time);
            cout << p->pid << " completed on time: " << t << endl;
        }
        else
        {
            t++;
        }
    }
}