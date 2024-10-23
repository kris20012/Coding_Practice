int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> ht;

        for(int i = 0; i < nums.size(); i++){
            ht[nums[i]]++;
        }

        for(unordered_map<int, int>::iterator it = ht.begin(); it!=ht.end(); it++){
            cout << "Num: " << it->first << " Freq: " << it->second << endl;
            if(it->second >= 2) return it->first;
        }
        return -1;
    }