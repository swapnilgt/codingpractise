int Solution::solve(vector<int> &A) {

    if(A.size() == 0) {
        return -1;
    }

    int size = A.size();

    // Sorting the array ...
    sort(A.begin(), A.end());

    int prev = A[0];
    int index = 0;

    while(index < size) {

        //cout << "Running for element value " << A[index] << endl;

        while(index < size && A[index] == prev) {
            index++;
        }

        //cout << "Final index is " << index - 1 << endl;

        if(size - index == prev) {
            return 1;
        }

        if(index < size) {
            // Updating the previous ...
            prev = A[index];

            //cout << "###############################" << A[index] << endl;
        }
    }

    return -1;
}
