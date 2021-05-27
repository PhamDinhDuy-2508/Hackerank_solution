
class Work_shop {
private : 
  vector<int>  The_workshop_s_start_tie; 
  vector<int> The_workshop_s_duration; 
  vector<int> The_workshop_s_end_time;     
public : 
  Work_shop() = default;          
  Work_shop(vector<int>  The_workshop_s_start_tie1, vector<int> The_workshop_s_duration1) {
    this->The_workshop_s_duration = The_workshop_s_duration1;  
    this->The_workshop_s_start_tie = The_workshop_s_start_tie1; 
  }                      
  int get_Work_Shop_Start_time() {
    return this->The_workshop_s_duration.size();  
  }                           
  int get_WorkP_Shop_durrnet_time() {
    return this->The_workshop_s_duration.size(); 
  }               
  vector<int> get_durent_time() {
    return this->The_workshop_s_duration; 
  }       
  vector<int> get_Start_time() {
    return this->The_workshop_s_start_tie; 
  }
  ~Work_shop() {};
};                       
class Available_Workshops :public Work_shop {      
  friend Work_shop; 
private :  
  vector<Work_shop> Workshop;    
public :                   
  Available_Workshops() = default;     
  Available_Workshops(Work_shop c ){  
    this->Workshop.push_back(c); 
  }                   
  int get_Availble_workShop_size() {
    return  this->Workshop.at(0).get_Start_time().size();
  }             
   vector<int> get_Start_time() {     
     return this->Workshop.at(0).get_Start_time();
  }
  vector<int> get_durent_time() {
    return this->Workshop.at(0).get_durent_time(); 
  }
}; 
Available_Workshops* initialize(int start_time[], int duration[], int n) {      
  vector<int> T_W_S(start_time, start_time + n);        
  //vector<int>T_W_D;                            
  vector<int> T_W_D(duration, duration + n);                   
  Work_shop c(T_W_S, T_W_D);         
  Available_Workshops*A_W = new   Available_Workshops(c); 
  return A_W; 
}   

Available_Workshops* initialize(vector<int> start_time, vector<int> duration) {  
  Work_shop c(start_time, duration);
  Available_Workshops*A_W = new   Available_Workshops(c);
  return A_W;
}            
int  CalculateMaxWorkshops(Available_Workshops*_pre_work_shop) {         
//  using namespace std::chrono;  
  //high_resolution_clock::time_point t1 = high_resolution_clock::now(); 
  int count = 0;     
  int first = 0; 
  int n = _pre_work_shop->get_Availble_workShop_size(); 
  vector<int> Durrent = _pre_work_shop->get_durent_time();
  vector<int> Start = _pre_work_shop->get_Start_time();
  vector<pair<int, int>>  _Pair;                 
  _Pair.push_back({ 0, 0 });
  for (int i = 0; i < n; i++) {
    pair<int, int> k;  
    k.first = Start[i];  
    k.second = Durrent[i] + Start[i] ; 
    _Pair.push_back(k);    
  }    //Thread1.get();    
  sort(_Pair.begin(), _Pair.end(), [](const pair<int, int> &a, const pair<int, int> &b) {     
    return a.second < b.second;
  });      
  for (int i = 1; i < _Pair.size(); i++) {   
    if (_Pair[i].first >= first) { 
      if (_Pair[i].first > _Pair[i - 1].first) {
        count++;  
        first = _Pair[i].second; 
      }                
      else { continue;  }      
    }              
    else { continue;  }    
  }                   
  //high_resolution_clock::time_point t2 = high_resolution_clock::now();  
  //duration<double> time = duration_cast<duration<double>> (t2 - t1);  
  //cout << time.count() << endl; 
  return  count ;
  }                     
