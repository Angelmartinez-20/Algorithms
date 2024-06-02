/*
    This script is used to find the postions of 2 numbers 
    within a list that add up to a target. By utilizing a 
    hashmap (key = nums[i], value = i), its runtim is O(n).
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map <int, int> numsMap;
    vector<int> result;

    /* iterates through list of nums */
    for (int i = 0; i < nums.size(); i++) {
        int target2 = target - nums[i];
        /* answer is found */
        if (numsMap.find(target2) != numsMap.end()) {
            result.push_back(numsMap[target2]);
            result.push_back(i);
            break;
        }
        numsMap[nums[i]] = i;   // add num to hashMap
    }   

    return result;
}

int main () {
    vector<int> nums, result;
    int target, numsSize, value;

    /* gets input from user */
    cout << "Enter Target: ";
    cin >> target;
    cout << "Enter Size of List: ";
    cin >> numsSize;
    cout << "Enter List Values: ";
    for (int i = 0; i < numsSize; i++){
        cin >> value;
        nums.push_back(value);
    }

    /* prints answer */
    result = twoSum(nums, target);
    if (result.empty())
        cout << "No Answer!\n";
    else 
        cout << "[" << result[0] << ", " << result[1] << "]\n";

    return 0;
}
