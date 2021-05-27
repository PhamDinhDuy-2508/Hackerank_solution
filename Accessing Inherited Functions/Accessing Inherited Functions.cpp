

class D :virtual public A, virtual public B, virtual public C 
{

	int val;
public:
  //Initially val is 1   
  int arr[3] = { 2,3,5 };
  D() {
    val = 0;
  }
  int val1 = 0;
  int val2 = 0;
  int val3 = 0;
  //Implement this function
  int devide_5(int new_val, int count) {
    if (new_val % 5 != 0) {
      return 1;
    }
    return devide_5(new_val / 5, count + 1);
  }
  void update_val(int new_vval) {
    int count = 0;
    int VAL = new_vval;  
    val = new_vval;   
    int k = 0; 
    if (new_vval <= 2 || new_vval <=3 || new_vval <= 5) {
      k = 1; 
    }   
    else {
      k = new_vval / 2; 
    }
    static int sum  =1 ;
    for (int i = 0; i < k; i++) {    
      for (int j = 0; j < 3; j++) {            
        if (sum < val){          
          if (j == 0) {
            if (VAL % 2 == 0 && sum < val) {
              if (sum * 2 <= val) {
                A::func(sum);   
                VAL /= 2; 
              }                
            }
            else { continue; }
          }
          else if (j == 1) {      
            if (sum < val && VAL % 3 == 0) {
              if (sum * 3 <= val) {
                B::func(sum);      
                VAL /= 3;
              }
              
            }
            else { continue; }
          }
          else if (j == 2) { 
            if (sum < val&& VAL % 5 == 0) {
              if (sum * 5 <= val) {
                C::func(sum);  
                VAL /= 5;
              }
            }
            else { continue; }
          }
        }   
        else { 
          break; 
        }
      }

    }
  }

  //For Checking Purpose
  void check(int); //Do not delete this line.
};

