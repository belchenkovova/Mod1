#pragma once

#include "engine_gl/namespace.h"


template					<typename type>
class						mod1_engine_gl::point2
{
public :

MOD1_GENERATE_EXCEPTION(exception_index, "Mod1 Engine GL, Point2 : Bad index")

	type					x = 0;
	type					y = 0;

							point2() = default;

	explicit				point2(type value)
	{
		this->x = value;
		this->y = value;
	}
							point2(type x, type y)
	{
		this->x = x;
		this->y = y;
	}

	template 				<typename point_like>
	explicit				point2(const point_like &point)
	{
		this->x = point.x;
		this->y = point.y;
	}
							~point2() = default;

	point2<type>			operator + (const point2<type> &other) const
	{
		return (point2<type>(this->x + other.x, this->y + other.y));
	}

	point2<type>			operator - (const point2<type> &other) const
	{
		return (point2<type>(this->x - other.x, this->y - other.y));
	}

	point2<type>			operator * (const point2<type> &other) const
	{
		return (point2<type>(this->x * other.x, this->y * other.y));
	}

	template 				<typename another_type>
	point2<type>			operator * (const another_type &other) const
	{
		return (point2<type>(this->x * other, this->y * other));
	}

	point2<type>			operator / (const point2<type> &other) const
	{
		return (point2<type>(this->x / other.x, this->y / other.y));
	}

	template 				<typename another_type>
	point2<type>			operator / (const another_type &other) const
	{
		return (point2<type>(this->x / other, this->y / other));
	}

	void					operator += (const point2<type> &other)
	{
		this->x += other.x;
		this->y += other.y;
	}

	void					operator -= (const point2<type> &other)
	{
		this->x -= other.x;
		this->y -= other.y;
	}

	void					operator *= (const point2<type> &other)
	{
		this->x *= other.x;
		this->y *= other.y;
	}

	template 				<typename another_type>
	void					operator *= (const another_type &other)
	{
		this->x *= other;
		this->y *= other;
	}

	void					operator /= (const point2<type> &other)
	{
		this->x /= other.x;
		this->y /= other.y;
	}

	template 				<typename another_type>
	void					operator /= (const another_type &other)
	{
		this->x /= other;
		this->y /= other;
	}

	type					&operator [] (int i)
	{
		switch (i)
		{
			case 0 :
				return (x);
			case 1 :
				return (y);
			default :
				throw (exception_index());
		}
	}

	const type				&operator [] (int i) const
	{
		switch (i)
		{
			case 0 :
				return (x);
			case 1 :
				return (y);
			default :
				throw (exception_index());
		}
	}

	template 				<typename another_type>
	explicit				operator point2<another_type> () const
	{
		return (point2<another_type>(this->x, this->y));
	}

	template 				<class point_like>
	point2<type>			&operator = (const point_like &point)
	{
		this->x = point.x;
		this->y = point.y;
		return (*this);
	}

	bool					operator == (const point2<type> &other)
	{
		if (this->x != other.x)
			return (false);
		if (this->y != other.y)
			return (false);
		return (true);
	}

	friend bool				operator < (const point2<type> &left, const point2<type> &right)
	{
		return (left.x < right.x and left.y < right.y);
	}

	friend bool				operator > (const point2<type> &left, const point2<type> &right)
	{
		return (left.x > right.x and left.y > right.y);
	}

	static point2<type>		min(const point2<type> &a, const point2<type> &b)
	{
		return (point2<type>(MOD1_MIN(a.x, b.x), MOD1_MIN(a.y, b.y)));
	}

	static point2<type>		max(const point2<type> &a, const point2<type> &b)
	{
		return (point2<type>(MOD1_MAX(a.x, b.x), MOD1_MAX(a.y, b.y)));
	}

	type					*data()
	{
		return (&x);
	}

	const type				*data() const
	{
		return (&x);
	}

	int 					size_in_bytes() const
	{
		return (2 * sizeof(type));
	}

	friend std::ostream		&operator << (std::ostream& stream, const point2 &point)
	{
		stream << "(";
		stream << point.x;
		stream << ", ";
		stream << point.y;
		stream << ")";
		return (stream);
	}

	friend std::istream		&operator >> (std::istream& stream, point2 &point)
	{
		char 				pattern[3];

		stream >> pattern[0] >> point.x >> pattern[1] >> point.y >> pattern[2];
		if (pattern[0] != '(' or pattern[1] != ',' or pattern[2] != ')')
			stream.setstate(std::ios::failbit);
		return (stream);
	}
};
