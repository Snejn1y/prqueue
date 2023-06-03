# Queue and Priority Queue Operations

This code demonstrates the implementation of queue and priority queue operations in C++. It provides functions for pushing and popping elements from a queue, as well as functions for calculating the average arithmetic of multiple queues.

## Queue Operations

The following functions are available for queue operations:

- `push(queue& q, int value)`: Pushes an element with the given value to the queue.
- `pop(queue& q, int& value)`: Pops the front element from the queue and returns it.
- `clear(queue& q)`: Clears all elements from the queue.
- `print(queue*& q, int n)`: Prints the contents of the given array of queues.
- `size(const queue& q)`: Returns the size of the queue.
- `copy(const queue& q)`: Creates and returns a copy of the given queue.
- `sum(queue& q, int& n)`: Calculates the sum of elements in the queue and updates the count of elements.
- `avgN(queue*& q, int n)`: Calculates the average arithmetic of multiple queues.

## Priority Queue Operations

The following functions are available for priority queue operations:

- `push(priority_queue& q, const int& value, const unsigned int& priority_value)`: Pushes an element with the given value and priority to the priority queue.
- `pop(priority_queue& q, int& out)`: Pops the element with the highest priority from the priority queue and returns it.
- `clear(priority_queue& q)`: Clears all elements from the priority queue.
- `print(priority_queue*& q, int n)`: Prints the contents of the given array of priority queues.
- `size(priority_queue& q)`: Returns the size of the priority queue.
- `copy(const priority_queue& pq)`: Creates and returns a copy of the given priority queue.
- `sum(priority_queue& q, int& n)`: Calculates the sum of elements in the priority queue and updates the count of elements.
- `avgN(priority_queue*& q, int n)`: Calculates the average arithmetic of multiple priority queues.

## Main Function

The `main` function presents a menu with the following options:

1. Work with a queue.
2. Work with a priority queue.
3. Analyze all algorithms.
4. Exit the program.

Depending on the selected option, the program executes the corresponding functionality.

### Menu Options

1. Work with a Queue:
   - Prompts the user to enter the number of queues and the number of elements.
   - Allows the user to input values for the queues or generate random values.
   - Prints the entered or generated queues.
   - Calculates the average arithmetic of the queues.

2. Work with a Priority Queue:
   - Prompts the user to enter the number of priority queues and the number of elements.
   - Allows the user to input values and priorities for the priority queues or generate random values.
   - Prints the entered or generated priority queues.
   - Calculates the average arithmetic of the priority queues.

3. Analyze All Algorithms:
   - Performs a series of tests on the queue and priority queue algorithms.
   - Measures the time taken to calculate the average arithmetic for varying queue sizes.
   - Writes the test results to separate text files.

4. Exit: Ends the program.

---

This is the overview of the provided code and its functionalities. Feel free to explore and modify it as needed.
