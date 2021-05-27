#include <bits/stdc++.h>

using namespace std;

int IdBracket(char _char) { 
  if(_char == '(') return 1 ;  
  else if (_char == '[') return 2 ;  
  else if(_char == '{') return 3 ;  
  else if(_char == ')') return 4 ;  
  else if(_char == ']') return 5 ;  
  else if (_char == '}') return 6 ;  
  else return 0 ; 
} 
int checkCoupe(char x , char y) { 
  if(x == '(' && y == ')') return 1 ;  
  else if(x == '['  && y == ']') return 1 ; 
  else if(x == '{' && y == '}') return 1 ; 
  else return 0 ; 
} 
bool check(string bracket) { 
  stack<int>_stack ;  
  char element ;  
  int i= 0 ;  
  while(bracket[i]) { 
    if(IdBracket(bracket[i]) == 1 ||  IdBracket(bracket[i]) == 2 || IdBracket(bracket[i]) == 3)  _stack.push(bracket[i]) ;  
    else if (IdBracket(bracket[i]) == 4 ||  IdBracket(bracket[i]) == 5 || IdBracket(bracket[i]) == 6 ) { 
    if(_stack.empty()) return false ; 
      element = _stack.top() ;  
      _stack.pop() ;   
      if(checkCoupe(element, bracket[i]) == 0 ) return false ; 

    }
    else return true ; 
    i++ ; 
  } 
   if(_stack.empty() == true ) return true ; 
   else { return false  ; }  
} 
string isBalanced(string &s) { 
  if(check(s) == true ) return "YES" ;  
  else return "NO" ; 
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
