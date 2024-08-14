/*
Approach 1: binary Search

Create a function hasAtLeastHPapersWithHCitations with a parameter h to check if there are at least h papers with >= h citations. When hasAtLeastHPapersWithHCitations(x) is true, 
hasAtLeastHPapersWithHCitations(x-1) is also true. This means that hasAtLeastHPapersWithHCitations is a monotonic function, so we can binary search for the highest h for which it 
return true. This h is our h-index.
*/

class Solution {
public:
    bool hasAtLeastHPapersWithHCitations(int h, vector<int>& citations) {
        int count = 0;
        for (int cite_count : citations) {
            if (cite_count >= h)
                count++;
        }
        return count >= h;
    }
    int hIndex(vector<int>& citations) {
        int low = 0, high = citations.size();
        while (low <= high) {
            int mid = (low + high) / 2;
            if (hasAtLeastHPapersWithHCitations(mid, citations))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};

/*
Approach 2: Sort and Loop

First we sort the papers by decreasing # of citations. Imagine a histogram where each bar represents a paper and its height is the # of citations it has.
If the h-index were h, we'd need exactly h bars with height as least h. That is to say, we'd need the green square covered by bars. To find the h index, first set h = 0. 
Then keep increasing h by 1 as long as the next tallest bar is >= h+1. When we can no longer increase h, we have our answer.
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int h = 0;
        while (h < citations.size() and citations[h] >= h+1) {
            h++;
        }
        return h;
    }
};
