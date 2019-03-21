int Solution::maxSpecialProduct(vector<int> &A) {

    if(A.size() == 0) {
        return 0;
    }

    vector<long long int> leftMax(A.size(), 0);
    vector<long long int> rightMax(A.size(), 0);

    // Working for the left max ....
    stack<long long int> stkNumber;
    stack<int> stkIndex;

    stkNumber.push(A[0]);
    stkIndex.push(0);

    int index = 1;
    while(index < A.size()) {
        while(!stkNumber.empty() && stkNumber.top() <= A[index]) {
            // Keep popping till we get a number that is greater or the stack is empty ...
            stkNumber.pop();
            stkIndex.pop();
        }

        // Now check if we have got a bigger number ...
        if(!stkNumber.empty() && stkNumber.top() > A[index]) {
            // Assigning the value from the index stack ...
            leftMax[index] = stkIndex.top();
        }

        // Pushing this value on the top of the stack ...
        stkNumber.push(A[index]);
        stkIndex.push(index);

        index++;
    }

    // Working for the right max ....
    stack<long long int> temp1;
    stack<int> temp2;

    stkNumber.swap(temp1);
    stkIndex.swap(temp2);

    stkNumber.push(A[A.size()-1]);
    stkIndex.push(A.size()-1);

    index = A.size() - 2;
    while(index >= 0) {
        while(!stkNumber.empty() && stkNumber.top() <= A[index]) {
            // Keep popping till we get a number that is greater or the stack is empty ...
            stkNumber.pop();
            stkIndex.pop();
        }

        // Now check if we have got a bigger number ...
        if(!stkNumber.empty() && stkNumber.top() > A[index]) {
            // Assigning the value from the index stack ...
            rightMax[index] = stkIndex.top();
        }

        // Pushing this value on the top of the stack ...
        stkNumber.push(A[index]);
        stkIndex.push(index);

        index--;
    }

    long long int retVal = 0;
    for(int i = 0; i < A.size(); i++) {
        if(leftMax[i] * rightMax[i] > retVal) {
            retVal = leftMax[i] * rightMax[i];
        }
    }


    return retVal % 1000000007;

}
