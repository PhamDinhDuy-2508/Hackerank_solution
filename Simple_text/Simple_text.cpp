#include"pch.h"
#include<iostream>  
#include<vector> 
#include<stack>	 
#include<future> 
#include<unordered_map>		 
#include<algorithm>
#include<utility>		    
#include<string>	
#include<queue>
#include<fstream>			   
using namespace std;    		 
enum class Choice { 
	Append , Delete , Print , Undo 
};
string Split_String(string k); 
class Text_edittor { 
private : 
	vector<string> Text; 
	queue<pair<char, string>> _Text; 	 
	stack<pair< char, string>> Flag;  
	pair<char, string> Temp_flag; 		 
	stack<pair<char , string>> res; 
	string Model; 
public : 
	Text_edittor() = default; 
	Text_edittor( string model , queue<pair<char, string>> text):
		 Model(model) , _Text(text) {
		this->Temp_flag.first = ' ';   
		this->Temp_flag.second = " ";  	  
		this->Model = " "; 
	} 				  	
	void Processing() {					  			 
		Flag.push(make_pair('0', Model)); 	 
		res.push(make_pair('0', Model));
		while (!_Text.empty()) {
			int choice = int(_Text.front().first) - 48; 	 
			switch (choice){
			case 1: {
				res.top().second += _Text.front().second;
				Flag.push(make_pair('1', res.top().second));
				res.push(make_pair('1' , res.top().second));
				_Text.pop();
				break;
			}
			case 2: {				
				string _s = _Text.front().second;
				int _n = stoi(_s);
				string k = res.top().second;								
				k.erase(k.size() - _n);								
				res.push(make_pair('2',k));
				Flag.push(make_pair('2', res.top().second));
				_Text.pop();
				break;
			}
			case 3: {				
				string s = _Text.front().second;
				cout << res.top().second[stoi(s)] << " " << _Text.front().first << " " << _Text.front().second << " " << res.top().second <<" " << res.top().second.size() <<  endl; ;
				_Text.pop();
				break;
			}
			case 4: {
				int count = 0; 
				Flag.pop(); 
				while(res.top().first != Flag.top().first) {  					
					res.pop();		    
				}		 
				res.top().second = Flag.top().second; 
				_Text.pop();
				break;
			}
			default:
				break;
			}
		}
	}
	void Print() {
		while (!_Text.empty()) {	  
			cout << _Text.front().first << " " << _Text.front().second << endl;  
			_Text.pop(); 
		}
	}
	~Text_edittor(){}
};	 

string Split_String(string k) {
	string _Str;
	k.erase(0, 2); 
	return k; 
}
void Read(queue<pair<char,string> >&k  ) {
	ifstream input{ "Testkey2.txt" };       
	int count =  0 ; 
	if (input.fail()) {
		cout << "Fail" << endl; 
	}
	string message;   

	while (getline(input, message)) {  
		if (message[0] != '4') {
			k.push({ message[0] ,  Split_String(message) }); 
		}
		else {
			k.push({ message[0] ,  " " });
		}
	}
	input.close(); 
}			    
void Input(int n, queue<pair<char ,string>> &_check) {
	for (int i = 0; i < n; i++) {
		char  x;
		string  y;
		cin >> x;
		if (x != '4') {
			cin >> y;
			_check.push({ x,y }); 
		}
		else {		
			_check.push({ x," " });
		}
	}
}
int main() { 
	int n;  
	cin >> n;  
	queue<pair<char,string>> ops; 
	Input(n, ops); 		
	Text_edittor*Simple_Text = new Text_edittor("", ops);  
	Simple_Text->Processing(); 
	return 0  ; 	
}	

