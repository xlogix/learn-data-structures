class Node(int):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


class BST(int):
    def __init__(self, root):
        self.root = Node(root)

    def insert(self, new_val):
        self.insert_helper(self.root, new_val)

    def insert_helper(self, cur_top, val):
        if (cur_top > val):
            if cur_top.right:
                self.insert_helper(cur_top.right, val)
            else:
                cur_top.left = Node(val)
        if cur_top < val:
            if cur_top.left:
                self.insert_helper(cur_top.left, val)
            else:
                cur_top.left = Node(val)

    def search(self, find_val):
        return self.search_helper(self.root, find_val)

    def search_helper(self, cur_top, val):
        if cur_top:
            if cur_top.value == val:
                return True
            else:
                if val > cur_top.value:
                    return self.search_helper(cur_top.right, val)
                else:
                    return self.search_helper(cur_top.left, val)
        else:
            return False


# Set up tree
tree = BST(4)

# Insert elements
tree.insert(2)
tree.insert(1)
tree.insert(3)
tree.insert(5)

# Check search
# Should be True
print(tree.search(4))
# Should be False
print(tree.search(6))
