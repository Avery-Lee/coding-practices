#ifndef GUARD_Vec_h
#define GUARD_Vec_h

#include <memory>
#include <algorithm>
#include <stdexcept>


template <class T> class Vec {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef std::ptrdiff_t dirrerence_type;
	typedef T& reference;
	typedef const T& const_reference;

	Vec() { create(); }
	explicit Vec(size_type n, const T& val = T()) { create(n, val); }

	Vec(const Vec& v) { create(v.begin(), v.end()); }
	Vec& operator=(const Vec&);
	~Vec() { uncreate(); }


	T& operator[](size_type i) { return data[i]; }
	const T& operator[](size_type i) const { return data[i]; }

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

	void clear() { Vec_destroy(); }
	void erase(iterator) { Vec_destroy(iterator); }
	void erase(iterator, iterator) { Vec_destroy(iterator, iterator); }

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

	void Vec_destroy();
	iterator Vec_destroy(iterator iter);
	iterator Vec_destroy(iterator beg, iterator end);
};

#endif