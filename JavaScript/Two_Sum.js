/*
    This script is used to find the positions of 2 numbers 
    within a list that add up to a target. By utilizing a 
    hashmap (key = nums[i], value = i), its runtime is O(n).
*/
const prompt = require('prompt-sync')({sigint: true});

function twoSum(nums, target){
    const numsMap = new Map();
    const result = []

    // iterates through list of nums
    for (let i = 0; i < nums.length; i++) {
        const target2 = target - nums[i];
        if (numsMap.has(target2)) {
            result.push(numsMap.get(target2));
            result.push(i);
            break;
        }
        numsMap.set(nums[i], i);    // add num to hashtable
    }

    return result;
}

function main() {
    const nums = []
    let result = []
    
    // gets input from user
    const target = prompt("Enter Target: ");
    const numSize = parseInt(prompt("Enter Size of List: "), 10);
    console.log("Enter List Values: ");
    for (let i = 0; i < numSize; i++) {
        const value = parseInt(prompt(""), 10);
        nums.push(value);
    }

    // prints answer
    result = twoSum(nums, target);
    if (result.length === 0)
        console.log("No Answer!");
    else 
        console.log(`[${result[0]}, ${result[1]}]`);
}

main()