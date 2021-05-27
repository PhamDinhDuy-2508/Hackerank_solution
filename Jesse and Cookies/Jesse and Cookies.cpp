#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the cookies function below.
 */
int cookies(int k, vector<int> vec) {
    int step  = 0  ; 
  int valtop = 0 ; 
  priority_queue<int,vector<int>, greater<int>> Pq ;  
  for(auto x :  vec ) { 
    Pq.push(x) ; 
  }   
   if(k< Pq.top()) return 0 ; 
  while(!Pq.empty()) { 
    int val1 = Pq.top() ;  
    Pq.pop() ;    
    int val2 = Pq.top() ;  
    if(!Pq.empty()) Pq.pop() ;  
    else { 
      valtop = val1 ; 
      break  ; 
    } 
    if (val1 <=  k || val2 <= k  ) { 
       valtop = val1+val2*2 ;   
      Pq.push(valtop) ; 
      step++ ; 
    } 
    else { 
      break  ; 
    } 
    } 
    if(valtop <  k  ) { 
      return -1 ; 
    } 
    return step ; 
}