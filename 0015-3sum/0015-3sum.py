class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []
        n = len(nums)

        # Traverse each element as a potential first element
        for i in range(n - 2):
            # Skip duplicate elements
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            l, r = i + 1, n - 1  # Left and Right pointers

            while l < r:
                sum = nums[i] + nums[l] + nums[r]

                if sum == 0:  # Valid triplet found
                    result.append([nums[i], nums[l], nums[r]])

                    # Skip duplicate elements for the second pointer
                    while l < r and nums[l] == nums[l + 1]:
                        l += 1

                    # Skip duplicate elements for the third pointer
                    while l < r and nums[r] == nums[r - 1]:
                        r -= 1

                    # Move to the next potential pair
                    l += 1
                    r -= 1
                elif sum < 0:  # Need a larger sum
                    l += 1
                else:  # Need a smaller sum
                    r -= 1
        return result