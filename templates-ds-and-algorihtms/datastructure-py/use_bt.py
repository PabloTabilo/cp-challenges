from tqdm import tqdm
from node import BinaryNode as N
from binaryTree import BinaryTree as BT


if __name__=="__main__":
    i_bt = BT()
    #data = [30, 10, 40, 5, 35, 20, 50]
    #data = [30, 10, 5, 15]
    data = [10, 20, 30, 40, 50]
    for i in tqdm(data):
        i_node = N(i,2)
        i_bt.add_new_node(i_node)
    i_bt.print_bst()
