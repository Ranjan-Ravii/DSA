
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class heaps{
    private:
    int arr[100];
    int size;

    //constructore
    public:
    heaps(){
        size = 0;
        arr[0] = -1;
    }

    // function to insert in heap
    void insertInHeap( int data){

        size = size + 1;
        int index = size;
        arr[index] =  data;

        while (index > 1){
            int parent = index / 2;

            if(arr[index] > arr[parent]){
                swap(arr[index], arr[parent]);
                index = parent;
            }else{
                return;
            }
            
        }
        
    }

    void printHeap(){
        for (int i = 1; i <= size; i++){
            cout << arr[i] << " " ; 
        }
        cout << "size = " << size << endl; 
    }

    void dfeleteHeapNode(){
       
       arr[1] = arr[size];
        size = size - 1;

        int i = 1;
        while (i < size){
            int left = i * 2;
            int right = (i * 2 ) + 1 ;

            if( left < size && arr[i] < arr[left]){
                if(right < size && arr[i] < arr[right] && arr[left] < arr[right]){
                    swap(arr[i], arr[right]);
                    i = right;
                }
                else{
                    swap(arr[left], arr[i]);
                    i = left;
                }
            }
            else if(right < size && arr[i] < arr[right]){
                swap(arr[i], arr[right]);
                i = right;
            }else{
                return;
            }
        }
        
    }
};

//heapify
void heapify(int arr[], int n, int i){

    int largest = i;
    int left = 2 * i; 
    int right = 2 * i + 1;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if (largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }    
}

void heapSort(int arr[], int n){
    //create a max heap
    for (int i = n/2; i > 0; i--){
        heapify(arr, n, i);
    }

    // sort the max heap
    for (int i = n+1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


int main(){

    heaps h;
    h.insertInHeap(50);
    h.insertInHeap(55);
    h.insertInHeap(35);
    h.insertInHeap(15);
    h.insertInHeap(25);
    h.insertInHeap(75);
    h.insertInHeap(45);

    h.printHeap();
   
    h.dfeleteHeapNode();
    h.printHeap();



    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n/2; i > 0; i--){
        heapify(arr, n, i);
    }

    cout << "printing new heapified heap" << endl;
    for (int i = 1; i <= n; i++){
        cout << arr[i] << " " ;
    }cout << endl;


    heapSort(arr, n);
    cout << "printing new heapified sorted heap" << endl;
    for (int i = 1; i <= n; i++){
        cout << arr[i] << " " ;
    }cout << endl;



    // ************* the max heap or min heap can be created using STL (priority queue)

    priority_queue<int> pq; // default a max heap.

    pq.push(2);
    pq.push(5);
    pq.push(7);
    pq.push(3);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }cout << endl;

    priority_queue<int, vector<int>, greater<int> > mpq;
    mpq.push(2);
    mpq.push(5);
    mpq.push(7);
    mpq.push(3);

    while (!mpq.empty()) {
        cout << mpq.top() << " ";
        mpq.pop();
    }cout << endl;



    return 0;
}