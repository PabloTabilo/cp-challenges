const INF = 99999;
const debug = false;
export class PriorityQueue{
    constructor(capacity){
        this.heap_size = 0; // current numbers of elements
        this.capacity = capacity; // size of heap
        this.val = new Array(capacity); // values of heap
        for(let i = 0; i < capacity; i++){
            this.val[i] = INF;
        }
    }
    empty(){return this.heap_size == 0;}
    parent(i) {return ((i-1)/2)|0;}
    leftChild(i){return (2*i+1);}
    rightChild(i){return (2*i+2);}
    front(){return this.val[0]}
    poll(){
        // copiar last element on position  0
        // apply sink;
        this.val[0] = this.val[this.heap_size-1]
        this.val[this.heap_size-1] = INF;

        this.heap_size--;
        this.sink(0);
    }
    // up node i until hi is satisfied
    swim(i){
        while(this.parent(i) >= 0 && this.val[this.parent(i)] > this.val[i]){
            if(debug) console.log("index i: ", i, "; this.val[i]: ", this.val[i]);
            if(debug) console.log("this.parent(i): ", this.parent(i), "; this.val[this.parent(i)]: ", this.val[this.parent(i)]);
            this.swap(i, this.parent(i));
            i = this.parent(i);
        }
    }
    // down node i until leaf node
    sink(i){
        while (true){
            let left = this.leftChild(i);
            let right = this.rightChild(i);
            let smallest = left;
            if(debug) console.log(i, this.val[i], " - ",left, right, this.val[right], this.val[left]) 
            if(right <= this.heap_size-1 && this.val[right] < this.val[left]) smallest = right
            if(smallest > this.heap_size-1 || this.val[smallest] > this.val[i]) break
            this.swap(i, smallest);
            i = smallest;
        }
    }
    swap(i, down){
        // swap values
        let v_i = this.val[i];
        let v_d = this.val[down];
        this.val[i] = v_d;
        this.val[down] = v_i;
    }
    insert(newVal){
        if(this.heap_size == this.capacity){
            // Crear new arr with double capacity
            let t_val = this.val;
            this.val = new Array(2*this.capacity);
            for(let i = 0; i < capacity; i++){
                this.val[i] = INF;
            }
            this.capacity = 2*this.capacity;
            for(let i = 0; i < t_val.length; i++){
                this.val[i] = t_val[i];
            }
        }
        this.heap_size++;
        let i = this.heap_size - 1;
        if(debug) console.log("index: ", i,", newVal: " ,newVal);
        this.val[i] = newVal;
        this.swim(i);
    }
    remove(rm_val){
        let found = -1;
        for(let i=0; i<this.heap_size;i++){
            if(this.val[i] == rm_val){
                found = i;
                break;
            }
        }
        if(found != -1){
            this.val[found] = this.val[this.heap_size-1]
            this.val[this.heap_size-1] = INF;
            
            this.heap_size--;
            this.swim(found);
        }else{
            console.log("Not found");
        }
    }
    myHeapData(){
        console.log("On my heap: ")
        console.log("Values: ", this.val)
        console.log("this.heap_size: ", this.heap_size)
        console.log("this.capacity: ", this.capacity)
    }
}
