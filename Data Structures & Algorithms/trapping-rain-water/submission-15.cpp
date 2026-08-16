class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0; // guard against empty input
        if (height.size()==1 | height.size() == 2) return 0;
        int liquid = 0;
        int front = 0;
        int back = front + 2;
        vector <pair<bool,int>> containsLiquid(height.size());

        vector<int> rightMax(n);
        rightMax[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        while (front <= height.size()-3){
            if (height.at(front) > height.at(front+1) || (containsLiquid.at(front).first && containsLiquid.at(front).second+height.at(front) >= height.at(front+1))) {

                int frontHeight = 0;
                if (containsLiquid.at(front).first) {
                    frontHeight = containsLiquid.at(front).second + height.at(front);
                    
                }
                else frontHeight = height.at(front);

                while (back <= height.size()-1){
                    if (height.at(back) <= height.at(front+1)){
                        back ++;
                    }
                    else {
                        while (back <= height.size()-2){
                            if (height.at(back+1) >= height.at(back)){
                                back ++;
                            }
                            else break;
                        }
                        
                        // int toAdd = min(frontHeight,height.at(back)) - height.at(front+1);
                        // CHANGED: rightMax.at(back) instead of height.at(back)
                        int toAdd = min(frontHeight,rightMax.at(back)) - height.at(front+1);
                        
                        // cout << height.at(front) << height.at(back) << endl;
                        // cout << front << back << endl;
                        // cout << "toadd" << toAdd << endl;
                        liquid += toAdd;
                        
                        
                        containsLiquid.at(front+1) = {true,toAdd};
                        break;
                    }
                }
            }
            front ++;
            back = front + 2;
        }
        
        return liquid;
    }
};
