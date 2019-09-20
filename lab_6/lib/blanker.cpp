#include <iostream> 
#include <string.h> 
#include <vector> 
// total number of process 
#define P 4 
// total number of resources 
#define R 3 
  
// total safe-sequences 
int total = 0; 
  
using namespace std; 
  
// function to check if process 
// can be allocated or not 
// Function to find the system is in safe state or not 
bool isSafe(int processes[], int avail[], int maxm[][R], 
            int allot[][R],int need[][R], int work[R],int remid[P][R]) 
{ 
    
  

  
    // Mark all processes as infinish 
    bool finish[P] = {0}; 
  
    // To store safe sequence 
    int safeSeq[P]; 
  
    // Make a copy of available resources 

    for (int i = 0; i < R ; i++) 
        work[i] = avail[i]; 
  
    // While all processes are not finished 
    // or system is not in safe state. 
    int count = 0; 
    while (count < P) 
    { 
        // Find a process which is not finish and 
        // whose needs can be satisfied with current 
        // work[] resources. 
        bool found = false; 
        for (int p = 0; p < P; p++) 
        { 
            // First check if a process is finished, 
            // if no, go for next condition 
            if (finish[p] == 0) 
            { 
                // Check if for all resources of 
                // current P need is less 
                // than work 
                int j; 
                for (j = 0; j < R; j++) 
                    if (need[p][j] > work[j]) 
                        break; 
  
                // If all needs of p were satisfied. 
                if (j == R) 
                { 
                    // Add the allocated resources of 
                    // current P to the available/work 
                    // resources i.e.free the resources 
                    for (int k = 0 ; k < R ; k++) 
                    {
                        work[k] += allot[p][k]; 
                        remid[p][k]=work[k];
                        //cout << work[k];
                    }
                        
  
                    // Add this process to safe sequence. 
                    safeSeq[count++] = p; 
  
                    // Mark this p as finished 
                    finish[p] = 1; 
  
                    found = true; 
                } 
            } 
        } 
  
        // If we could not find a next process in safe 
        // sequence. 
        if (found == false) 
        { 
            cout << "System is not in safe state"; 
            return false; 
        } 
    } 
  
    // If system is in safe state then 
    // safe sequence will be as below 
    cout << "System is in safe state.\nSafe"
         " sequence is: "; 
    for (int i = 0; i < P ; i++) 
        cout << safeSeq[i] << " "; 
  
    return true; 
} 
bool is_available(int process_id, int allocated[][R], 
                  int max[][R], int need[][R], int available[]) 
{ 
  
    bool flag = true; 
  
    // check if all the available resources 
    // are less greater than need of process 
    for (int i = 0; i < R; i++) { 
  
        if (need[process_id][i] > available[i]) 
            flag = false; 
    } 
  
    return flag; 
} 



void display2(int box1[][R], int box2[][R],int box3[][R],int box4[][R]){
    int x,y;

    for(x=0; x<P; x++){
        cout << x<<"\t";
        for(y=0; y<R; y++){
           cout <<box1[x][y];
        }
        printf("\t\t");
        for(y=0; y<R; y++){
           cout << box2[x][y];
        }
        printf("\t");
        for(y=0; y<R; y++){
           cout << box3[x][y];
        }
        printf("\t");
        for(y=0; y<R; y++){
           cout << box4[x][y];
        }
        printf("\n");
    }
}

// Print all the safe-sequences 
void safe_sequence(bool marked[], int allocated[][R], int max[][R], 
                   int need[][R], int available [], vector<int> safe) 
{ 
  
    for (int i = 0; i < P; i++) { 
  
        // check if it is not marked 
        // already and can be allocated 
        if (!marked[i] && is_available(i, allocated, max, need, available)) { 
  
            // mark the process 
            marked[i] = true; 
  
            // increase the available 
            // by deallocating from process i 
            for (int j = 0; j < R; j++) 
            {
                available[j] += allocated[i][j]; 
                cout << available[j];
                cout << "\n";
            }
                
  
            safe.push_back(i); 
            // find safe sequence by taking process i 
            safe_sequence(marked, allocated, max, need, available, safe); 
            safe.pop_back(); 
  
            // unmark the process 
            marked[i] = false; 
  
            // decrease the available 
            for (int j = 0; j < R; j++) 
                available[j] -= allocated[i][j]; 
        } 
    } 
  
    // if a safe-sequence is found, display it 
    if (safe.size() == P) { 
  
        total++; 
        for (int i = 0; i < P; i++) { 
  
            cout << "P" << safe[i] + 1; 
            if (i != (P - 1)) 
             cout << "--> "; 
        } 
  
        cout << endl; 
    } 
} 
  
// Driver Code 
int blanker() 
{ 
  
    // allocated matrix of size P*R 
    int allocated[P][R] = { { 1, 0, 1 }, 
                            { 4, 5, 2 }, 
                            { 5, 3, 5 }, 
                            { 0, 6, 3 } }; 
  
    // max matrix of size P*R 
    int max[P][R] = { { 4, 0, 1 }, 
                      { 6, 7, 3 }, 
                      { 8, 3, 5 }, 
                      { 7, 6, 5 } }; 
  
    // Initial total resources 
    int resources[R] = { 10, 5, 7 }; 
    int processes[P]={1,2,3,4};
    // available vector of size R 
    int available[P][R]; 
    int j=0;
    for (int i = 0; i < R; i++) { 
  
        int sum = 0; 
        for ( j = 0; j < P; j++) {
            sum += allocated[j][i]; 
        }
            
  
        available[i][j] = resources[i] - sum; 
        //cout <<  available[i][j];
    } 
    
  
    // safe vector for displaying a safe-sequence 
    vector<int> safe; 
   
    // marked of size P for marking allocated process 
    bool marked[P]; 
    memset(marked, false, sizeof(marked)); 
    int avail[] = {2, 2, 2};
    // need matrix of size P*R 
    int need[P][R]; 
    for (int i = 0; i < P; i++) 
        for (int j = 0; j < R; j++) 
            need[i][j] = max[i][j] - allocated[i][j]; 
     int work[R];
     int remid[P][R];
    cout << "Safe sequences are:" << endl; 
    isSafe(processes, avail, max, allocated,need,work,remid); 
    //safe_sequence(marked, allocated, max, need, avail, safe); 
    cout << "\nprocess\t"
        <<"allocated\t"
        <<"Max\t"
        <<"need\t"
        <<"avail\t"
        <<"\n";
    display2(allocated,max,need,remid);
    //cout << "\nThere are total " << total << " safe-sequences" << endl; 
    return 0; 
} 
