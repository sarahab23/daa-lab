#include <iostream>

using namespace std;

// A function to heapify the array.
void MaxHeapify(string a[], int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2*i;

 	while (j <= n)
	{
		if (j < n && a[j+1] > a[j])
		j = j+1;
		// Break if parent value is already greater than child value.
		if (temp > a[j])
			break;
		// Switching value with the parent node if temp < a[j].
		else if (temp <= a[j])
		{
			a[j/2] = a[j];
			j = 2*j;
		}
	}
	a[j/2] = temp;
	return;
}
void HeapSort(string a[], int n)
{
	int i, temp;
	for (i = n; i >= 2; i--)
	{

		temp = a[i];
		a[i] = a[1];
		a[1] = temp;

		MaxHeapify(a, 1, i - 1);
	}
}
void Build_MaxHeap(string a[], int n)
{
	int i;
	for(i = n/2; i >= 1; i--)
		MaxHeapify(a, i, n);
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

	Build_MaxHeap(arr, n-1);
	HeapSort(arr, n-1);

	cout<<"\nSorted Data ";

	for (i = 1; i < n; i++)
		cout<<"->"<<arr[i];

	return 0;
}
