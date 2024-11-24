#include <iostream>
#include <stdexcept> // For std::runtime_error to throw errors in case of issues.
using namespace std;

const int MAX_SIZE = 100;

template <typename T> 
class H_Stack 
{
private:
T array[MAX_SIZE];
T* top;
T* start;
int size = 0;

public:

H_Stack(){
  top = array;
  start = array;    
}

bool is_full() const {
  return (start + MAX_SIZE == top);
}

bool is_empty() const {
  return (top == start);
}

void push(const T& element) {

  if (!is_full()) {
    *top = element;
    top++;
    size++;
  } 
  else {
    throw std::runtime_error("Stack overflow: Cannot push onto a full stack.");
  }
}

T pop() {
  if (!is_empty()) {
    top--;
    size--;
    return *top;
  }
  else {
      throw std::runtime_error("Stack underflow: Cannot pop from an empty stack.");
  }
}

int get_size() const {
  return size;
}

T peek() const {
  if (!is_empty()) {
    return *(top - 1);
  } 
  else {
    throw std::runtime_error("Stack is empty: Cannot peek.");
  }
}

};

class Dish {
private:
    string description;

public:
    Dish() : description("Unknown dish") {} // Add default constructor
    Dish(string description) {
        this->description = description;
    }

    string get_description() const {
        return this->description;
    }
};

////////////////// --- Driver --- /////////////////
int main() {

  Dish one_dish("A dish with one fish pattern on it");
  Dish two_dish("A dish with two fish patterns on it");
  Dish red_dish("A dish with a red fish pattern on it");
  Dish blue_dish("A dish with a blue fish pattern on it");

  H_Stack<Dish> s1;

  cout << "\nStack size before pushes: " << s1.get_size();

  cout << "\nPushing elements into the stack:";
  cout << "\nPushing: " << one_dish.get_description();
  s1.push(one_dish);
  cout << "\nPushing: " << two_dish.get_description();
  s1.push(two_dish);
  cout << "\nPushing: " << red_dish.get_description();
  s1.push(red_dish);
  cout << "\nPushing: " << blue_dish.get_description();
  s1.push(blue_dish);
  cout << "\nStack size after pushes: " << s1.get_size();

  cout << "\nTop of stack (peek): " << s1.peek().get_description();

  cout << "\nPopping elements from the stack:";
  while (!s1.is_empty()) {
      cout << "\nPopped: " << s1.pop().get_description();
  }

  cout << "\nStack size after pops: " << s1.get_size();
  cout << "\nDemonstration completed. Goodbye.\n";

  return 0;
}