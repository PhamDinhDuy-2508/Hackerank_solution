#include"pch.h"	  
#include<iostream> 
#include<stack>
#include<vector>	    
#include<set>			 
#include<thread>
#include<future>	 
#include<thread>
#include<string> 
#include<fstream> 
#include<sstream>
using namespace std;  
void Read(vector<vector<int>> &_Text) {
	ifstream input("Test_key5.txt");
	string message;
	if (input.fail()) {
		cout << "Fail ";
		return;
	}
	int count = 0;
	while (getline(input, message)) {		
			stringstream lineStream(message);
			int value;
			vector<int> data;
			while (lineStream >> value) {
				data.push_back(value);
			}
			_Text.push_back(data);		
	}
}
int _Pre_count(int i, vector<int> h) { 
	int count = 0; 	    
	int data = h[i]; 
	for (int j = i; j >= 0; j--) {
		if (h[j] < data) {
			return count; 
		}				   
		count++; 
	}
	return count; 
}	 
void int_pre(vector<int> h , vector<int> &res) {	   
	int count = 0; 	   
	for (int i = 0; i < h.size(); i++) {		  
		res.push_back(_Pre_count(i, h)-1); 
	} 	  
}
long _largestRectangle(vector<int> h) {  
	stack<int> _STACK;  
	set<int > _SET;    
	vector<thread> _Thread1;    
	vector<int>  THread_res;   
	_Thread1.emplace_back([ h  ,  &THread_res  ]() {   
		int_pre(h, THread_res); 
	});
	vector<int> res_count; 
	int count1 = 0;
	for (int i = 0; i < h.size(); i++) {  
		_STACK.push(h[i]); 	  
		int  count = 0;		 			
		int data =  h[i]; 		
		for (int j = i; j < h.size(); j++) {
			if (h[j] >= _STACK.top()) {
				count++; 
			}	 		 
			else {
				break; 
			}
		} 			 
		res_count.push_back( (count) );  
	}		 
	for (auto &x : _Thread1) {	 
		x.join(); 
	}		   	    
	for (int i = 0; i < h.size(); i++) {
		_SET.insert(h[i] * (THread_res[i] + res_count[i])); 
	}
	return *_SET.rbegin(); 
}			 
int main() {	  
	vector<vector<int>> k; 
	Read( k ); 	
	cout << k[0].size() << endl; 
	cout << _largestRectangle(k[0]); 
	return  0; 
}
