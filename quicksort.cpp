#include <bits/stdc++.h>
using namespace std ;
#define ll long long ;

//ham chon chi so phan tu ngau nhien trong vector
int randompivot(const vector<int>& vec ,int low ,int high)
{
    srand(time(0));
    int indexpivot = rand() % (high - low +1) + low ; 
    return indexpivot ;
}

// chia thanh 2 mang (divided into tow gills)
int ditg(vector<int>& arr , int low , int high)
{
    
    int chiso = randompivot(arr , low, high);
    swap(arr[high] , arr[chiso]);
    int pivot = arr[high]  ; 
    int i = low-1;
    for(int j = low ; j < high;j++)
    {
        if(arr[j] < pivot)
        {
            ++i ;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1] , arr[high]);
    return i+1 ;
    
}
void quicksort(vector<int>& arr , int low , int high)
{
    if(low < high)
    {
        int pivotindex = ditg(arr,low,high);
        quicksort(arr,low,pivotindex -1);
        quicksort(arr, pivotindex+1 ,high) ;
    }
    
}

int main()
{
    ifstream inputfile("songaunhien_1.txt") ;
    ofstream outputfile("quicksorttest.txt") ;
    if(!inputfile.is_open() || !outputfile.is_open())
    {
        cout << "err" ;
        return 1 ; 
    }
    vector<int> numbs ; 
    int numb ; 
    while(inputfile >> numb)
    {
        numbs.push_back(numb) ;
    }
    quicksort(numbs ,0, numbs.size()-1) ;
    for( int num : numbs )
    {
        outputfile <<  num << " " ;
    }

    inputfile.close() ; 
    outputfile.close() ; 

    return 0 ;
}