#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct process
{
       int AT, BT, CT, TAT, WT, pri;
};
bool operator<(const process& a, const process& b)
{
    if (a.pri > b.pri)
        return true;
    else
    return false;
}
void NP_Pri()
{
    int i, n, x, y, z, time = 0, sumTAT = 0, sumWT = 0; double avgTAT, avgWT;
    process p[] = {{1, 9,1}, {2, 3,1}, {3, 5,3}, {4, 4,4},{5,2,7}};
    int n = sizeof proc / sizeof proc[0]; 
    bool flag = false;
    vector<process> Q;
    for (i = 0; i < n; i++) {
        process p;
        cin >> x >> y >> z;
        p.pri = x; p.AT = y; p.BT = z; 
        Q.push_back(p);
    }
    sort(Q.begin(), Q.end());
    i = 0;
    cout << "\nPri AT BT CT TAT WT" << endl;
    while (!Q.empty())
    {
        if (Q[i].AT <= time)
        {
           Q[i].CT = Q[i].BT + time;
           time = Q[i].CT;
           Q[i].TAT = Q[i].CT - Q[i].AT;
           Q[i].WT = Q[i].TAT - Q[i].BT;
           sumTAT += Q[i].TAT;
           sumWT += Q[i].WT;
           cout << Q[i].pri << "   " << Q[i].AT << "   " << Q[i].BT << " " << Q[i].CT << "  " << Q[i].TAT << "   " << Q[i].WT << endl;
           Q.erase(Q.begin() + i);
           flag = true; 
        }
        if (flag == true)
           i = 0;
        else
            i++;
    }
    avgTAT = (double)sumTAT/n; avgWT = (double)sumWT/n;
    cout << "Average TAT = " << avgTAT << endl;
    cout << "Average WT = " << avgWT << endl;
}
