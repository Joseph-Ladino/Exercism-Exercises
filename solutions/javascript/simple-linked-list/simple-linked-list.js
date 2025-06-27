//
// This is only a SKELETON file for the 'Simple Linked List' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export class Element {
    constructor(val) {
        this.value = val;
        this.next = null;
    }
}

export class List {

    constructor(arr = []) {
        this.head = null;

        for (let i of arr) this.add(new Element(i));
    }

    add(nextValue) {
        let temp = this.head;
        this.head = nextValue;
        this.head.next = temp;
    }

    get length() {
        let out = 0, cur = this.head;
        for (out; cur != null; out++) cur = cur.next;
        return out;
    }

    toArray() {
        let out = [], cur = this.head;
        while (cur != null) {
            out.push(cur.value);
            cur = cur.next;
        }
        return out;
    }

    reverse() {
        return new List(this.toArray());
    }
}
