#include <iostream>
#include "stack.h"
using namespace std;

int main(){
  Stack<int> s;
  s.push(1);
  s.push(2);
  cout<<"top:" << s.top()<<endl;
  cout<<"size:" << s.size()<<endl;
  cout<<"empty:" << s.empty()<<endl;
  s.pop();
  cout<<"top after pop:" << s.top()<<endl;
  cout<<"size:" << s.size()<<endl;
  try{
    s.pop();
  }
  catch(underflow_error &e){
    cout << "exception" << endl;
  }
  try{
    cout<<"top after pop2:" << s.top()<<endl;
  }
  catch(underflow_error &e){
    cout << "exception" << endl;
  }
  cout<<"size:" << s.size()<<endl;
  cout<<"empty:" << s.empty()<<endl;
}