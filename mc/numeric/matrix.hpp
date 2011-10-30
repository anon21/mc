#ifndef MC_NUMERIC_MATRIX_HPP_
#define MC_NUMERIC_MATRIX_HPP_

#include <valarray>

namespace mc {
namespace numeric {

using std::valarray;

template<class T>
class matrix {
	typedef matrix<T> self_type;
	
public:
	typedef T value_type;
	
	matrix(size_t nr, size_t nc) : v_(nr * nc), n_(nc)
	{
	}
	
	matrix(size_t nr, size_t nc, value_type const& val) : v_(val, nr * nc), n_(nc)
	{
	}
	
	self_type& operator=(self_type const& m)
	{
		v_ = m.v_;
		return *this;
	}
	
	self_type& operator+=(self_type const& m)
	{
		v_ += m.v_;
		return *this;
	}
	
	self_type& operator-=(self_type const& m)
	{
		v_ -= m.v_;
		return *this;
	}
	
	self_type& operator*=(value_type const& val)
	{
		v_ *= val;
		return *this;
	}
	
	self_type& operator/=(value_type const& val)
	{
		v_ /= val;
		return *this;
	}
	
private:
	valarray<T> v_;
	size_t n_;
};

}; // namespace numeric
}; // namespace mc

#endif MC_NUMERIC_MATRIX_HPP_

