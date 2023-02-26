#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>

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
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

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
  size_t heapSize;  //size of heap
  std::vector<T> vechp; //set heap as a vector
  unsigned int m;
  PComparator c;
  //checks whether the element at that index violates the heap property
  void heapify(int index);
  // returns the index of the parent of the element at index i in the heap
  int parent (int i) {
    return(i-1)/m;
  }


};

// Add implementation of member functions here
template<typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
  heapSize=0;
  this->m=m;
  this->c=c;
}

template<typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){}

template<typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return heapSize;
}

template<typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  return (heapSize==0);
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
    throw std::underflow_error("Empty Heap");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  else{
    return vechp[0];
  }


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty Heap");

  }
  vechp[0]=vechp[heapSize-1];
  heapSize--;
  vechp.pop_back();
  heapify(0);

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify(int index){
    int smallestIndex = index;
    for(unsigned int i = 1; i <= m; i++){
        // Compute the index of the right child of the current node.
        unsigned int rightChildIndex = m * index + i;
        // Check if the right child exists and is smaller than the current smallest element.
        if(rightChildIndex < heapSize && c(vechp[rightChildIndex], vechp[smallestIndex])){
            smallestIndex = rightChildIndex;
        }
    }
    // If the smallest element is not the current element, swap them and recursively heapify the affected subtree.
    if(smallestIndex != index){
          std::swap(vechp[index], vechp[smallestIndex]);
          heapify(smallestIndex);
    }
}



template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
    // Add the new item to the end of the vector and increase heap size
    vechp.push_back(item);
    heapSize++;

    // Set the index of the inserted element
    int i = heapSize - 1;

    // Loop until the element is at its correct position
    for (; i != 0 && c(vechp[i], vechp[parent(i)]); i = parent(i)) {
        // Swap the element with its parent if the element is smaller 
        // or max heap than its parent
        std::swap(vechp[i], vechp[parent(i)]);
    }
}



#endif

