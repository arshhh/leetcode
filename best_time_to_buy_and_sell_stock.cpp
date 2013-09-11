class Solution {
public:
  int findMinIndex(vector<int> &prices, int startIndex,int endIndex){
    int minIndex = startIndex;
	for(int i=startIndex+1;i<=endIndex;i++){
		if(prices[i]<prices[minIndex])
			minIndex = i;
	}
	return minIndex;
    }
    
    int findMaxIndex(vector<int> &prices, int startIndex,int endIndex){
	int maxIndex = startIndex;
	for(int i=startIndex+1;i<=endIndex;i++){
		if(prices[i] >prices[maxIndex])
			maxIndex = i;
    }
	return maxIndex;
    }
int getMax(int i,int j){
	return i >j ? i : j;
}
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
 int size = prices.size();
if(size==0)
	return 0;
    
    
	int startIndex = 0;
    for(int i=startIndex+1;i<size;i++){
        if(prices.at(i)<prices.at(startIndex))
            startIndex = i;
        else
            break;
    }
    
    
    int minIndex = findMinIndex(prices, startIndex,size-1);
	int maxIndex = findMaxIndex(prices,startIndex,size-1);
	int profit = 0;
	while(minIndex>maxIndex){
		int tempMinIndex = 0 ;
		if(maxIndex>startIndex){
            tempMinIndex = findMinIndex(prices,startIndex,maxIndex-1);
			profit = getMax(profit, prices.at(maxIndex)-prices.at(tempMinIndex));
		}
		startIndex = maxIndex + 1;
		maxIndex = findMaxIndex(prices,startIndex,size-1);
}
profit = getMax(profit, prices.at(maxIndex)-prices.at(minIndex));
return profit;
}
};
