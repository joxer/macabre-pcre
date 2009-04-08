#include "../pcre.h"


int main(){
  
  Regex r("ciao mondo", "\\w");
  r.match();
  cout << r.gsub("a", "ue12") << endl;

  return 0;
}
