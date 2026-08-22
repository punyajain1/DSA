class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> mh;
    // in min heap always minimum will be in front , and to find the kth largest element , we will push alll elements to min heam and whenevr the size of minheap gets bigger then k we pop front as we do not require it anymore
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int n:nums){
            mh.push(n);
            if(mh.size()>k) mh.pop();
        }
    }
    
    int add(int val) {
        mh.push(val);
        if(mh.size()>k) mh.pop();
        return mh.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */