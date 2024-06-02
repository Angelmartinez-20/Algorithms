'''
    This script is used to find the postions of 2 numbers 
    within a list that add up to a target. By utilizing a 
    hashmap (key = nums[i], value = i), its runtim is O(n).
'''
def two_sum(nums, target):
    nums_map = {}
    result = []

    # iterates through list of nums
    for i in range(len(nums)):
        target2 = target - nums[i]
        # answer is found
        if target2 in nums_map:
            result.append(nums_map[target2])
            result.append(i)
            break
        nums_map[nums[i]] = i  # add num to nums_map

    return result

def main():
    nums = []
    result = []

    # gets input from user
    target = int(input("Enter Target: "))
    nums_size = int(input("Enter Size of List: "))
    print("Enter List Values: ")
    for _ in range(nums_size):
        value = int(input())
        nums.append(value)

    # prints answer
    result = two_sum(nums, target)
    if not result:
        print("No Answer!")
    else:
        print(f"[{result[0]}, {result[1]}]")

if __name__ == "__main__":
    main()