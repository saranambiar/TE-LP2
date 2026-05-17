#include <iostream>
using namespace std;

class SelectionSort{
    public:
    int n, arr[100];

    void input(){
        cout << "Enter the number of elements: ";
        cin >> n;
        cout << endl;
        cout << "Enter the elements: ";
        for(int i = 0; i <n; i++){
            cin >> arr[i];
        }
        cout << "Original array: ";
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
    }

    void selectionSort(){
        for(int i = 0; i < n-1; i++){
            int minIndex = i;
            for(int j = i+1; j < n; j++){
                if(arr[j] < arr[minIndex]){
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
        cout << "\nSorted array: ";
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    SelectionSort ss;
    ss.input();
    ss.selectionSort();
    return 0;
}