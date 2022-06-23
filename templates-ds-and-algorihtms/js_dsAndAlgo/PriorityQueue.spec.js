

import {PriorityQueue} from "./PriorityQueue.js";

describe("Test priority queue class", () => {

    test("Check basic characterictics of pq like the capacity must be 10 and have 1 element", () =>{
        let pq = new PriorityQueue(10);
        pq.insert(10);
        expect(pq.heap_size).toBe(1);
    });

    test("Check the states of PQ - sink & swim implementation - do insert & poll", () =>{
        let pq = new PriorityQueue(20);
        pq.insert(8);
        pq.insert(12);
        pq.insert(4);
        pq.insert(17);
        pq.insert(22);
        pq.insert(1);
        pq.myHeapData();
        pq.poll();
        pq.myHeapData();
        console.log("--------------");
        expect(pq.heap_size).toBe(5);
    });
    test("Check the states of PQ >> remove function", () =>{
        let pq = new PriorityQueue(20);
        pq.insert(8);
        pq.insert(12);
        pq.insert(4);
        pq.insert(17);
        pq.insert(22);
        pq.insert(1);
        pq.myHeapData();
        pq.remove(17);
        pq.myHeapData();
        expect(pq.heap_size).toBe(5);
    });
});
