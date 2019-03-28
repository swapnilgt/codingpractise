/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    const int l = intervals.size();

    if(l == 0) {
        intervals.push_back(newInterval);
        return intervals;
    }

    vector<Interval> retVal;
    int i = 0;

    // Skipping all the smaller intervals ...
    while(i < l && intervals[i].end < newInterval.start) {
        retVal.push_back(intervals[i]);
        i++;
    }

    if(i < l) {
        Interval mergedInterval;

        // Handling the start position ...
        if(newInterval.start < intervals[i].start) {
            mergedInterval.start = newInterval.start;
        } else {
            mergedInterval.start = intervals[i].start;
        }

        // Handling the end position ...
        while(i < l && newInterval.end >= intervals[i].start) { // Just skip over for the merge ..
            i++;
        }

        //cout << "Value of i is " << i << endl;
        if(i <= l && i > 0) { // Only if we have moved ahead ....
            if(newInterval.end > intervals[i-1].end) {
                mergedInterval.end = newInterval.end;
            } else {
                mergedInterval.end = intervals[i-1].end;
            }
        } else {
            mergedInterval.end = newInterval.end;
        }
        retVal.push_back(mergedInterval);
    } else {
        retVal.push_back(newInterval);
    }

    while(i < l) { // Pushing the left
        retVal.push_back(intervals[i]);
        i++;
    }


    return retVal;

}
