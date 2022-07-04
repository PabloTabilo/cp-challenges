
class BinaryTree:
    def __init__(self):
        self.root = None
        self.height = 0
        self.pos_bt = []

    def get_root():
        return self.root
    
    def add_new_node(self, new_node):
        if self.root is None: 
            self.root = new_node
            new_node.set_curr_height(0)
        else: self.add_child(self.root, self.root, True, new_node,0)

    def add_child(self, parent, current, l_bool, new_node, c_h):
        if current is None:
            self.height = max(self.height, c_h)
            if l_bool: parent.set_ref(new_node, 0)
            else: parent.set_ref(new_node,1)
            new_node.set_curr_height(c_h)
        else:
            if current.data > new_node.data:
                self.add_child(current,current.ref[0], True, new_node,c_h+1)
            else:
                self.add_child(current, current.ref[1], False, new_node,c_h+1)
    
    def inorder(self, current, pos_c):
        if current is not None:
            self.inorder(current.ref[0], 2*pos_c+1)
            self.pos_bt.append((pos_c, current.data, current.get_curr_height()))
            self.inorder(current.ref[1], 2*pos_c+2)
    
    def print_biarray(self, arr):
        for i in range(len(arr)):
            for j in range(len(arr[0])):
                print(arr[i][j], end=" ")
            print("\n")

    def print_bst(self):
        self.print_bst_position()
        self.pos_bt.sort(key=lambda x : x[0])
        
        p = self.height
        max_number_of_nodes = 2**(p+1) - 2
        pos_complete_bt = 0
        w = (2**p)*2-1
        h = p+1
        res = [[-1 for i in range(w)] for i in range(h)]
        yeah = True
        max_number_of_nodes_copy = max_number_of_nodes
        j = w-1
        while j >= 0:
            if yeah:
                res[p][j] = max_number_of_nodes_copy
                max_number_of_nodes_copy -= 1
                yeah = False
            else: yeah = True
            j-=1

        i = p-1
        while(i >= 0):
            last_i = i+1
            r = w-1
            nodes_on_level = 2**last_i
            while r > 0 and nodes_on_level > 0:
                while(res[last_i][r] == -1): r-=1
                l = r-1
                while(res[last_i][l] == -1): l-=1
                parent_idx = (l+r) // 2
                res[i][parent_idx] = max_number_of_nodes_copy
                max_number_of_nodes_copy -= 1
                nodes_on_level -= 2
                r = l - 1
            i-=1
        bool_res = [[False for i in range(w)] for i in range(h)]
        for k in range(len(self.pos_bt)):
            p = self.pos_bt[k][0] # position on complete BT node ith
            c = self.pos_bt[k][1] # cost node ith
            i = self.pos_bt[k][2] # height node ith
            for j in range(w):
                if res[i][j] == p and not bool_res[i][j]: 
                    res[i][j] = c
                    bool_res[i][j] = True
                    break
       
        for i in range(h):
            for j in range(w):
                if bool_res[i][j]: 
                    print(res[i][j],end=" ")
                else: print(" ", end=" ")
            print("\n")

    def print_bst_position(self):
        self.inorder(self.root, 0)
        print("\nInorder print")
        print(self.pos_bt)
        print("\n")

