/*
Simple approach of including and excluding the item 

*/

#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

int solveRec(vector<int>& weight, vector<int>& value, int n, int maxWeight, int itemIdx){ //Recursive solution gives TLE
	//base case
	if(itemIdx == 0){
		if(weight[itemIdx] <= maxWeight){
			return value[itemIdx];
		}
		else{
			return 0;
		}
	}

	int valStored = 0;

	int include = solveRec(weight, value, n, maxWeight - weight[itemIdx], itemIdx - 1) + value[itemIdx];
	int exclude = solveRec(weight, value, n, maxWeight, itemIdx - 1);

	valStored = max(include, exclude);

	return valStored;
}

int solveMem(vector<int>& weight, vector<int>& values, vector<vector<int>>& memArray, int maxWeight, int index){ //Dynamic Programming solution using memoization 
	//base case
	if(index == 0){
		if(weight[0] <= maxWeight){
			return values[0];
		}
		else{
			return 0;
		}
	}

	if(memArray[index][maxWeight] != -1){
		return memArray[index][maxWeight];
	}

	int include = 0;
	if(weight[index] <= maxWeight){
		include = values[index] + solveMem(weight, values, memArray, maxWeight - weight[index], index-1);
	}

	int exclude = solveMem(weight, values, memArray, maxWeight, index-1);

	memArray[index][maxWeight] = max(include, exclude);

	return memArray[index][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	//return solveRec(weight, value, n, maxWeight, n-1);

	vector<vector<int>> memArray(n, vector<int>(maxWeight+1, -1));

	return solveMem(weight, value, memArray, maxWeight, n-1);
}
