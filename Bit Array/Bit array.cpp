#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  unsigned long long  P;     
  unsigned long long N;       
  unsigned long long S;      
  unsigned long long Q;             
  cin >>  N >> S >> P >> Q;    
  unsigned long long check = pow(2, 31);
  unsigned long long  temp = S;
  unsigned long long   count = 1;      
  for (unsigned long long i = 1; i < N; i++) {    
   unsigned long long  ans = (temp * P + Q)%check;  
    if (temp == ans) { 
      break; 
    }
    temp = ans;    
    count++;       
  }              
  cout << count; 
  return  0; 
  
}

