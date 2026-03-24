/*
eg arr = [3,0,6,1,5], since there are only 5 papers thus range of h [0,5].

Create a bucket of citations of 0 to 5, where each index represents the citations, This bucket contains the count of papers that have been cited i times (being index)
Once bucket is filled,
iterate it from back marking cummulative paper count,
as cummulative_count == i return i (hIndex);
*/

class Solution {
    public int hIndex(int[] citations) {
        int papers = citations.length;
        int[] citationBuckets = new int[papers + 1];

        for (int citation : citations) {
            citationBuckets[Math.min(citation, papers)]++;
        }

        int cumulativePapers = 0;
        for (int hIndex = papers; hIndex >= 0; hIndex--) {
            cumulativePapers += citationBuckets[hIndex];
            if (cumulativePapers >= hIndex) {
                return hIndex;
            }
        }
        return 0;        
    }
}
