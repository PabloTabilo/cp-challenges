import unittest
from node import Node, WhereIsError

class TestNodeMethods(unittest.TestCase):
    def test_basic_node(self):
        instance_node = Node()
        self.assertEqual(instance_node.get_data(), 0)
        self.assertEqual(len(instance_node.get_ref()), 1)

    def test_node_data(self):
        instance_node = Node(15)
        self.assertEqual(instance_node.get_data(), 15)

    def test_node_reference(self):
        datas = [12, 3]
        n3 = Node(datas[1])
        n2 = Node(datas[0])
        n1 = Node(10,2)
        n1.set_ref(n2)
        n1.set_ref(n3)
        max_n = n1.get_max_num_ref()
        i = 0
        while i < max_n:
            data_i = n1.get_ref(i).get_data()
            self.assertEqual(data_i, datas[i])
            i+=1

    def test_error_with_position_reference(self):
        with self.assertRaises(WhereIsError) as context:
            Node(2,2).set_ref(Node(1),3)
        self.assertEqual(context.exception.message, "The number of referencies is max, in this case: {} or the specific position is imposible, the position is : {}".format(2, 3))

if __name__ == '__main__':
    unittest.main()


