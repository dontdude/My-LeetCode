/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
    int next_val;
    bool has_next_val;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods. 
        has_next_val = Iterator::hasNext(); // hasNext() method of inherited iterator class
        if(has_next_val) {
            next_val = Iterator::next(); 
        }
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return next_val;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int curr_val = next_val;
        has_next_val = Iterator::hasNext();
        if(has_next_val) {
            next_val = Iterator::next();
        }
        return curr_val;
	}
	
	bool hasNext() const {
	    return has_next_val;
	}
};