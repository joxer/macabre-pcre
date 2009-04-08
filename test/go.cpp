#include "../pcre.h"


int main(){
  
  Regex r("ciao mondo ciao asd D:", "\\d");
  vector<string> s = r.split("") ;
  
  for(int i= 0; i < s.size() ;i++)
    cout << s[i] << endl;
  
  cout << r.gsub("a", "ua") << endl;

  return 0;
}
