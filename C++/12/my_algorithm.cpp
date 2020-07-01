#include <vector>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <iterator>

using std::vector;
using std::string;
using std::domain_error;
using std::swap;

template <class T>
T median(vector<T> v)
{
	typedef typename vector<T>::size_type vec_sz;
	vec_sz size = v.size();

	if (size == 0)
		throw domain_error("median of an empty vector");

	sort(v.begin(), v.end());
	vec_sz mid = size / 2;

	return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

template <class T>
T my_max(const T& left, const T& right)
{
	return left > right ? left : right;
}

template <class In, class X>
In my_find(In begin, In end, const X& x)
{
	if (begin == end || *begin == x)
		return begin;

	begin++;
	return my_find(begin, end, x);
}


template <class In, class Pred>
In my_find_if(In beg, In end, Pred p)
{
	while (beg != end)
	{
		if (pred(*beg))
			return beg;
		++beg;
	}
	return end;
}

template <class In, class Pred>
In my_find_if_not(In beg, In end, Pred p)
{
	while (beg != end)
	{
		if (!pred(*beg))
			return beg;
		++beg;
	}
	return end;
}

template <class In, class Out>
Out my_copy(In begin, In end, Out dest)
{
	while (begin != end)
		*dest++ = *begin++;

	return dest;
}

template <class For, class X>
void my_replace(For beg, For end, const X& x, const X& y)
{
	while (beg != end) {
		if (*beg == x)
			*beg = y;

		++beg;
	}
}

template <class Bi>
void my_reverse(Bi begin, Bi end)
{
	while (begin != end) {
		--end;
		if (begin != end)
			swap(*begin++, *end);
	}
}

template <class Ran, class X>
bool my_binary_search(Ran begin, Ran end, const X& x)
{
	while (begin < end) {
		Ran mid = begin + (end - begin) / 2;

		if (x < *mid)
			end = mid;
		else if (*mid < x)
			begin = mid + 1;
		else return true;
	}
	return false;
}

bool space(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}

template <class Out>
void my_split(const string& str, Out os) {
	typedef string::const_iterator iter;
	iter i = str.begin();

	while (i != str.end()) {
		i = my_find_if(i, str.end(), not_space);

		iter j = my_find_if(i, str.end(), space);

		if (i != str.end())
			*os++ = string(i, j);

		i = j;
	}
}

template <class In>
bool my_equal(In beg, In end, In dest)
{
	while (beg != end)
	{
		if (*beg != *dest)
			return false;
		++beg;
		++dest;
	}
	return true;
}

template <class For1, class For2>
For1 my_search(For1 beg1, For1 end1, For2 beg2, For2 end2)
{
	if (beg2 == end2) return beg1;

	while (beg1 != end1) {
		For1 it1 = beg1;
		For2 it2 = beg2;

		while (*it1 == *it2) {
			if (it2 == end2) return beg1;
			if (it1 == end1) return end1;
			++it1;
			++it2;
		}
		++beg1;
	}
	return end1;
}


template <class In, class Dest, class X>
Dest my_remove_copy(In beg, In end, Dest d, const X& val)
{
	while (beg != end) {
		if (*beg != val)
			*d++ = *beg;
		++beg;
	}
	return d;
}

template <class In, class Dest, class Pred>
Dest my_remove_copy_if(In beg, In end, Dest d, Pred p)
{
	while (beg != end) {
		if (!p(*beg))
			*d++ = *beg;
		++beg;
	}
	return d;
}

template <class For, class T>
For my_remove(For beg, For end, const T& tar) {
	For inst = beg;
	while (beg != end) {
		if (beg != tar)
			*inst++ = *beg;
		++beg;
	}
	return inst;
}

template <class In, class Out, class Oper>
In my_transform(In beg, In end, Out dest, Oper op)
{
	while (beg != end)
		*dest++ = pref(*beg++);
	return dest;
}

template <class For, class Pred>
For my_partition(For beg, For end, Pred p)
{
	For inst = beg;

	while (beg != end) 
	{
		if (p(*beg))
			swap(*inst++, *beg);
		
		++beg;
	}
	return inst;
}

template <class In, class T>
T my_accumulate(In beg, In end, T& t)
{
	T obj = t;

	while (beg != end)
		obj = obj + *beg;

	return t;
}

template <class In, class T, class Oper>
T my_accumulate(In beg, In end, T& t, Oper op)
{
	T obj = t;

	while (beg != end)
	{
		obj = op(obj, *beg);
		++beg;
	}
	return t;
}