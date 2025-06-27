class Link {
    constructor(val, prev = null, next = null) {
        this.value = val;
        this.prev = prev;
        this.next = next;
    }
}

export class LinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
    }

    push(val) {
        let temp = new Link(val, this.head);
        if (this.head) this.head.next = temp;
        if (!this.tail) this.tail = temp;
        this.head = temp;
    }

    pop() {
        let out = this.head.value;
        this.head = this.head.prev;
        if (this.head) this.head.next = null;
        if (!this.head) this.tail = null;
        return out;
    }

    shift() {
        if (this.tail) {
            let out = this.tail.value;
            this.tail = this.tail.next;
            if (this.tail) this.tail.prev = null;
            return out;
        }
    }

    unshift(val) {
        let temp = new Link(val);
        if (this.tail) {
            temp.next = this.tail;
            this.tail.prev = temp;
        } else this.head = temp;
        this.tail = temp;
    }

    delete(val) {
        var cur = this.tail;
        while (cur) {
            if (cur.value == val) break;
            cur = cur.next;
        }

        if (cur == null) return;

        if (cur.next) cur.next.prev = cur.prev;
        else this.head = cur.prev;

        if (cur.prev) cur.prev.next = cur.next;
        else this.tail = cur.next;
    }

    count() {
        var cur = this.tail, out;
        for (out = 0; cur; out++) cur = cur.next;
        return out;
    }
}
