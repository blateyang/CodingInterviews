# -*- coding:utf-8 -*-
class Solution:
    def __init__(self, m_data=[], m_min=[]):
        self.m_data = m_data
        self.m_min = m_min
        
    def push(self, node):
        # write code here
        if len(self.m_data) == 0:
            self.m_data.append(node)
            self.m_min.append(node)
            return
        tmp_node = self.top()
        self.m_data.append(node)
        if tmp_node >= node:
            self.m_min.append(node)
        else:
            self.m_min.append(tmp_node)

    def pop(self):
        # write code here
        assert len(self.m_data) > 0, "stack is empty"
        self.m_data.pop()
        self.m_min.pop()

    def top(self):
        # write code here
        assert len(self.m_data) > 0, "stack is empty"
        return self.m_data[-1]

    def min(self):
        # write code here
        assert len(self.m_min) > 0, "stack is empty"
        return self.m_min[-1]


if __name__ == "__main__":
    s = Solution()
    s.push(3)
    s.push(4)
    print s.min()
    s.push(2)
    s.push(1)
    print s.min()
    s.pop()
    s.pop()
    print s.min()