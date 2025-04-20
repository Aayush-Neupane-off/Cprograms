//infix to postfix
// #include <iostream>
// #include <stack>
// #include <cstring>
// #include <cctype>

// using namespace std;

// // Function to determine the precedence of operators
// int precedence(char op) {
//     if (op == '+' || op == '-')
//         return 1;
//     else if (op == '*' || op == '/')
//         return 2;
//     return 0;
// }

// // Function to convert infix expression to postfix expression
// void infixToPostfix(const char* infix, char* postfix) {
//     stack<char> st;
//     int i, k;
//     for (i = 0, k = -1; infix[i]; ++i) {
//         // If the scanned character is an operand, add it to output
//         if (isalnum(infix[i]))
//             postfix[++k] = infix[i];
//         // If the scanned character is '(', push it to the stack
//         else if (infix[i] == '(')
//             st.push(infix[i]);
//         // If the scanned character is ')', pop and output from the stack
//         // until an '(' is encountered
//         else if (infix[i] == ')') {
//             while (!st.empty() && st.top() != '(') {
//                 postfix[++k] = st.top();
//                 st.pop();
//             }
//             if (!st.empty() && st.top() != '(')
//                 return; // Invalid expression
//             else
//                 st.pop();
//         }
//         // An operator is encountered
//         else {
//             while (!st.empty() && precedence(infix[i]) <= precedence(st.top())) {
//                 postfix[++k] = st.top();
//                 st.pop();
//             }
//             st.push(infix[i]);
//         }
//     }

//     // Pop all the operators from the stack
//     while (!st.empty()) {
//         postfix[++k] = st.top();
//         st.pop();
//     }
//     postfix[++k] = '\0';
// }

// int main() {
//     const int MAX_SIZE = 100;
//     char infix[MAX_SIZE], postfix[MAX_SIZE];
    
//     cout << "Enter an infix expression: ";
//     cin.getline(infix, MAX_SIZE);
    
//     infixToPostfix(infix, postfix);
    
//     cout << "Postfix expression: " << postfix << endl;
    
//     return 0;
// }

// to evaluate postfix expression 
// #include <iostream>
// #include <stack>
// #include <cstring>
// #include <cctype>
// #include <cstdlib>

// using namespace std;

// // Function to evaluate postfix expression
// int evaluatePostfix(const char* postfix) {
//     stack<int> st;
//     int i;

//     // Traverse through every character of input expression
//     for (i = 0; postfix[i]; ++i) {
//         // If the scanned character is an operand (number), push it to the stack
//         if (isdigit(postfix[i])) {
//             st.push(postfix[i] - '0'); // Convert char to int
//         }
//         // If the scanned character is an operator, pop two elements from stack and apply the operator
//         else {
//             int operand2 = st.top();
//             st.pop();
//             int operand1 = st.top();
//             st.pop();
//             switch (postfix[i]) {
//                 case '+': st.push(operand1 + operand2); break;
//                 case '-': st.push(operand1 - operand2); break;
//                 case '*': st.push(operand1 * operand2); break;
//                 case '/': st.push(operand1 / operand2); break;
//             }
//         }
//     }
//     // Top of 'st' contains the result, return it
//     return st.top();
// }

// int main() {
//     const int MAX_SIZE = 100;
//     char postfix[MAX_SIZE];
    
//     cout << "Enter a postfix expression: ";
//     cin.getline(postfix, MAX_SIZE);
    
//     int result = evaluatePostfix(postfix);
    
//     cout << "Result of postfix expression: " << result << endl;
    
//     return 0;
// }


//Queue as an ADT 
// #include <iostream>
// using namespace std;

// #define MAX_SIZE 100

// class Queue {
// private:
//     int front, rear;
//     int arr[MAX_SIZE];

// public:
//     Queue() {
//         front = -1;
//         rear = -1;
//     }

//     bool isEmpty() {
//         return (front == -1 && rear == -1);
//     }

//     bool isFull() {
//         return (rear + 1) % MAX_SIZE == front ? true : false;
//     }

