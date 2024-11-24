#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

template <typename T> 
class H_Stack 
{
private:
T array[MAX_SIZE];
T *top;
T *start;

public:

H_Stack(){
    top = array;
    start = array;
}

bool is_full (){
    return (start + MAX_SIZE == top);
}

bool is_empty(){
    return (top == start);
}

void push(T element)
  {
    if (!is_full())
    {
      *top = element;
      top++;
    }
  }

T pop()
  {
    if (!is_empty())
    {
      top--;
      T poppedElement = *top;
      return poppedElement;
    }
    else
    {
      throw "Encountered error during pop operation.";
    }
  }


T peek()
  {
    if (!is_empty())
    {
      top--;
      T poppedElement = *top;
      top++;
      return poppedElement;
    }
    else
    {
      throw "Encountered error during peek operation.";
    }
  }
};

////////////////// --- driver --- /////////////////
int main() {

H_Stack <int> s1;

cout << "\nPushing elements into the stack: 1, 2, 3, 4, 5";
s1.push(1);
s1.push(2);
s1.push(3);
s1.push(4);
s1.push(5);

cout << "\nPeeking! Value: " << s1.peek();

cout << "\nPopping elements from the stack.";
while(!s1.is_empty()){
    cout << "\nPopped: " << s1.pop();
}

cout << "\nDemonstration completed. Good bye.";


}