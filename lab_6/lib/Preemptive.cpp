
#include<bits/stdc++.h> 

#include <iostream>
using namespace std; 
  
struct Process_1 { 
    int pid; // Process_1 ID 
    int bt; // Burst Time 
    int art; // Arrival Time 
};                                                                                                                                                                                                                                                                                                                                                                                       
  
// Function to find the waiting time for all 
// Process_1es 
void findWaitingTime(Process_1 proc[], int n, 
                                int wt[]) 
{ 
    int rt[n]; 
  
    // Copy the burst time into rt[] 
    for (int i = 0; i < n; i++) 
        rt[i] = proc[i].bt; 
  
    int complete = 0, t = 0, minm = INT_MAX; 
    int shortest = 0, finish_time; 
    bool check = false; 
  
    // Process_1 until all Process_1es gets 
    // completed 
    while (complete != n) { 
  
        // Find Process_1 with minimum 
        // remaining time among the 
        // Process_1es that arrives till the 
        // current time` 
        for (int j = 0; j < n; j++) { 
            
            if ((proc[j].art <= t) && 
            (rt[j] < minm) && rt[j] > 0) { 
                minm = rt[j]; 
                shortest = j; 
                check = true; 
            } 
        } 
  
        if (check == false) { 
            t++; 
            
            continue; 
        } 
  
        // Reduce remaining time by one 
        rt[shortest]--; 
  
        // Update minimum 
        minm = rt[shortest]; 
        if (minm == 0) 
            minm = INT_MAX; 
  
        // If a Process_1 gets completely 
        // executed 
        if (rt[shortest] == 0) { 
  
            // Increment complete 
            complete++; 
            check = false; 
  
            // Find finish time of current 
            // Process_1 
            finish_time = t + 1; 
  
            // Calculate waiting time 
            wt[shortest] = finish_time - 
                        proc[shortest].bt - 
                        proc[shortest].art; 
  
            if (wt[shortest] < 0) 
                wt[shortest] = 0; 
        } 
        
        // Increment time 
        t++; 
    } 
} 
  
// Function to calculate turn around time 
void findTurnAroundTime(Process_1 proc[], int n, 
                        int wt[], int tat[]) 
{ 
    // calculating turnaround time by adding 
    // bt[i] + wt[i] 
    for (int i = 0; i < n; i++) 
        tat[i] = proc[i].bt + wt[i]; 
} 
  
// Function to calculate average time 
void findavgTime(Process_1 proc[], int n) 
{ 
    int wt[n], tat[n], total_wt = 0, 
                    total_tat = 0; 
  
    // Function to find waiting time of all 
    // Process_1es 
    findWaitingTime(proc, n, wt); 
  
    // Function to find turn around time for 
    // all Process_1es 
    findTurnAroundTime(proc, n, wt, tat); 
  
    // Display Process_1es along with all 
    // details 
    cout << "\n| Process_1es |"
        << "| Burst time |"
        << "| Waiting time |"
        << "| Turn around time |\n"; 
  
    // Calculate total waiting time and 
    // total turnaround time 
    for (int i = 0; i < n; i++) { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << "" << proc[i].pid << "\t\t"
            << proc[i].bt << "\t\t " << wt[i] 
            << "\t\t " << tat[i] << endl; 
    } 
  
    cout << "\nAverage waiting time = "
        << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "
        << (float)total_tat / (float)n; 
} 
  
// Driver code 
int main_preemptive() 
{ 
    Process_1 proc[] = { { 1, 9, 1 }, { 2, 3, 1 }, 
                    { 3, 5, 3 }, { 4, 4, 4 },{5,2,7} }; 
    
    int n = sizeof(proc) / sizeof(proc[0]); 
        cout<<"------------------------------------------------------------------------------------\n";
    cout << "Sequence process is :";
    for (int i = 0 ; i<= n-1; i++) {
         if (i ==n-1){
            cout <<"P"<< proc[i].pid <<" ";
        }
        else
        {
             cout <<"P"<< proc[i].pid <<"->"; 
        }
        
       
    }
       
    findavgTime(proc, n); 
    cout<<"\n------------------------------------------------------------------------------------\n";
   cout << '\n' << "Press a key to continue...";

    return 0; 
} 