#include<iostream>   
#include<stack> 
#include<map> 
#include<unordered_map> 
#include<vector>
#include<string>
#include<future>       
#include<chrono>
#include<thread>      
#include<deque> 
#include<algorithm>
using namespace std;      
class Code_Input {  
  private:
    int n;
    string _queries = "";    
    vector<string> step; 
    deque<string> queries; 
    map<string , map<string , string>> Pre_process; 
    unordered_map<string, map<string, string>> Pro; 
  public:
    Code_Input() = default;
    Code_Input(int amount) :n(amount) {}  
    unordered_map<string, map<string, string>> Get_Pro() {
      return this->Pro; 
    }
    void set_process(string  t1, map<string, string> t) {
      this->Pre_process.insert({t1,t});
    }
    void Set_amount(int amount) {
      this->n = amount;
    }                 
    void Get_IN() {          
      for (int i = 0; i < n; i++) {
        string str = "";
        getline(std::cin >> std::ws, str, '\n');
        Processing_Code_String(str);
      }      
    }          
    void Processing_Code_String(string _Str) {            
      string key_hash = "";
      string temp = "";
      string document = "";
      string key_close = ""; 
      _Str.pop_back();
      map<string, string> HRML_element; 
      int i = 1;      
      if (_Str[i] != '/') {
        for (; i < _Str.size(); i++) {
          if (_Str[i] ==' ') {   
            break;
          }
          else {            
            key_hash += _Str[i];             
          }                   
        }                     
        queries.push_back(key_hash); 
        _Str.erase(remove(_Str.begin(), _Str.end(), ' '), _Str.end());
        _Str.erase(remove(_Str.begin(), _Str.end(), '='), _Str.end()); 
        while (i < _Str.size()) {
          if (_Str[i] != '"') {
            temp += _Str[i];
          }     
          else {
            int j = i + 1;
            for (; j < _Str.size(); j++) {
              if (_Str[j] == '"') {                 
                HRML_element.insert({ temp , document });   
                
                temp = "";
                document = "";
                break;
              }
              else {
                document += _Str[j];
              }
            }
            i = j;
          }
          i++;
        }                 
        set_process(key_hash, HRML_element);
      }     
      else {          
        i= 2 ;
        while (i < _Str.size()) {              
          key_close += _Str[i];   
          i++; 
        }   
        string _temp_top = "";     
        string _temp_queries = "";     
        _temp_top = queries.back();   
        queries.pop_back();               
        deque<string> temp_querie = queries;  
        if (temp_querie.empty()) {
          _temp_queries  += _temp_top;
        }      
        else {
          while (!temp_querie.empty()) {
            if (_temp_queries.size() == 0) {
              _temp_queries += temp_querie.front();
              temp_querie.pop_front();
            }
            else {
              _temp_queries += '.' + temp_querie.front();
              temp_querie.pop_front();
            }
          }
          if (temp_querie.empty()) {
            _temp_queries += '.' + _temp_top;
          }          
        }               
        Pro.insert({ _temp_queries , Pre_process[key_close] }); 
        }                
        return;
      }                                                    
  };     
class Code_Queries:public  Code_Input {
protected : 
  vector<string>  result;       
  vector<pair<string, string>>Pair; 
  int m; 
public :  
  Code_Queries() = default;  
  Code_Queries(int n) :m(n) {      
  }     
  void set_amount(int amoutn) {
    this->m = amoutn; 
  }        
  void get_result() {
    for (auto x : result) {
      cout << x << endl; 
    }
  }  
  void Get_In() {        
    for (int i = 0; i < m; i++) {
      string str = "";
      getline(std::cin >> std::ws, str);
      Process(str);
    }
  }          
  vector<pair<string, string>> get_pair() {
    return Pair; 
  }
  void Set_Process(string key , string data) {           
    key.erase(remove(key.begin(), key.end(), ' '), key.end());
    data.pop_back(); 
    unordered_map<string, map<string, string>>  test = Code_Input::Get_Pro();     
    auto it = test.find(key); 
    if (it != test.end()) {
      if (test[key][data] != "") {
        result.push_back(test[key][data]); 
      }                      
      else {
        result.push_back("Not Found!"); 
      }                   
    }                      
    else {
      result.push_back("Not Found!"); 
    }
  }                   
  void Process(string str) {
    string head = "";
    string tail = "";     
    future<void>Thead_head = async(launch::async, [&head,str]() {
      int i = 0;
      while (i < str.size()) {
        if (str[i] == '~') {
          break;
        }
        head += str[i]; 
        i++; 
      }
    });
    future<void>Thead_tail = async(launch::async, [&tail, str]() {  
      int i = str.size();
      while (i >= 0) {
        if (str[i] == '~') {
          break;
        }
        tail += str[i]; 
        i--; 
      }      
      reverse(tail.begin(), tail.end()); 
    });           
    Thead_tail.get(), Thead_head.get();           
    Set_Process(head, tail); 
    return; 
  }  
};              
class HRML_processing :  virtual public Code_Queries {
private:
  unordered_map<string, map<string, string>> HRML_CODE; 
  int m;  
  int n;    
  vector<string> result; 
  stack<string> Process_CODE;         
public:         
  HRML_processing() = default;
  HRML_processing(int n1, int m1) :n(n1), m(m1) {   
    Code_Input::Set_amount(n); 
    Code_Queries::set_amount(m);     
  }      
  void Input() {    
      Code_Input::Get_IN();       
      Code_Queries::Get_In();     
  }                 
  void Attribue_Parser() {            
    Code_Queries::get_result();  
    return; 
  }
  ~HRML_processing() {}
};                    
int main() {    
  int n = 0; 
  int m = 0;
  cin >> n >> m; 
  HRML_processing k(n, m); 
  k.Input();  
  k.Attribue_Parser();
}
