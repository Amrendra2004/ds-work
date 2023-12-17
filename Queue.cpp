#include <iostream>
#include <queue>

using namespace std;

int main() {
  // Create a queue
  queue<int> myQueue;

  // Enqueue elements
  myQueue.push(1);
  myQueue.push(2);
  myQueue.push(3);

  // Display the queue
  cout << "Queue Elements: ";
  while (!myQueue.empty()) {
    cout << myQueue.front() << " ";
    myQueue.pop();
  }
  cout << endl;

  // Check if the queue is empty
  if (myQueue.empty()) {
    cout << "Queue is empty!" << endl;
  } else {
    cout << "Queue is not empty." << endl;
  }

  // Accessing front element (without removing)
  cout << "Front element: " << myQueue.front() << endl;

  // Dequeue and display removed element
  int removedElement = myQueue.front();
  myQueue.pop();
  cout << "Removed element: " << removedElement << endl;

  // Display the size of the queue
  cout << "Queue size: " << myQueue.size() << endl;

  return 0;
}
