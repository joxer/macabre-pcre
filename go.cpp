#include <pcre.h>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <regex.h>





using namespace std;


int main(){
  
  Regex r("ciao mondo", "\\w");
  r.match(0);
  cout << r.gsub("a", "ue12") << endl;
  if(r == "\\w++")
    cout << ":OOO" << endl;
  else
    cout << "fail\n";
      
  return 0;
}
