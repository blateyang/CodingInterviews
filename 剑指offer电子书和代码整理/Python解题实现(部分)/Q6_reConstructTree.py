# coding:utf-8
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


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


if __name__ == "__main__":
    pre = [1, 2, 4, 7, 3, 5, 6, 8]
    tin = [4, 7, 2, 1, 5, 3, 8, 6]
    s = Solution()
    tree = s.reConstructBinaryTree(pre, tin)
    if tree is not None:
        print tree.val, tree.left.val, tree.right.val