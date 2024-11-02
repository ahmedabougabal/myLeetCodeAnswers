from queue import PriorityQueue

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        pq = PriorityQueue()
        for stone in stones:
            pq.put(-stone)  # negate to act as a max heap since it is a minHeap

        while pq.qsize() >= 2:
            stone1 = -pq.get()
            stone2 = -pq.get()
            if stone1 > stone2:
                pq.put(-(stone1 - stone2))

        return -pq.get() if not pq.empty() else 0


"""
another approach using sort
"""

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones.sort()
        while(len(stones)>1):
            stone1 = stones.pop()
            stone2 = stones.pop()
            if stone1 > stone2:
                stones.append(stone1-stone2)
                stones.sort()
        return stones[0] if stones else 0





