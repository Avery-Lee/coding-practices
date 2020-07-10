#ifndef GUARD_List_h
#define GUARD_List_h

#include <memory>
#include <algorithm>

template <class T> class List{
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;
	typedef T& reference;
	typedef const T& const_reference;

	List() { create(); }
	explicit List(size_type n, const T& val = T()) { create(n, val); }

	List(const List& l) { create(l.begin(), l.end()); }
	List& operator=(const List&);
	~List() { uncreate(); }

	void push_back(const T& val) {
		if (avail == limit)
			grow();
		unchecked_append(val);
	}

	size_type size() const { return avail - data; }

	iterator begin() { return data; }
	const_iterator begin() { return data; }

	iterator end() { return avail; }
	const_iterator end() { return avail; }


private:
	iterator data;
	iterator avail;
	iterator limit;

	std::allocator<T> alloc;

	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	void uncreate();

	void grow();
	void unchecked_append(const T&);
	
	void List_destroy();
	iterator List_destroy(iterator iter);
	iterator List_destroy(iterator beg, iterator end);
};

#endif