
class WhereIsError(Exception):
    def __init__(self, message):
        self.message = message
        super().__init__(self.message)

class Node:
    def __init__(self, data=0, num_ref=1):
        self.data = data
        self.pos = 0
        self.n = num_ref
        self.ref = [None]*num_ref
   
    def get_max_num_ref(self) -> int:
        return self.n

    def get_data(self) -> int:
        return self.data

    def get_ref(self, spec_pos=None) -> list:
        if spec_pos is None: return self.ref
        if spec_pos < self.n and spec_pos >= 0: return self.ref[spec_pos]
   
    def set_data(self,data):
        self.data=data

    def set_ref(self, new_node, spec_pos=None):
        if spec_pos is None and self.pos < self.n:
            self.ref[self.pos] = new_node
            self.pos+=1
        elif spec_pos is not None and spec_pos < self.n and spec_pos >= 0:
            self.ref[spec_pos] = new_node
        else:
            error = "The number of referencies is max, in this case: {} or the specific position is imposible, the position is : {}".format(self.n, spec_pos)
            raise WhereIsError(error)



