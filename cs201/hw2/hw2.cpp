#include <iostream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <limits>


typedef std::numeric_limits< double > dbl;


using namespace std;

int binarySearchRecur(int *arr, int low, int high, int key){
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;

    if (arr[mid] > key)
        return binarySearch(arr,low,mid - 1,key);

    return binarySearch(arr,mid + 1,high,key);
}



int binarySearch(int *A, int N, int value)
{
    int low = 0, high = N;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] < value)
            low = mid + 1;
        else if (a[mid] > value)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

int linearSearch(int arr[], int n, int value)
{
    index = -1;
    for (i = 0; i < n; i++)
        if (A[i] == value)
        {
            index = i;
            break;
        }
    return index;
}

int main()
{
    int array3 = {1,2,3,4,5,6,7,8,9,10};
//    BINARY
//    int closeToBeginning = new int[10];
//    for(int i = 0; i < 10; i++)
//    {
//        closeToBeginning[i] = i;
//    }
//
//    int aroundTheMiddle = new int[100];
//    for(int i = 0; i < 100; i++)
//    {
//        aroundTheMiddle[i] = i;
//    }
//    int* closeToEnd = new int[10000];
//    for(int i = 0; i < 10000; i++)
//    {
//        closeToEnd[i] = i;
//    }
//    int* notExtistent = new int[100000];
//    for(int i = 0; i < 100000; i++)
//    {
//        notExtistent[i] = i;
//    }

//    LINEAR SEARCH
//    int closeToBeginning2 = new int[10];
//    for(int i = 0; i < 10; i++)
//    {
//        closeToBeginning2[i] = i;
//    }
//
//    int aroundTheMiddle2 = new int[100];
//    for(int i = 0; i < 100; i++)
//    {
//        aroundTheMiddle2[i] = i;
//    }
//    int closeToEnd2 = new int[10000];
//    for(int i = 0; i < 10000; i++)
//    {
//        closeToEnd2[i] = i;
//    }
//    int notExtistent2 = new int[100000];
//    for(int i = 0; i < 100000; i++)
//    {
//        notExtistent2[i] = i;
//    }

    //BINARY SEARCH


        double duration;
        clock_t startTime = clock();
		double d= binarySearch(array3, 10, 3);
		cout.precision(dbl::max_digits10);

        cout<< d <<endl;

        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds." << endl;

//       for(int i = 0; i < 5; i++)
//    {
//
//        double duration;
//        clock_t startTime = clock();
//        cout<< binarySearch(aroundTheMiddle, int 50, int 20)<<endl;
//
//        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
//        cout << "Execution took " << duration << " milliseconds." << endl;
//    }
//       for(int i = 0; i < 5; i++)
//    {
//
//        double duration;
//        clock_t startTime = clock();
//        cout<< binarySearch(closeToEnd, int 10000, int 20)<<endl;
//
//        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
//        cout << "Execution took " << duration << " milliseconds." << endl;
//    }
//       for(int i = 0; i < 5; i++)
//    {
//
//        double duration;
//        clock_t startTime = clock();
//        cout<< binarySearch(notExtistent, int 100001, int 20)<<endl;
//
//        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
//        cout << "Execution took " << duration << " milliseconds." << endl;
//    }

//      for(int i = 0; i < 5; i++)
//    {
//
//        double duration;
//        clock_t startTime = clock();
//        cout<< binarySearchRecur(closeToBeginning, 0, 9, 3)<<endl;
//
//        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
//        cout << "Execution took " << duration << " milliseconds." << endl;
//    }


//    //LINEAR SEARCH
//      for(int i = 0; i < 5; i++)
//    {
//
//        double duration;
//        clock_t startTime = clock();
//        cout<< linearSearch(closeToBeginning2, int 10, int 20)<<endl;
//
//        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
//        cout << "Execution took " << duration << " milliseconds." << endl;
//    }
//       for(int i = 0; i < 5; i++)
//    {
//
//        double duration;
//        clock_t startTime = clock();
//        cout<< linearSearch(aroundTheMiddle2, int 50, int 20)<<endl;
//
//        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
//        cout << "Execution took " << duration << " milliseconds." << endl;
//    }
//       for(int i = 0; i < 5; i++)
//    {
//
//        double duration;
//        clock_t startTime = clock();
//        cout<< linearSearch(closeToEnd2, int 10000, int 20)<<endl;
//
//        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
//        cout << "Execution took " << duration << " milliseconds." << endl;
//    }
//       for(int i = 0; i < 5; i++)
//    {
//
//        double duration;
//        clock_t startTime = clock();
//        cout<< linearSearch(notExtistent2, int 100001, int 20)<<endl;
//
//        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
//        cout << "Execution took " << duration << " milliseconds." << endl;
//    }

    return 0;

}
