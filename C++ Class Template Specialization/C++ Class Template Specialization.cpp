
template<typename T> struct Traits{       
  static string str; 
//  static void set_STR(str); 
   static std::string name(int index){  
    return " "; 
  }        
};           
template<>
std::string Traits<Fruit>::name(int index) {    
   if (index == 0) {  
     return "apple"; 
  }            
   else if (index == 1) {
     return "orange";
   } 
   else if (index == 2) {
     return "pear"; 
   }           
   else {
     return"unknown"; 
   }              
}          
template<>
std::string Traits<Color>::name(int index) {
  if (index == 0) {
    return "red";
  }
  else if (index == 1) {
    return "green";
  }
  else if (index == 2) {
    return "orange";
  }
  else {
    return"unknown";
  }
}
