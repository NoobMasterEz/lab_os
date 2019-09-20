#include<bits/stdc++.h> 
#include <iostream>
using namespace std; 
  
struct Process_2 
{ 
   int pid; // Process_2 ID 
   int bt;  // Burst Time 
   int at;
}; 

// This function is used for sorting all 
// Process_2es in increasing order of burst 
// time 
bool comparison(Process_2 a, Process_2 b) 
{ 
     if(a.at == b.at) 
    { 
    return a.bt<b.bt; 
    } 
    else
    { 
        return a.at<b.at; 
    } 
} 
  
// Function to find the waiting time for all 
// Process_2es 
void findWaitingTime(Process_2 proc[], int n, int wt[]) 
{
// declaring service array that stores cumulative burst time  
int service[50]; 
  
// Initilising initial elements of the arrays 
service[0]=0; 
wt[0]=0; 
  
  
for(int i=1;i<n;i++) 
{ 
service[i]=proc[i-1].bt+service[i-1]; 
  
wt[i]=service[i]-proc[i].at+1; 
  
// If waiting time is negative, change it into zero 
      
    if(wt[i]<0) 
    { 
    wt[i]=0; 
    } 
} 
  
} 
  
// Function to calculate turn around time 
void findTurnAroundTime(Process_2 proc[], int n, 
                        int wt[], int tat[]) 
{ 
    // calculating turnaround time by adding 
    // bt[i] + wt[i] 
    for (int i = 0; i < n ; i++) 
        tat[i] = proc[i].bt + wt[i]; 
} 
  
//Function to calculate average time 
void findavgTime(Process_2 proc[], int n) 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
  
    // Function to find waiting time of all Process_2es 
    findWaitingTime(proc, n, wt); 
    cout << "\n \t\t   ";
    for (int j = 0; j < n; j++)
    {
        if (j ==n-1){
            cout <<" "<< wt[j] ;
        }
        else
        {
            cout <<" "<< wt[j] <<"->"; 
        }
        
    }
    
    // Function to find turn around time for all Process_2es 
    findTurnAroundTime(proc, n, wt, tat); 
  
    // Display Process_2es along with all details 
    //mvprintw(20, 0, "\nProcess_2es Burst time Waiting time Turn around time\n");
     
    
    cout << "\nProcess_2es "<< " Burst time "
         << " Waiting time " << " Turn around time\n"; 
    
    // Calculate total waiting time and total turn 
    // around time 
    for (int i = 0; i < n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
   // mvprintw(50, 0, " %d \t\t %d  \t %d \t\t %d",proc[i].pid,proc[i].bt,wt[i],tat[i]);
	
	cout << " " << proc[i].pid << "\t\t"
             << proc[i].bt << "\t " << wt[i] 
             << "\t\t " << tat[i] <<endl;
    
    } 
    //mvprintw(70, 0,"Avyerage waiting time = %f", (float)total_wt / (float)n); 
   // mvprintw(90, 0,"Avyerage turn time = %f", (float)total_tat / (float)n); 
    
    cout << "Avyerage waiting time = "
         << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "
    << (float)total_tat / (float)n; 

} 

  
// Driver code 
int main_Non_preemptive()
{ 

    Process_2 proc[] = {{1, 10,1}, {2, 4,1}, {3, 7,5}, {4, 5,6},{5,12,15},{6,16,6}};
    int n = sizeof proc / sizeof proc[0]; 
    
    // Sorting Process_2es by burst time. 
    sort(proc, proc + n, comparison); 
    
    

     cout<<"------------------------------------------------------------------------------------\n";
    cout << "Order in which Process_2 gets executed\n"; 
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
