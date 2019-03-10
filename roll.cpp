#include <iostream>
using namespace std;
int binarysearch(int sr,int arr[][]);
int heapSort(int arr[][],int n);
int main()
{
   int c,n,sr;
   cout<<"Enter number of elements :";
   cin>>n;;
   int roll[n][2],mark[n];
   char nam[n][50];
   cout<<"Enter the elements of the array:"<<endl;
   for (c = 0; c < n; c++)
      {
          cout<<"Roll no.:";
          cin>>roll[n][2];
          cout<<endl<<"Name:";
          cin>>name[n];
          cout<<endl<<"Total Marks:";
          cin>>mark[n];
          roll[n][1]=c;
      }
   heapSort(roll,n);
   cout<<"Enter the roll number to be searched:";
   cin>>sr;
   binarysearch(sr,roll);
   return 0;
}
int binarysearch(int search,int array[]){
   int  first, last, middle;
   first = 0;
   last = sizeof(array)+1;
   middle = (first+last)/2;

   while (first <= last) {
      if (array[middle] < search)
         first = middle + 1;
      else if (array[middle] == search) {
         printf("%d found at location %d ", search, middle+1);
         break;
      }
      else
         last = middle - 1;

      middle = (first + last)/2;
   }
   if (first > last)
      printf("not in the list", search);
}
void heapify(int arr[][], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l][2] > arr[largest][2])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r][2] > arr[largest][2])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i][2], arr[largest][2]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[][], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(roll, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0][2], arr[i][2]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

