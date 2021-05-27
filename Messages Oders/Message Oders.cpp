

class Message {    
private : 
  string text;    
  int oder; 
public:
  Message() {}    
  Message(string _text , int oder) :text(_text) , oder(oder){  
    set_text(_text); 
  }
  const string& get_text() {   
    return this->text;  
  }           
  int get_oder() {
    return this->oder; 
  }
  void set_text(string text) {
    this->text = text;  
    return; 
  }     
  ~Message() {};
};                       
bool operator < (Message   &a, Message   &b) {
  return a.get_oder() < b.get_oder(); 
}
class MessageFactory {                  
private : 
   int oder = 0;
public:       
  MessageFactory() {}         
  void set_oder() {
    this->oder++; 
  }
  Message create_message(const string& text) {      
    set_oder(); 
    Message*TXT = new Message(text , oder);         
    return *TXT; 
  }
};
