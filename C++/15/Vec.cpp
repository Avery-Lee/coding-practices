#include "Vec.h"

template <class T> Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
	if (&rhs != this) {
		uncreate();

		create(rhs.begin(), rhs.end());
	}
	return *this;
}

template <class T> void Vec<T>::create()
{
	data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val)
{
	data = alloc.allocate(n);
	limit = avail = data + n;
	uninitialized_fil(data, limit, val);
}

template <class T> void Vec<T>::create(const_iterator i, const_iterator j)
{
	data = alloc.allocate(j - i);
	limit = avail = unitialized_copy(i, j, data);
}

template <class T> void Vec<T>::uncreate()
{
	if (data) {
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);
		
		alloc.deallocate(data, limit - data);

		data = limit = avail = 0;
	}
}

template <class T> void Vec<T>::grow()
{
	size_type new_size = max(2 * (limit - data), ptrdiff_t(1));
	
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = uninitialized_copy(data, avail, new_data);

	uncreate();

	data = new_data;
	avail = new_avail;

	limit = data + new_size;
}

template <class T> void Vec<T>::unchecked_append(const T& val)
{
	alloc.construct(avail++, val);
}

template <class T> void Vec<T>::Vec_destroy()
{
	if (data) {
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);
	}
	avail = data;
}


template <class T>
typename Vec<T>::iterator Vec<T>::Vec_destroy(iterator iter)
{
	if (data && iter != avail)
	{
		alloc.destroy(iter);
		iterator it = iter + 1;

		while (it != avail)
		{
			alloc.construct(iter++, *it++);
			alloc.destroy(iter);
		}
		avail = iter;
	}
	return avail;
}

template <class T>
typename Vec<T>::iterator Vec<T>::Vec_destroy(iterator beg, iterator end)
{
	if (beg != end && data && beg != avail)
	{
		iterator it = beg;
		while (it != end)
			alloc.destroy(it++);

		while (end != avail)
		{
			alloc.construct(beg++, *end);
			alloc.destroy(end++);
		}
		avail = beg;
	}
	return avail;
}

int main()
{

}