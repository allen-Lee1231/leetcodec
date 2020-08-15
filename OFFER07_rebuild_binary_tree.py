# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

    @staticmethod
    def buildTree(preorder: list, inorder: list):
        if len(preorder) < 1:
            return None

        # inorder_idx = -1
        for j, _ in enumerate(inorder):
            if _ == preorder[0]:
                inorder_idx = j
                break

        currentNode = TreeNode(preorder[0])
        currentNode.left = TreeNode.buildTree(preorder[1: inorder_idx + 1], inorder[:inorder_idx])
        currentNode.right = TreeNode.buildTree(preorder[inorder_idx + 1:], inorder[inorder_idx + 1:])

        return currentNode


if __name__ == '__main__':
    preorder = [3, 9, 20, 15, 7]
    inorder = [9, 3, 15, 20, 7]


    def printTree(nodes: list):
        if len(nodes) == 0:
            return

        container = []
        for node in nodes:
            print(node.val)
            if node.left:
                container.append(node.left)

            if node.right:
                container.append(node.right)

        printTree(container)


    rebuiltRoot = TreeNode.buildTree(preorder, inorder)
    printTree([rebuiltRoot])