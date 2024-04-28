/*
  This solution uses two variables first (most smallest no. encountered) and second (2nd most smallest no. encountered)
  both are initialised to INT_MAX or Infinity
  modifications to the variables are made accordingly
  if the number isn't smaller than first and second then we have found increasing triplet subseq hence return true
  else return false
*/

bool increasingTriplet(vector<int>& nums) {
    if(nums.size() < 3){
        return false;
    }
    
    int first = INT_MAX, second = INT_MAX;
    
    for(auto num : nums){
        if(num <= first){
            first = num;
        }
        else if(num <= second){
            second = num;
        }
        else{
            return true;
        }
    }
    
    return false;
}
