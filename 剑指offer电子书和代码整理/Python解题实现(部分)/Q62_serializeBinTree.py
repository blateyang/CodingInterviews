# -*- coding:utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def ReadItem(s_list, num):
    num[0] = s_list[0]
    return False if num[0] == '$' else True

class Solution: # 参考剑指offer的思路
    def __init__(self):
        self.str = ''
        self.rootNode = None

    def Serialize(self, root):
        # write code here
        if root is None:
            self.str += "$,"
            return self.str
        self.str += str(root.val)+','
        self.Serialize(root.left)
        self.Serialize(root.right)
        return self.str

    def DeserializeIter(self, s_list):
        num = ['$'] # 需要设为可变对象，传参时才能把函数内部的值拿出来
        rootNode = None
        if(ReadItem(s_list, num)):
            rootNode = TreeNode(num[0])
        s_list.pop(0) # 去掉列表头元素
        if rootNode is not None:
            rootNode.left = self.DeserializeIter(s_list)
            rootNode.right = self.DeserializeIter(s_list)
        return rootNode
            
    def Deserialize(self, s):
        # write code here
        s_list = s[:-1].split(',')
        self.rootNode = self.DeserializeIter(s_list)
        return self.rootNode

root = TreeNode(1)
l1 = TreeNode(2)
r1 = TreeNode(3)
root.left, root.right = l1, r1
ll2 = TreeNode(4)
l1.left = ll2
rl2 = TreeNode(5)
rr2 = TreeNode(6)
r1.left, r1.right = rl2, rr2
s = Solution()
# result = s.Serialize(root)
# print(result)
result = s.Deserialize("1,2,4,$,$,$,3,5,$,$,6,$,$,")
# result = s.Deserialize("1,2,$,$,3,$,$,")
print(result.val)
print(result.left.val)
print(result.right.val)