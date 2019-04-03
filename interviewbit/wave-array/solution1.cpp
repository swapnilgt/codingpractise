vector<int> Solution::wave(vector<int> &A) {

    int size = A.size();

    // Sorting the array ...
    sort(A.begin(), A.end());

    for (int i = 0; i < size / 2; i ++) {
        A[i * 2] = A[i * 2] + A[i * 2 + 1];
        A[i * 2 + 1] = A[i * 2] - A[i * 2 + 1];
        A[i * 2] = A[i * 2] - A[i * 2 + 1];
    }

    return A;
}
