# -*- coding:utf-8 -*-


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def convertNode(pNode, pLastNodeInList):
    if pNode:  # 如果pNode为空，直接返回
        return
    pCurrent = pNode
    if pCurrent.left:
        convertNode(pCurrent.left, pLastNodeInList)
    pCurrent.left = pLastNodeInList[0]
    if pLastNodeInList[0]:
        pLastNodeInList[0].right = pCurrent
    pLastNodeInList[0] = pCurrent
    if pCurrent.right:
        convertNode(pCurrent.right, pLastNodeInList)
        

class Solution:
    def Convert(self, pRootOfTree):
        # write code here
        pLastNodeInList = [None]
        convertNode(pRootOfTree, pLastNodeInList)
        pHeadOfList = pLastNodeInList[0]
        while pHeadOfList and pHeadOfList.left:
            pHeadOfList = pHeadOfList.left
        return pHeadOfList


s = Solution()
n1 = TreeNode(10)
n2 = TreeNode(6)
n3 = TreeNode(14)
n1.left = n2
n1.right = n3
result = s.Convert(n1)
print(result.val, result.right.val, result.right.right.val)