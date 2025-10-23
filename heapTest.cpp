#include "heap.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
  Heap <int> minHeap;
  minHeap.push(3);
  minHeap.push(7);
  minHeap.push(2);
  minHeap.push(8);
  minHeap.push(1);

  cout << "MINHEAP " << endl;
  cout << "top: "<< minHeap.top() << endl;
  while(minHeap.empty()!=true){
    cout << "top: "<< minHeap.top() << endl;
    minHeap.pop();
  }

  Heap <int, std::greater<int>> maxHeap;
  cout << "MAXHEAP " << endl;
  maxHeap.push(3);
  maxHeap.push(7);
  maxHeap.push(2);
  maxHeap.push(8);
  maxHeap.push(1);
  cout << "top: "<< maxHeap.top() << endl;
  while(maxHeap.empty()!=true){
    cout << "top: "<< maxHeap.top() << endl;
    maxHeap.pop();
  }

  Heap <string> stringHeap;
  cout << "STRINGHEAP " << endl;
  stringHeap.push("flour");
  stringHeap.push("eggs");
  stringHeap.push("sugar");
  stringHeap.push("vanilla");
  stringHeap.push("lemon");
  cout << "top: "<< stringHeap.top() << endl;
  while(stringHeap.empty()!=true){
    cout << "top: "<< stringHeap.top() << endl;
    stringHeap.pop();
  }
  return 0;


}

