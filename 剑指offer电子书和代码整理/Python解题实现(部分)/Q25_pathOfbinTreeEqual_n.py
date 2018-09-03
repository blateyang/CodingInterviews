# coding:utf-8
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def findPathRecur(root, expectNum, Sum, path, paths):
    Sum += root.val
    path.append(root.val)
    if root.left is None and root.right is None:
        if Sum == expectNum:
#            print path, paths
# 直接用paths.append(path)只是把path的引用加到paths中，会跟着path变，需要用深拷贝
            paths.append(path[:]) 
    if root.left:
        findPathRecur(root.left, expectNum, Sum, path, paths)
    if root.right:
        findPathRecur(root.right, expectNum, Sum, path, paths)
    path.pop()


def constructionCore(pre, tin):
    # 使用列表切片当C++中的指针或迭代器
    Len = len(pre)
    assert Len != 0, "List has no item"
    root = TreeNode(pre[0])
    if Len == 1:
        assert pre[0] == tin[0], "invalid input"
        return root
    root_tin_idx = 0
    while root_tin_idx < Len and tin[root_tin_idx] != pre[0]:
        root_tin_idx += 1
    assert root_tin_idx < Len, "invalid input"
    leftLen = root_tin_idx
    if leftLen > 0:  # 左子树不为空，构建左子树
        root.left = constructionCore(pre[1:1+leftLen], tin[:root_tin_idx])
    if leftLen < Len-1:  # 右子树不为空，构建右子树
        root.right = constructionCore(pre[1+leftLen:], tin[root_tin_idx+1:])
    return root


class Solution:
    def reConstructBinaryTree(self, pre, tin):
        if len(pre)*len(tin) == 0 or len(pre) != len(tin):
            return None
        return constructionCore(pre, tin)
    
        # 返回二维列表，内部每个列表表示找到的路径
    def FindPath(self, root, expectNumber):
        # write code here
        paths = []
        if root is None:
            return paths
        Sum = 0
        path = []
        findPathRecur(root, expectNumber, Sum, path, paths) # Sum要传递可变对象才是引用传递
        return paths


if __name__ == "__main__":
    pre = [10, 5, 4, 7, 12]
    tin = [4, 5, 7, 10, 12]
    s = Solution()
    tree = s.reConstructBinaryTree(pre, tin)
    if tree is not None:
        print tree.val, tree.left.val, tree.right.val
    paths = s.FindPath(tree, 22)
    print paths