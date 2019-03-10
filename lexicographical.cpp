#include <iostream>
#include<string>

using namespace std;
void heapify(string arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}
void heapSort(string arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int i,n;
    string arr[10];
 cout<<"enter how many elements you want";
 cin>>n;
 cout<<"\n enter words";
 n=n+1;
 for(i=0;i<n;i++)
 {
     getline (cin, arr[i]);
 }

    heapSort(arr, n);


    cout << "Sorted  list is \n";

      {  for (i=0; i<n; ++i)
        {
            cout << arr[i] << " ";
        cout << "\n";}
    }
}
