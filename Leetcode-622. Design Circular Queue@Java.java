class MyCircularQueue {
    
    private final int CAPACITY;
    private int headIdx = 0;
    private int tailIdx = -1;
    private int count = 0;
    private int[] queue;

    public MyCircularQueue(int k) {
        this.queue = new int[k];
        this.CAPACITY = k;
    }
    
    public boolean enQueue(int value) {
        if(isFull()) {
            return false;
        }
        tailIdx = (tailIdx + 1) % CAPACITY;
        queue[tailIdx] = value;
        count += 1;
        return true;
    }
    
    public boolean deQueue() {
        if(isEmpty()) {
            return false;
        }
        queue[headIdx] = -1;
        headIdx = (headIdx + 1) % CAPACITY;
        count -= 1;
        return true;
    }
    
    public int Front() {
        if(isEmpty()) {
            return -1;
        }
        else {
            return queue[headIdx];
        }
    }
    
    public int Rear() {
        if(isEmpty()) {
            return -1;
        }
        else {
            return queue[tailIdx];
        }
    }
    
    public boolean isEmpty() {
        return count == 0;
    }
    
    public boolean isFull() {
        return count >= CAPACITY;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */