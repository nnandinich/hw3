#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()): m_(m), c_(c){
    if(m_<2){
      throw std::invalid_argument("Heap branching needs to be larger than 2.");
    }
  }

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap() {}

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> x;
  int m_;
  PComparator c_;



};

// Add implementation of member functions here
//empty implementation
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return x.empty();
}

//size implementation
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return x.size();
}

//push implementation
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  x.push_back(item);
  int pos= (int)x.size()-1;
  //need to trickle up
  while(pos>0){
    int parent = (pos-1)/m_;
    if(c_(x[pos], x[parent])){
      T temp = x[pos];
      x[pos]=x[parent];
      x[parent]=temp;
      pos=parent;
    }
    else{
      break;
    }
  }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return x.front();


}


// We will start pop() for you to handle the case of 
// calling pop on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
     throw std::underflow_error("heap is empty");
  }
  x[0]=x.back();
  x.pop_back();
  int s_ = int(x.size());
  //if only one element
  if(empty()){
    return;
  }

  int pos =0;
  //need to trickle down
  while(((m_*pos)+1)<s_){
    //need to find child that will be swapped
    int swapChildIndex=(m_*pos)+1;
    for(int i=1; i<m_; i++){
      if(((m_*pos)+1+i)<s_){
        int child=(m_*pos)+1+i;
        if(c_(x[child], x[swapChildIndex])){
          swapChildIndex= child;
        }
      }
    }
    if(c_(x[swapChildIndex], x[pos])){
      T temp= x[pos];
      x[pos]=x[swapChildIndex];
      x[swapChildIndex]=temp;
      pos=swapChildIndex;
    }
    //everything is in order
    else{
      break;
    }
  }
}



#endif

