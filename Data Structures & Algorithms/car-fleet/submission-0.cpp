class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // initialize a vector pair to store <position, speed>
        vector<pair<int, int>> cars;

        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end());

        stack<double> st;
        // now the calculation of the car fleet backwards
        for (int i = cars.size() - 1; i >= 0; i--) {
            int pos = cars[i].first;
            int speed = cars[i].second;

            double time = (double)(target - pos) / speed; // time = distance / speed
 
            st.push(time);

            if(st.size() >= 2){
                double current = st.top();
                st.pop();

                double front = st.top();

                if(current > front){
                    st.push(current);
                }
                // otherwise, current merges with front
            }

        }
        return st.size();
    }
};
