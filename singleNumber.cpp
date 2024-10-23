int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hashTable;

        for(int i = 0; i < nums.size(); i++){
            hashTable[nums[i]]++;
        }

        for(unordered_map<int, int>::iterator it=hashTable.begin(); it != hashTable.end(); it++){
            cout << "First: " << it->first << " Second: " << it->second << endl;
            if(it->second == 1) return it->first;
        }
        return -1;
    }