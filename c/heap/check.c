#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int heap_array[1000];
int count = -1;

void swap(int *x, int *y) {
    int temp = *y;
    *y = *x;
    *x = temp;
}
int parent(int i)
{
        if( i <= 0 )
        {
            return -1;
        }
 
        return (i - 1)/2;
}
 
// Returns top element of heap data structure
int get_min(void)
{
        int max = -1;
 
        if( count >= 0 )
        {
            max = heap_array[0];
        }
 
        return max;
}
 
    // Returns number of elements in heap
int get_count()
{
        return count + 1;
}

    // Heapification
    // Note that, for the current median tracing problem
    // we need to heapify only towards root, always
void heapify(int i)
{
        int p = parent(i);
 
        // comp - differentiate MaxHeap and MinHeap
        // percolates up
        if( p >= 0 && heap_array[i] < heap_array[p] )
        {
            swap(&heap_array[i], &heap_array[p]);
            heapify(p);
        }
}
void heapifyDown(int parent) {
    int left_child = 2 * parent + 1;
    int right_child = 2 * (parent + 1);
    int smallest = -1;

    if (left_child <= count && right_child <= count) {
        if (heap_array[left_child] < heap_array[right_child]) {
            smallest = left_child;
        } else {
            smallest = right_child;
        }
    } else if (left_child <= count) {
        smallest = left_child;
    } else if (right_child <= count) {
        smallest = right_child;
    } else {
        return;
    }
    if (heap_array[parent] > heap_array[smallest]) {
            swap(&heap_array[parent], &heap_array[smallest]);
            heapifyDown(smallest);
    }
}
 
    // Deletes root of heap
int remove_min()
{
        int del = -1;
 
        if( count > -1)
        {
            del = heap_array[0];
 
            swap(&heap_array[0], &heap_array[count]);
            count--;
            heapifyDown(0);
        }
 
        return del;
}
 
void insert(int key)
{
        if( count < 1000 )
        {
            count++;
            heap_array[count] = key;
            heapify(count);
        }
}
void print_array() {
    int i;
    for (i = 0; i <= count; i++) {
        printf("%d ", heap_array[i]);
    }
    printf("\n");
}
main() {

    insert(5);
    print_array();
    insert(2);
    print_array();
    insert(8);
    print_array();
    insert(11);
    print_array();
    insert(1);
    print_array();
    insert(12);
    print_array();
    insert(15);
    print_array();
    insert(4);
    print_array();
    insert(3);
    print_array();

    remove_min();
    print_array();
    remove_min();
    print_array();
    remove_min();
    print_array();
    remove_min();
    print_array();
    remove_min();
    print_array();
    remove_min();
    print_array();
    remove_min();
    print_array();
    remove_min();
    print_array();
}
