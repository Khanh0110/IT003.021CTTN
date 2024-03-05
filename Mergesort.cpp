#include<bits/stdc++.h> 
using namespace std; 

void merge(vector<int>& arr, int l, int mid, int r)
{
    int nl = mid - l + 1;
    int nr = r - mid;
    
    vector<int> b(nl), c(nr);

    for(int i = 0; i < nl; i++)
        b[i] = arr[l + i];
    for(int j = 0; j < nr; j++)
        c[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = l;

    while(i < nl && j < nr)
    {
        if(b[i] <= c[j])
        {
            arr[k] = b[i];
            i++;
        }
        else
        {
            arr[k] = c[j];
            j++;
        }
        k++;
    }

    while(i < nl)
    {
        arr[k] = b[i];
        i++;
        k++;
    }
    while(j < nr)
    {
        arr[k] = c[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r)
{
    if(l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{
    ifstream input("songaunhien_1.txt");
    ofstream output("Mergesort.txt");
    if(!input.is_open() || !output.is_open())
    {
        cout << "err";
        return 1;
    }
    vector<int> arrs;
    int arr;
    while(input >> arr)
    {
        arrs.push_back(arr);
    }
    mergeSort(arrs, 0, arrs.size() - 1);
    for(int j = 0; j < arrs.size(); j++)
    {
        output << arrs[j] << " ";
    }
    input.close();
    output.close();

    return 0;
}
