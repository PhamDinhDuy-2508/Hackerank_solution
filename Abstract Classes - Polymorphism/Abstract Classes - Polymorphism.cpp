
class LRUCache :protected Cache {
private:
  int capacity;
  int count;    
  vector<pair<int, int>> NOde_pair; 
  map<int, int> res_key;      
  map<int, int>key_pos; 

public:

  LRUCache() {};
  LRUCache(int cp) :capacity(cp) {
    
  }
  int get(int key) {
    auto it = res_key.find(key); 
    if (it !=  res_key.end()) {
      return it->second; 
    }
    else {
      return -1;
    }
  }
  void Print_List() {
    while (head != NULL) {
      cout << head->value << "->";
      head = head->next;
    }
  }
  void set(int key, int data) {       
    if (res_key.empty()) {
      NOde_pair.push_back({ key , data });  
      res_key.insert({ key , data });
      key_pos.insert({ key  , 0 }); 
    }  
    else {
      if (res_key.size() < capacity) {
        auto it = res_key.find(key);
        if (it == res_key.end()) {                     
          NOde_pair.push_back({ key , data });  
          res_key.insert({ key , data });            
          key_pos.insert({ key  ,NOde_pair.size()-1 }); 
        }                        
        else {       
          int c = 0;
          for (auto x : NOde_pair) { 
            c++; 
            if (x.first == key) {
              NOde_pair.erase(NOde_pair.begin()+c);  
              break; 
            }                        
          }                            
          NOde_pair.push_back(make_pair(key, data)); 
          it->second = data;                               
        }                
      } 
      else {
        auto it = res_key.find(key);     
        if (it == res_key.end()) { 
          res_key.erase(NOde_pair.begin()->first);  
          NOde_pair.erase(NOde_pair.begin());     
          NOde_pair.push_back(make_pair(key, data));
          res_key.insert({ key , data }); 
        }                   
        else {   
          int c = 0;     
          for (auto x : NOde_pair) {
            c++;
            if (x.first == key) {
              NOde_pair.erase(NOde_pair.begin() + c);
              break;
            }
          }
          NOde_pair.push_back(make_pair(key, data));
          it->second = data;
        }
      }
    }          
    return; 
}
  void print_Map() {
    for (auto x : res_key) {
      cout << x.first << "->" << x.second << endl;
    }
  }
  ~LRUCache() {}
};

