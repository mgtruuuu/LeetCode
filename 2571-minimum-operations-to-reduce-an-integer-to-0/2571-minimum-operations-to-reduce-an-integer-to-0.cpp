class Solution {
public:
    int minOperations(int n) {
        int result = 0;
        // 39 = 100111
        // 54 = 110110

        unordered_set<int> myset;

        queue<vector<int>> myq;

        myq.push({n, 0});

        while(!myq.empty()){
            for(int i = 0; i < myq.size(); i++){
                vector<int> mf = myq.front(); myq.pop();
                
                int num = mf[0];
                int distance = mf[1];

                myset.insert(num);

                if(num == 0) return distance;

                int adder = 1;
                while((num & adder) == 0){
                    adder = adder << 1;
                }

                if(!myset.contains(num + adder)){
                    myset.insert(num + adder);
                    myq.push({num + adder, distance + 1});
                }

                if(!myset.contains(num - adder)){
                    myset.insert(num - adder);
                    myq.push({num - adder, distance + 1});
                }
            }

        }

        return 0;


    }
};