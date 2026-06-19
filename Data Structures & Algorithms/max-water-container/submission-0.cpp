class Solution {
public:
    int maxArea(vector<int>& heights) {
        int hmax=INT_MIN;
        int left=0,right=heights.size()-1;
        int n = heights.size();
        while(left<right){
            int h= min(heights[left],heights[right]);
            int b=right-left;
            int area= h*b;
            hmax= max(area,hmax);
            if(heights[left]<heights[right]){
                left++;
            }else{
                right--;
            }
        }
        return hmax;
    }
};
