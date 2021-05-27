#include<iostream>     
#include<vector> 
#include<set>         
#include<queue>
#include<future>  
#include<sstream> 
#include<fstream>
#include<map>
#include<string>
using namespace std;
vector<string> split_string(string);

vector<int> create_Zero_vector(int n) {
  vector<int>_vec(n, 0);
  return _vec;
}
void Get_set(int value, set<int> &_set) {
  _set.insert(value);  
  return; 
}
void Map_arr(vector<vector<int>> _vec, map<int, vector<int>> &_map_cvec , int n ) {  
    auto Thread_Test = async(launch::async, create_Zero_vector, ref(n)); 
    _map_cvec.insert({ 0 , Thread_Test.get() }); 
}
long long  arrayManipulation(long n, vector<vector<int>> queries) {
  ///std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
  vector<long long > temp(n + 2, 0);
  future<void> _Thread_3;   
  for (int i = 0; i < queries.size(); i++) {
    long long last_limit = queries[i][0];
    long long  top_limit = queries[i][1] + 1;
    long long data = queries[i][2];
      temp[last_limit] += data;
      temp[top_limit] -= data;
  }            
  //_Thread_3.wait(); 
  long long res = 0;
  long long int compare = INT_MIN; 
  long long sum = 0; 
  for (int i = 0; i < temp.size(); i++) {
    sum += temp[i];
    if (sum > compare) {
      compare = sum;
    }
  }
    using namespace std::chrono;
    ///high_resolution_clock::time_point t2 = high_resolution_clock::now();
    //duration<double>   time = duration_cast<duration<double>>(t2 - t1); 
    //cout << time.count() << endl; 
    return compare;
}