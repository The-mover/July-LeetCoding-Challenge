class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        res = 0
        for num in nums:
            res ^= num
        
        mask = res & -res
        
        one = 0
        for num in nums:
            if num & mask == 0:
                one ^= num
        
        two = res ^ one
        return [one, two]