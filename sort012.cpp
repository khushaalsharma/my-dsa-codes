/*
low -> the region containing 0 or values less than the middle region
mid -> region with 1
high -> region with 2 or values greater than middle region
*/

void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        int low = 0, mid = 0, high = n-1;
        
        while(mid <= high){
            int num = arr[mid];
            if(num == 0){
                swap(arr[low++], arr[mid++]);
            }
            else if(num == 1){
                mid++;
            }
            else{
                swap(arr[mid++], arr[high--]);
            }
        }
        
    }
