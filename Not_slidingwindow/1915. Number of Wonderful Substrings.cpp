#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int, int> count;
        int mask = 0;
        count[0] = 1;//00...00 10 zeros
        long long result = 0;
        for(char c : word) {
            mask ^= 1 << (c - 'a');
            result += count[mask];//even pattern
            for(int i = 0; i < 10; i++) {
                result += count[mask ^ (1 << i)];//one odd and rest are even
            }
            count[mask]++;
        }
        return result;
    }
};