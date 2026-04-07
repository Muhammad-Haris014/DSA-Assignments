#include <iostream>
using namespace std;


 //  Q1 – Arrays & Searching
 

// Q1.A.1
// Contiguous memory allocation means storing elements next to each other in memory.
// Arrays use this so we can directly access any element using index.
// Advantage: very fast access (O(1)) because address is calculated directly.

// Q1.A.2
// Memory leak happens when we allocate memory but forget to free it.
// Example: using new to create an array but not deleting it after use.
// int* arr = new int[10]; // allocated
// (no delete[]) → memory leak

// Q1.A.3
// Static array has fixed size (decided at compile time).
// Dynamic array size can be changed at runtime.
// Fixed size matters because we cannot resize it later, which can waste or limit memory.

// Q1.A.4
// Array access is O(1) because we directly calculate index address.
// In Linked List, we must traverse nodes one by one → O(n).

// Linear Search
int linearSearch(int arr[], int size, int key){
for(int i = 0; i < size; i++){
           if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

// Find Min & Max in one loop
void findMinMax(int arr[], int size, int &minVal, int &maxVal){
    minVal = arr[0];
    maxVal = arr[0];

    for(int i = 1; i < size; i++){
        if(arr[i] < minVal) minVal = arr[i];
        if(arr[i] > maxVal) maxVal = arr[i];
    }
}


//   Q2 – Bubble Sort


// Q2.A.1
// Bubble sort compares adjacent elements and swaps if wrong order.
// After each pass, largest element moves to end like a bubble.

// Q2.A.2
// Best: O(n) (already sorted with flag)
// Average: O(n^2)
// Worst: O(n^2)

// Q2.A.3
// Selection sort does fewer swaps.
// Bubble sort is easier but slower in general.

void bubbleSort(int arr[], int size, int &swapCount){
    swapCount = 0;

    for(int i = 0; i < size-1; i++){
        bool swapped = false;

        for(int j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapCount++;
                swapped = true;
            }
        }

        // print after each pass
        cout << "Pass " << i+1 << ": ";
        for(int k = 0; k < size; k++){
            cout << arr[k] << " ";
        }
        cout << endl;

        if(!swapped) break;
    }
}


   // Q3 – Binary Search


// Q3.A.1
// Array must be sorted.
// Without sorting, binary search won't work correctly.

// Q3.A.2
// Dry Run for key 23:
// low=0 high=7 mid=3 → arr[3]=12
// low=4 high=7 mid=5 → arr[5]=23 (found)

// Q3.A.3
// Linear search = O(n)
// Binary search = O(log n)
// Binary is faster because it halves search space each time.

int binarySearch(int arr[], int size, int key, int &iterations){
    int low = 0, high = size-1;
    iterations = 0;

    while(low <= high){
        iterations++;
        int mid = (low + high) / 2;

        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}


   // Q4 – Big O


// Q4.A.1
// Big O shows how algorithm grows with input size.
// We don't use seconds because machines differ.

// Q4.A.2
// Big O = worst case
// Big Omega = best case
// Big Theta = exact bound

// Q4.A.3
// Fast → Slow:
// O(1), O(log n), O(n), O(n log n), O(n^2)

// Q4.A.4
// Space complexity = memory used.
// If array of size n → O(n)

// Q4.A.5
// Wrong. Better algorithm always wins for large input.

// Nested loop → O(n^2)
void nestedLoop(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << "*";
        }
    }
}

// Single loop → O(n)
void singleLoop(int n){
    for(int i=0;i<n;i++){
        cout << "*";
    }
}

// Check A in B → O(n^2)
bool checkArrays(int A[], int B[], int n){
    for(int i=0;i<n;i++){
        bool found = false;
        for(int j=0;j<n;j++){
            if(A[i] == B[j]){
                found = true;
                break;
            }
        }
        if(!found) return false;
    }
    return true;
}


//   Q5 – Linked List


// Q5.A.1
// Linked list stores elements using nodes connected by pointers.

// Q5.A.2
// Insert head = O(1)
// Insert tail = O(n)
// Delete = O(n)

// Q5.A.3
// Not deleting node causes memory leak.

struct Node{
    int data;
    Node* next;
};

class LinkedList{
public:
    Node* head;

    LinkedList(){
        head = nullptr;
    }

    void insertAtHead(int val){
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    void insertAtTail(int val){
        Node* newNode = new Node{val, nullptr};
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteByValue(int val){
        if(head == nullptr) return;

        if(head->data == val){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr && temp->next->data != val){
            temp = temp->next;
        }

        if(temp->next == nullptr){
            cout << "Value not found\n";
            return;
        }

        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }

    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};


//   MAIN FUNCTION
  

int main(){

    // Q1
    int arr[10] = {4,15,7,23,1,9,42,18,6,30};
    int index = linearSearch(arr, 10, 42);

    if(index != -1)
        cout << "Found at index: " << index << endl;
    else
        cout << "Not found\n";

    int minVal, maxVal;
    findMinMax(arr, 10, minVal, maxVal);
    cout << "Min: " << minVal << " Max: " << maxVal << endl;

    // Q2
    int arr2[7] = {64,34,25,12,22,11,90};
    int swaps;
    bubbleSort(arr2, 7, swaps);
    cout << "Total swaps: " << swaps << endl;

    // Q3
    int arr3[10] = {2,5,8,12,16,23,38,45,56,72};
    int iter;
    int res = binarySearch(arr3, 10, 56, iter);
    cout << "Index: " << res << " Iterations: " << iter << endl;

    // Q5
    LinkedList list;
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtHead(5);
    list.insertAtTail(30);
    list.insertAtHead(1);

    list.display();

    list.deleteByValue(20);
    list.deleteByValue(100);

    list.display();

    return 0;
}

// GitHub: https://github.com/YourUsername/YourRepoName