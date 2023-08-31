#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kadane(vector<int>& arr) {
    int maxEndingHere = arr[0];
    int maxSoFar = arr[0];

    for (int i = 1; i < arr.size(); ++i) {
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
}

int maxCircularSubarraySum(vector<int>& arr) {
    int maxKadane = kadane(arr);
    
    int totalSum = 0;
    for (int i = 0; i < arr.size(); ++i) {
        totalSum += arr[i];
        arr[i] = -arr[i]; // Invert the signs to find the minimum subarray sum
    }
    
    int maxWrap = totalSum + kadane(arr);

    return max(maxKadane, maxWrap);
}

int main() {
    int N;
    cin >> N;
    
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int result = maxCircularSubarraySum(arr);
    cout << result << endl;

    return 0;
}
