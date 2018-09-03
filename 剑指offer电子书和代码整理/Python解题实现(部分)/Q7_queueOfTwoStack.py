# -*- coding:utf-8 -*-


class Solution:
    def __init__(self, stack1=[], stack2=[]):
        self.stack1 = stack1
        self.stack2 = stack2

    def push(self, node):
        # write code here
        self.stack1.append(node)

    def pop(self):
        # return xx
        if len(self.stack1) == 0:
            return 0
        while(len(self.stack1) > 1):
            self.stack2.append(self.stack1.pop())
        del_node = self.stack1.pop()
        while(len(self.stack2) > 0):
            self.stack1.append(self.stack2.pop())
        return del_node


if __name__ == "__main__":
    s = Solution()
    s.push(1)
    s.push(2)
    print s.pop()
