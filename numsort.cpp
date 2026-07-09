#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& vec, int left, int mid, int right) {
    vector<int> leftVec(vec.begin() + left, vec.begin()+ mid + 1);
    vector<int> rightVec(vec.begin() + mid + 1, vec.begin() + right + 1);

    int i = 0, j = 0;
    int k = left;

    while(i < leftVec.size() && j < rightVec.size()) {
        if(leftVec[i] <= rightVec[j]) {
            vec[k] = leftVec[i];
            i++;
        }
        else {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }

    while(i < leftVec.size()) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }

    while(j < rightVec.size()) {
        vec[k] = rightVec[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& vec, int left, int right) {
    if(left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(vec, left, mid);
    mergeSort(vec, mid+1, right);
    merge(vec, left, mid, right);
}

int main() {
    int n, x;
    vector<int> intVec;

    cout << "입력 숫자 개수: ";
    cin >> n;
    cout << endl;

    cout << "입력" << endl;
    for(int i = 0; i < n; i++) {
        cin >> x;
        intVec.push_back(x);
    }
    mergeSort(intVec, 0, intVec.size() - 1);
    cout << "정렬 후 배열 : " << endl;

    for(auto i : intVec) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}