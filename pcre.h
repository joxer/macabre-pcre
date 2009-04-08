#include <pcre.h>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

class pos{
public:
  int s;
  int e;

  pos(int _s, int _e): s(_s), e(_e){};
 

};

class Regex{

  string pattern;
  string string_to_match;
 

  char* error;
  pcre* pc;
  int err_off;
  
  vector<pos> position;
public:
  Regex(string _ex, string pat){
    
    pattern = pat;
    string_to_match = _ex;
    pc = pcre_compile(pattern.c_str(),  0 , (const char **)&error, &err_off, NULL); 
    //last_offset = 0;
    
  };
  /* version with start by an offset */
  
  int match(int offset = 0){
    size_t length = NULL;
    pcre_fullinfo(pc, NULL,  PCRE_INFO_SIZE, &length);
    int *s = new int[(length = (3 * length +1))];

    int result = 1;

    while((result = pcre_exec(pc, NULL, string_to_match.c_str(), string_to_match.length(), offset,0, s, length)) > 0){

      offset = s[1];
      pos r(s[0], s[1]);
      position.push_back(r);
    }
    return position.size();


  }
  //    cout << string_to_match.substr(0,2) << endl;
  
  
  vector<string> get(){
    vector<string> tmp;
    for(unsigned int i = 0; i < position.size() ; i++){
      tmp.push_back(string_to_match.substr(position[i].s, position[i].e - position[i].s)); 
    }
    return tmp;
  };
  
  
  Regex reset(string new_string, string new_regex){
  
  
    pattern = new_regex;
    string_to_match = new_string;
    
    error = NULL;
    memset(pc, '\0', sizeof(pc));
    err_off = 0;
    pc = pcre_compile(pattern.c_str(),  0 , (const char **)&error, &err_off, NULL); 
    return *this;
  };
  
  vector<string> split(string what){
    
    Regex r(string_to_match, "[^" +what + "]+");
    vector<string> tmp = r.get();
    r.match();
    return r.get();
      
    
  };

  string gsub(string what, string with){
    
    string tmp = string_to_match;
    int i = 0;
    while((i = tmp.find(what)) != string::npos){
      tmp.replace(i, what.size(), with);
    }
    return tmp;
  }
};
