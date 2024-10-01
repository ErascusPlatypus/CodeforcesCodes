def can_split(nums, max_sum, k):
    current_sum = 0
    required_subarrays = 1  # At least one subarray is needed
    
    for num in nums:
        if current_sum + num > max_sum:
            # Start a new subarray
            required_subarrays += 1
            current_sum = num
            if required_subarrays > k:
                return False
        else:
            current_sum += num
            
    return True

def minimize_max_subarray_sum(n, k, nums):
    low = max(nums)
    high = sum(nums)
    
    while low < high:
        mid = (low + high) // 2
        if can_split(nums, mid, k):
            high = mid
        else:
            low = mid + 1
            
    return low

# Input
n, k = map(int, input().split())
nums = list(map(int, input().split()))

# Output
print(minimize_max_subarray_sum(n, k, nums))
