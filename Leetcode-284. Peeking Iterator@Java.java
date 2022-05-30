// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html

class PeekingIterator implements Iterator<Integer> {
    
    private Integer current = null;
    private Iterator<Integer> it = null;
    
	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
        this.it = iterator;
        updateCurrent();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        return current;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    Integer result = this.current;
        updateCurrent();
        return result;
	}
	
	@Override
	public boolean hasNext() {
	    return this.current != null;
	}
    
    private void updateCurrent() {
        if(this.it.hasNext()) {
            this.current = this.it.next();
        }
        else {
            this.current = null;
        }
    }
}