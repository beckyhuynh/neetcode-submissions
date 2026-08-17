class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <int> track;
        vector <int> temps(temperatures.size(),0);

        if (temperatures.size() == 0) return {0};
        track.push(0);
        for (int i = 1; i < temperatures.size(); i++){
            if (!track.empty()){
                if (temperatures.at(track.top()) > temperatures.at(i)){
                    track.push(i);
                }
                else{
                     while (!track.empty() && temperatures.at(i) > temperatures.at(track.top())){
                        temps.at(track.top()) = i - track.top();
                        track.pop();
                    }
                    track.push(i);
                }
            }
        }
        return temps;
    }
};
