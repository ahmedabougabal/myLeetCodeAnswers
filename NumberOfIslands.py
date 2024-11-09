from collections import deque

class Queue:
    def __init__(self):
        self.items = deque()

    def is_empty(self):
        return not self.items

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        return self.items.popleft()

class Solution:
      
      def is_valid(self,grid, row, col):
          rows = len(grid)
          cols = len(grid[0])
          return 0 <= row < rows and 0 <= col < cols and grid[row][col] == '1'
      def bfs(self, grid, row,col):

        directions = [
            (0,1), # right
            (0,-1), # left 
            (-1,0), # up
            (1,0), # down
            ]
        
        q = Queue()
        q.enqueue((row,col))
        grid[row][col] = '0'
        while not q.is_empty():
            curr_row, curr_col = q.dequeue()
            for i,j in directions:
                new_row = i + curr_row
                new_col = j + curr_col
                #! if the new offset is '1' (valid) and unvisited  
                if self.is_valid(grid, new_row, new_col):
                    q.enqueue((new_row, new_col))
                    grid[new_row][new_col] = '0' #* end of bfs
                    
      def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        rows = len(grid)
        cols = len(grid[0])
        islands = 0
        for i in range(rows):
            for j in range(cols):
              if grid[i][j] == "1":
                  islands = islands+1
                  self.bfs(grid, i, j)
        return islands

if __name__ == "__main__":
    s = Solution()
    