# coding:utf-8
# 剑指offer思路：用两个栈S1和S2实现，S1用来存奇数层的节点，S2用来存偶数层的节点，在打印S1中的节点时，将其节点入栈到S2中。当一个栈为空后，交换处理两栈 

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def Print(self, pRoot):
        # write code here
        result = []
        if pRoot is not None: # 或者直接if pRoot
            # 设置两个栈（列表）并将根节点存入第一个栈
            stack_arr = [[pRoot]]
            stack_arr.append([])
            current = 0
            cur_level = []
            while len(stack_arr[0]) != 0 or len(stack_arr[1]) != 0:
                pNode = stack_arr[current][-1]
                cur_level.append(pNode.val)
                if current == 0: # 当前栈是s0,孩子节点从左向右入栈s1
                    if pNode.left is not None:
                        stack_arr[1].append(pNode.left)
                    if pNode.right is not None:
                        stack_arr[1].append(pNode.right)
                else:           # 当前栈是s1，孩子节点从右向左入栈s0
                    if pNode.right is not None:
                        stack_arr[0].append(pNode.right)
                    if pNode.left is not None:
                        stack_arr[0].append(pNode.left)
                stack_arr[current].pop() # 访问完一个节点后从当前栈弹出
                if len(stack_arr[current]) == 0: # 当前栈为空后，交换处理另一个栈
                    current = 1-current
                    result.append(cur_level)
                    cur_level = []
        return result

s = Solution()
root = TreeNode(1)
l1, r1 = TreeNode(2), TreeNode(3)
root.left = l1
root.right = r1
ll2, lr2 = TreeNode(4), TreeNode(5)
l1.left = ll2
l1.right = lr2
result = s.Print(root)
print result