//     void enqueue(int x) {
//         if (isFull()) {
//             cout << "Error: Queue is full\n";
//             return;
//         } else if (isEmpty()) {
//             front = rear = 0;
//         } else {
//             rear = (rear + 1) % MAX_SIZE;
//         }
//         arr[rear] = x;
//         cout << x << " enqueued into the queue\n";
//     }

//     void dequeue() {
//         if (isEmpty()) {
//             cout << "Error: Queue is empty\n";
//             return;
//         } else if (front == rear) {
//             cout << arr[front] << " dequeued from the queue\n";
//             front = rear = -1;
//         } else {
//             cout << arr[front] << " dequeued from the queue\n";
//             front = (front + 1) % MAX_SIZE;
//         }
//     }

//     int peek() {
//         if (isEmpty()) {
//             cout << "Error: Queue is empty\n";
//             return -1;
//         }
//         return arr[front];
//     }

//     void display() {
//         if (isEmpty()) {
//             cout << "Queue is empty\n";
//             return;
//         }
//         cout << "Queue elements: ";
//         int i = front;
//         while (i != rear) {
//             cout << arr[i] << " ";
//             i = (i + 1) % MAX_SIZE;
//         }
//         cout << arr[rear] << endl;
//     }
// };

// int main() {
//     Queue q;

//     int choice, item;

//     do {
//         cout << "\n---------------------" << endl;
//         cout << "Queue Operations Menu" << endl;
//         cout << "---------------------" << endl;
//         cout << "1. Enqueue" << endl;
//         cout << "2. Dequeue" << endl;
//         cout << "3. Peek" << endl;
//         cout << "4. Display" << endl;
//         cout << "5. Exit" << endl;
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Enter element to enqueue: ";
//                 cin >> item;
//                 q.enqueue(item);
//                 break;
//             case 2:
//                 q.dequeue();
//                 break;
//             case 3:
//                 cout << "Front element: " << q.peek() << endl;
//                 break;
//             case 4:
//                 q.display();
//                 break;
//             case 5:
//                 cout << "Exiting program\n";
//                 break;
//             default:
//                 cout << "Invalid choice\n";
//                 break;
//         }
//     } while (choice != 5);

//     return 0;
// }

// #include <iostream>
// using namespace std;

// #define MAX_SIZE 5 // Maximum size of the circular queue

// class CircularQueue {
// private:
//     int front, rear;
//     int arr[MAX_SIZE];

// public:
//     CircularQueue() {
//         front = -1;
//         rear = -1;
//     }

//     bool isEmpty() {
//         return (front == -1 && rear == -1);
//     }

//     bool isFull() {
//         return (rear + 1) % MAX_SIZE == front ? true : false;
//     }

//     void enqueue(int x) {
//         if (isFull()) {
//             cout << "Error: Queue is full\n";
//             return;
//         } else if (isEmpty()) {
//             front = rear = 0;
//         } else {
//             rear = (rear + 1) % MAX_SIZE;
//         }
//         arr[rear] = x;
//         cout << x << " enqueued into the queue\n";
//     }

//     void dequeue() {
//         if (isEmpty()) {
//             cout << "Error: Queue is empty\n";
//             return;
//         } else if (front == rear) {
//             cout << arr[front] << " dequeued from the queue\n";
//             front = rear = -1;
//         } else {
//             cout << arr[front] << " dequeued from the queue\n";
//             front = (front + 1) % MAX_SIZE;
//         }
//     }

//     int peek() {
//         if (isEmpty()) {
//             cout << "Error: Queue is empty\n";
//             return -1;
//         }
//         return arr[front];
//     }

//     void display() {
//         if (isEmpty()) {
//             cout << "Queue is empty\n";
//             return;
//         }
//         cout << "Queue elements: ";
//         int i = front;
//         do {
//             cout << arr[i] << " ";
//             i = (i + 1) % MAX_SIZE;
//         } while (i != (rear + 1) % MAX_SIZE);
//         cout << endl;
//     }
// };

// int main() {
//     CircularQueue q;

//     int choice, item;

//     do {
        
