import heapq
from typing import List

class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        priority_queue = [] 
        heapq.heapify(priority_queue)
        ans = []
        ans.append(-1)
        for num in arr.reverse:
            priority_queue.append(num)
            