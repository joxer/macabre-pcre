#include "../pcre.h"


int main(){
  
  Regex r("ciao mondo", "\\w");
  r.match();
  cout << r.gsub("a", "ue12") << endl;
  if(r == "\w++")
    cout << ":OOO" << endl;
  else
    cout << "fail\n";
      
  return 0;
}