//         cout << "What operation do you want to perform?" << endl;
//         cout << "1. Enqueue" << endl;
//         cout << "2. Dequeue" << endl;
//         cout << "3. Peek" << endl;
//         cout << "4. Display" << endl;
//         cout << "5. Exit" << endl;
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Enter element to enqueue: ";
//                 cin >> item;
//                 q.enqueue(item);
//                 break;
//             case 2:
//                 q.dequeue();
//                 break;
//             case 3:
//                 cout << "Front element: " << q.peek() << endl;
//                 break;
//             case 4:
//                 q.display();
//                 break;
//             case 5:
//                 cout << "Exiting program\n";
//                 break;
//             default:
//                 cout << "Invalid choice\n";
//                 break;
//         }
//     } while (choice != 5);

//     return 0;
// }

// Implementation of singly linked list

// #include <iostream>

// using namespace std;

// // Define a node structure for the linked list
// struct Node {
//     int data;
//     Node* next;
// };

// // Define a singly linked list class
// class LinkedList {
// private:
//     Node* head;

// public:
//     // Constructor
//     LinkedList() {
//         head = nullptr;
//     }

//     // Destructor to free allocated memory
//     ~LinkedList() {
//         Node* current = head;
//         Node* next;
//         while (current != nullptr) {
//             next = current->next;
//             delete current;
//             current = next;
//         }
//         head = nullptr;
//     }

//     // Function to append a new node at the end of the list
//     void append(int value) {
//         Node* new_node = new Node();
//         new_node->data = value;
//         new_node->next = nullptr;

//         if (head == nullptr) {
//             head = new_node;
//         } else {
//             Node* current = head;
//             while (current->next != nullptr) {
//                 current = current->next;
//             }
//             current->next = new_node;
//         }
//     }

//     // Function to prepend a new node at the beginning of the list
//     void prepend(int value) {
//         Node* new_node = new Node();
//         new_node->data = value;
//         new_node->next = head;
//         head = new_node;
//     }

//     // Function to insert a new node after the first occurrence of a specified value
//     void insertByKey(int valueToFind, int valueToInsert) {
//         Node* new_node = new Node();
//         new_node->data = valueToInsert;

//         if (head == nullptr) {
//             cout << "List is empty. Cannot insert into an empty list." << endl;
//             delete new_node;
//             return;
//         }

//         Node* current = head;
//         while (current != nullptr && current->data != valueToFind) {
//             current = current->next;
//         }

//         if (current == nullptr) {
//             cout << "Value not found in the list. Cannot insert." << endl;
//             delete new_node;
//             return;
//         }

//         new_node->next = current->next;
//         current->next = new_node;
//     }

//     // Function to delete the first occurrence of a node with a specified value
//     void deleteByKey(int valueToDelete) {
//         if (head == nullptr) {
//             cout << "List is empty. Cannot delete from an empty list." << endl;
//             return;
//         }

//         Node* current = head;
//         Node* previous = nullptr;

//         // If the node to delete is the head node
//         if (current != nullptr && current->data == valueToDelete) {
//             head = current->next;
//             delete current;
//             return;
//         }

//         // Traverse the list to find the node with the value to delete
//         while (current != nullptr && current->data != valueToDelete) {
//             previous = current;
//             current = current->next;
//         }

//         // If the value was not found
//         if (current == nullptr) {
//             cout << "Value not found in the list. Cannot delete." << endl;
//             return;
//         }

//         // Unlink the node from the linked list
//         previous->next = current->next;
//         delete current;
//     }

//     // Function to update the value of the first occurrence of a specified value
//     void updateByKey(int oldValue, int newValue) {
//         Node* current = head;

//         while (current != nullptr && current->data != oldValue) {
//             current = current->next;
//         }

//         if (current == nullptr) {
//             cout << "Value not found in the list. Cannot update." << endl;
//             return;
//         }

//         current->data = newValue;
//     }

//     // Function to print the elements of the linked list
//     void display() {
//         Node* current = head;
//         while (current != nullptr) {
//             cout << current->data << " -> ";
//             current = current->next;
//         }
//         cout << "NULL" << endl;
//     }
// };

// int main() {
//     LinkedList list;

//     int choice, value, position, key;

