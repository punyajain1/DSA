class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // in min heap always minimum will be in front , and to find the kth largest element , we will push alll elements to min heam and whenevr the size of minheap gets bigger then k we pop front as we do not require it anymore
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int num:nums){
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
