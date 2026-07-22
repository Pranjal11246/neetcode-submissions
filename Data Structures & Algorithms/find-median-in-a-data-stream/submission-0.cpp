class MedianFinder {
private:
    vector<int> nums;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        nums.push_back(num);
    }
    
    double findMedian() {
        sort(nums.begin(),nums.end());
        if(nums.size() & 1){
            return nums[nums.size()/2];
        }
        return (nums[nums.size()/2]+nums[nums.size()/2-1])/2.0;
    }
};