//     while (true) {
//         cout << "What operations do you want to perform?\n";
//         cout << "1. Append\n";
//         cout << "2. Prepend\n";
//         cout << "3. Insert by key\n";
//         cout << "4. Delete by key\n";
//         cout << "5. Update by key\n";
//         cout << "6. Display list\n";
//         cout << "7. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Enter value to append: ";
//                 cin >> value;
//                 list.append(value);
//                 break;
//             case 2:
//                 cout << "Enter value to prepend: ";
//                 cin >> value;
//                 list.prepend(value);
//                 break;
//             case 3:
//                 cout << "Enter value to find: ";
//                 cin >> key;
//                 cout << "Enter value to insert: ";
//                 cin >> value;
//                 list.insertByKey(key, value);
//                 break;
//             case 4:
//                 cout << "Enter value to delete: ";
//                 cin >> key;
//                 list.deleteByKey(key);
//                 break;
//             case 5:
//                 cout << "Enter value to update: ";
//                 cin >> key;
//                 cout << "Enter new value: ";
//                 cin >> value;
//                 list.updateByKey(key, value);
//                 break;
//             case 6:
//                 cout << "Current list: ";
//                 list.display();
//                 break;
//             case 7:
//                 cout << "Exiting program.\n";
//                 return 0;
//             default:
//                 cout << "Invalid choice. Please enter a valid choice.\n";
//         }
//     }

//     return 0;
// }

// implementing stack using linked list
// #include <iostream>

// using namespace std;

// // Define a node structure for the stack
// struct Node {
//     int data;
//     Node* next;
// };

// // Define a stack class using linked list
// class Stack {
// private:
//     Node* top; // Pointer to the top of the stack

// public:
//     // Constructor
//     Stack() {
//         top = nullptr;
//     }

//     // Destructor to free allocated memory
//     ~Stack() {
//         Node* current = top;
//         Node* next;
//         while (current != nullptr) {
//             next = current->next;
//             delete current;
//             current = next;
//         }
//         top = nullptr;
//     }

//     // Function to push (append) a new node onto the stack
//     void push(int value) {
//         Node* new_node = new Node();
//         new_node->data = value;
//         new_node->next = top;
//         top = new_node;
//     }

//     // Function to pop (delete) the top node from the stack
//     void pop() {
//         if (isEmpty()) {
//             cout << "Stack is empty. Cannot pop from an empty stack." << endl;
//             return;
//         }

//         Node* temp = top;
//         top = top->next;
//         delete temp;
//     }

//     // Function to peek (display) the top element of the stack
//     void peek() {
//         if (isEmpty()) {
//             cout << "Stack is empty. Cannot peek into an empty stack." << endl;
//             return;
//         }

//         cout << "Top of the stack: " << top->data << endl;
//     }

//     // Function to display all elements of the stack
//     void display() {
//         if (isEmpty()) {
//             cout << "Stack is empty." << endl;
//             return;
//         }

//         Node* current = top;
//         cout << "Stack elements (top to bottom): ";
//         while (current != nullptr) {
//             cout << current->data << " ";
//             current = current->next;
//         }
//         cout << endl;
//     }

//     // Function to check if the stack is empty
//     bool isEmpty() {
//         return top == nullptr;
//     }

//     // Function to count the number of elements in the stack
//     int count() {
//         int count = 0;
//         Node* current = top;
//         while (current != nullptr) {
//             count++;
//             current = current->next;
//         }
//         return count;
//     }
// };

// int main() {
//     Stack stack;

//     int choice, value;

//     while (true) {
//         cout << "What operations do you want to perform\n";
//         cout << "1. Push\n";
//         cout << "2. Pop \n";
//         cout << "3. Peek \n";
//         cout << "4. Display \n";
//         cout << "5. is empty\n";
//         cout << "6. Count \n";
//         cout << "7. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Enter value to push: ";
//                 cin >> value;
//                 stack.push(value);
//                 break;
//             case 2:
//                 stack.pop();
//                 break;
//             case 3:
//                 stack.peek();
//                 break;
//             case 4:
//                 stack.display();
//                 break;
//             case 5:
//                 if (stack.isEmpty()) {
//                     cout << "Stack is empty." << endl;
//                 } else {
//                     cout << "Stack is not empty." << endl;
//                 }
//                 break;
//             case 6:
//                 cout << "Number of elements in stack: " << stack.count() << endl;
//                 break;
//             case 7:
//                 cout << "Exiting program.\n";
//                 return 0;
//             default:
//                 cout << "Invalid choice. Please enter a valid choice.\n";
//         }
//     }

//     return 0;
// }

// implementation of queue using linked list
// #include <iostream>

// using namespace std;

// // Define a node structure for the queue
// struct Node {
//     int data;
//     Node* next;
// };

// // Define a queue class using linked list
// class Queue {
// private:
//     Node* front; // Pointer to the front of the queue
//     Node* rear;  // Pointer to the rear of the queue

// public:
//     // Constructor
//     Queue() {
//         front = nullptr;
//         rear = nullptr;
//     }

//     // Destructor to free allocated memory
//     ~Queue() {
//         Node* current = front;
//         Node* next;
//         while (current != nullptr) {
//             next = current->next;
//             delete current;
//             current = next;
//         }
//         front = nullptr;
//         rear = nullptr;
//     }

//     // Function to enqueue (append) a new node into the queue
//     void enqueue(int value) {
//         Node* new_node = new Node();
//         new_node->data = value;
//         new_node->next = nullptr;

//         if (isEmpty()) {
//             front = new_node;
//             rear = new_node;
//         } else {
//             rear->next = new_node;
//             rear = new_node;
//         }
//     }

//     // Function to dequeue (delete) the front node from the queue
//     void dequeue() {
//         if (isEmpty()) {
//             cout << "Queue is empty. Cannot dequeue from an empty queue." << endl;
//             return;
//         }

//         Node* temp = front;
//         front = front->next;

//         // If after dequeuing, the queue becomes empty, update rear as well
//         if (front == nullptr) {
//             rear = nullptr;
//         }

//         delete temp;
//     }

//     // Function to peek (display) the front element of the queue
//     void peek() {
//         if (isEmpty()) {
//             cout << "Queue is empty. Cannot peek into an empty queue." << endl;
//             return;
//         }

//         cout << "Front of the queue: " << front->data << endl;
//     }

//     // Function to display all elements of the queue
//     void display() {
//         if (isEmpty()) {
//             cout << "Queue is empty." << endl;
//             return;
//         }

//         Node* current = front;
//         cout << "Queue elements (front to rear): ";
//         while (current != nullptr) {
//             cout << current->data << " ";
//             current = current->next;
//         }
//         cout << endl;
//     }

//     // Function to check if the queue is empty
//     bool isEmpty() {
//         return front == nullptr;
//     }

//     // Function to count the number of elements in the queue
//     int count() {
//         int count = 0;
//         Node* current = front;
//         while (current != nullptr) {
//             count++;
//             current = current->next;
//         }
//         return count;
//     }
// };

// int main() {
//     Queue queue;

//     int choice, value;

//     while (true) {
//         cout << "Operations on Queue using Linked List\n";
//         cout << "1. Enqueue \n";
//         cout << "2. Dequeue \n";
//         cout << "3. Display queue\n";
//         cout << "4. isEmpty\n";
//         cout << "5. Count \n";
//         cout << "6. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Enter value to enqueue: ";
//                 cin >> value;
//                 queue.enqueue(value);
//                 break;
//             case 2:
//                 queue.dequeue();
//                 break;
//             // case 3:
//             //     queue.peek();
//             //     break;
//             case 3:
//                 queue.display();
//                 break;
//             case 4:
//                 if (queue.isEmpty()) {
//                     cout << "Queue is empty." << endl;
//                 } else {
//                     cout << "Queue is not empty." << endl;
//                 }
//                 break;
//             case 5:
//                 cout << "Number of elements in queue: " << queue.count() << endl;
//                 break;
//             case 6:
//                 cout << "Exiting program.\n";
//                 return 0;
//             default:
//                 cout << "Invalid choice. Please enter a valid choice.\n";
//         }
//     }

//     return 0;
// }
