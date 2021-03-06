//-------------------------------------------------------------
// Based on Variant.cc in the Physics eXtension Library (PXL) -
// http://vispa.physik.rwth-aachen.de/                        -
// Licensed under a LGPL-2 or later license                   -
//-------------------------------------------------------------
#include "radiopropa/Variant.h"

#include <algorithm>

namespace radiopropa
{

Variant::Variant() :
		type(TYPE_NONE)
{
}

Variant::~Variant()
{
	clear();
}

Variant::Variant(const Variant& a) :
		type(TYPE_NONE)
{
	copy(a);
}

Variant::Variant(const char *s)
{
	data._String = new std::string(s);
	type = TYPE_STRING;
}


void Variant::clear()
{
	if (type == TYPE_STRING)
	{
		if(data._String)
		{
			delete data._String;
			data._String = NULL;
		}

	}

	type = TYPE_NONE;
}

void Variant::check(const Type t) const
{
	if (type != t)
		throw bad_conversion(type, t);
}

void Variant::check(const Type t)
{
	if (type == TYPE_NONE)
	{
		std::memset(&data, 0, sizeof(data));
		switch (t)
		{
		case TYPE_STRING:
			data._String = new std::string;
			break;
		default:
			break;
		}
		type = t;
	}
	else if (type != t)
	{
		throw bad_conversion(type, t);
	}
}

const std::type_info& Variant::getTypeInfo() const
{
	if (type == TYPE_BOOL)
	{
		const std::type_info &ti = typeid(data._Bool);
		return ti;
	}
	else if (type == TYPE_CHAR)
	{
		const std::type_info &ti = typeid(data._Char);
		return ti;
	}
	else if (type == TYPE_UCHAR)
	{
		const std::type_info &ti = typeid(data._UChar);
		return ti;
	}
	else if (type == TYPE_INT16)
	{
		const std::type_info &ti = typeid(data._Int16);
		return ti;
	}
	else if (type == TYPE_UINT16)
	{
		const std::type_info &ti = typeid(data._UInt16);
		return ti;
	}
	else if (type == TYPE_INT32)
	{
		const std::type_info &ti = typeid(data._Int32);
		return ti;
	}
	else if (type == TYPE_UINT32)
	{
		const std::type_info &ti = typeid(data._UInt32);
		return ti;
	}
	else if (type == TYPE_INT64)
	{
		const std::type_info &ti = typeid(data._Int64);
		return ti;
	}
	else if (type == TYPE_UINT64)
	{
		const std::type_info &ti = typeid(data._UInt64);
		return ti;
	}
	else if (type == TYPE_FLOAT)
	{
		const std::type_info &ti = typeid(data._Float);
		return ti;
	}
	else if (type == TYPE_DOUBLE)
	{
		const std::type_info &ti = typeid(data._Double);
		return ti;
	}
	else if (type == TYPE_STRING)
	{
		const std::type_info &ti = typeid(*data._String);
		return ti;
	}
	else
	{
		const std::type_info &ti = typeid(0);
		return ti;
	}

}

const char *Variant::getTypeName(Type type)
{
	if (type == TYPE_NONE)
	{
		return "none";
	}
	else if (type == TYPE_BOOL)
	{
		return "bool";
	}
	else if (type == TYPE_CHAR)
	{
		return "char";
	}
	else if (type == TYPE_UCHAR)
	{
		return "uchar";
	}
	else if (type == TYPE_INT16)
	{
		return "int16";
	}
	else if (type == TYPE_UINT16)
	{
		return "uint16";
	}
	else if (type == TYPE_INT32)
	{
		return "int32";
	}
	else if (type == TYPE_UINT32)
	{
		return "uint32";
	}
	else if (type == TYPE_INT64)
	{
		return "int64";
	}
	else if (type == TYPE_UINT64)
	{
		return "uint64";
	}
	else if (type == TYPE_FLOAT)
	{
		return "float";
	}
	else if (type == TYPE_DOUBLE)
	{
		return "double";
	}
	else if (type == TYPE_STRING)
	{
		return "string";
	}
	else
	{
		return "unknown";
	}
}

Variant::Type Variant::toType(const std::string &name)
{
	if (name == "none")
	{
		return TYPE_NONE;
	}
	else if (name == "bool")
	{
		return TYPE_BOOL;
	}
	else if (name == "char")
	{
		return TYPE_CHAR;
	}
	else if (name == "uchar")
	{
		return TYPE_UCHAR;
	}
	else if (name == "int16")
	{
		return TYPE_INT16;
	}
	else if (name == "uint16")
	{
		return TYPE_UINT16;
	}
	else if (name == "int32")
	{
		return TYPE_INT32;
	}
	else if (name == "uint32")
	{
		return TYPE_UINT32;
	}
	else if (name == "int64")
	{
		return TYPE_INT64;
	}
	else if (name == "uint64")
	{
		return TYPE_UINT64;
	}
	else if (name == "float")
	{
		return TYPE_FLOAT;
	}
	else if (name == "double")
	{
		return TYPE_DOUBLE;
	}
	else if (name == "string")
	{
		return TYPE_STRING;
	}
	else
	{
		return TYPE_NONE;
	}
}

bool Variant::operator ==(const Variant &a) const
{
	if (type != a.type)
		return false;
	if (type == TYPE_BOOL)
	{
		return (data._Bool == a.data._Bool);
	}
	else if (type == TYPE_CHAR)
	{
		return (data._Char == a.data._Char);
	}
	else if (type == TYPE_UCHAR)
	{
		return (data._UChar == a.data._UChar);
	}
	else if (type == TYPE_INT16)
	{
		return (data._Int16 == a.data._Int16);
	}
	else if (type == TYPE_UINT16)
	{
		return (data._UInt16 == a.data._UInt16);
	}
	else if (type == TYPE_INT32)
	{
		return (data._Int32 == a.data._Int32);
	}
	else if (type == TYPE_UINT32)
	{
		return (data._UInt32 == a.data._UInt32);
	}
	else if (type == TYPE_INT64)
	{
		return (data._Int64 == a.data._Int64);
	}
	else if (type == TYPE_UINT64)
	{
		return (data._UInt64 == a.data._UInt64);
	}
	else if (type == TYPE_FLOAT)
	{
		return (data._Float == a.data._Float);
	}
	else if (type == TYPE_DOUBLE)
	{
		return (data._Double == a.data._Double);
	}
	else if (type == TYPE_STRING)
	{
		return (*data._String == *a.data._String);
	}
	else
	{
		throw std::runtime_error("compare operator not implemented");
	}
}

std::string Variant::toString() const
{
	if (type == TYPE_STRING)
		return *data._String;

	std::stringstream sstr;
	if (type == TYPE_BOOL)
	{
		sstr << data._Bool;
	}
	else if (type == TYPE_CHAR)
	{
		sstr << data._Char;
	}
	else if (type == TYPE_UCHAR)
	{
		sstr << data._UChar;
	}
	else if (type == TYPE_INT16)
	{
		sstr << data._Int16;
	}
	else if (type == TYPE_UINT16)
	{
		sstr << data._UInt16;
	}
	else if (type == TYPE_INT32)
	{
		sstr << data._Int32;
	}
	else if (type == TYPE_UINT32)
	{
		sstr << data._UInt32;
	}
	else if (type == TYPE_INT64)
	{
		sstr << data._Int64;
	}
	else if (type == TYPE_UINT64)
	{
		sstr << data._UInt64;
	}
	else if (type == TYPE_FLOAT)
	{
		sstr << std::scientific << data._Float;
	}
	else if (type == TYPE_DOUBLE)
	{
		sstr << std::scientific << data._Double;
	}

	return sstr.str();
}

Variant Variant::fromString(const std::string &str, Type type)
{
	std::stringstream sstr(str);
	switch (type)
	{
	case TYPE_BOOL:
	{
		std::string upperstr(str);
		std::transform(upperstr.begin(), upperstr.end(), upperstr.begin(),
				(int(*)(int))toupper);if
(		upperstr == "YES")
		return Variant(true);
		else if (upperstr == "NO")
		return Variant(false);
		if (upperstr == "TRUE")
			return Variant(true);
		else if (upperstr == "FALSE")
			return Variant(false);
		if (upperstr == "1")
			return Variant(true);
		else if (upperstr == "0")
			return Variant(false);
		throw bad_conversion(type, TYPE_BOOL);
	}
	case TYPE_CHAR:
	{
		char c;
		sstr >> c;
		return Variant(c);
	}
	case TYPE_UCHAR:
	{
		unsigned char c;
		sstr >> c;
		return Variant(c);
	}
	case TYPE_INT16:
	{
		int16_t c;
		sstr >> c;
		return Variant(c);
	}
	case TYPE_UINT16:
	{
		uint16_t c;
		sstr >> c;
		return Variant(c);
	}
	case TYPE_INT32:
	{
		int32_t c;
		sstr >> c;
		return Variant(c);
	}
	case TYPE_UINT32:
	{
		uint32_t c;
		sstr >> c;
		return Variant(c);
	}
	case TYPE_INT64:
	{
		int64_t c;
		sstr >> c;
		return Variant(c);
	}
	case TYPE_UINT64:
	{
		uint64_t c;
		sstr >> c;
		return Variant(c);
	}
	case TYPE_FLOAT:
	{
		float c;
		sstr >> c;
		return Variant(c);
	}
	case TYPE_DOUBLE:
	{
		double c;
		sstr >> c;
		return Variant(c);
	}
	case TYPE_STRING:
	{
		return Variant(str);
	}
	default:
		throw std::runtime_error("pxl::Variant::fromString: unknown type");
	}

}

bool Variant::operator !=(const Variant &a) const
{
	if (type != a.type)
		return true;

	switch (type)
	{
	case TYPE_BOOL:
		return (data._Bool != a.data._Bool);
	case TYPE_CHAR:
		return (data._Char != a.data._Char);
	case TYPE_UCHAR:
		return (data._UChar != a.data._UChar);
	case TYPE_INT16:
		return (data._Int16 != a.data._Int16);
	case TYPE_UINT16:
		return (data._UInt16 == a.data._UInt16);
	case TYPE_INT32:
		return (data._Int32 == a.data._Int32);
	case TYPE_UINT32:
		return (data._UInt32 == a.data._UInt32);
	case TYPE_INT64:
		return (data._Int64 == a.data._Int64);
	case TYPE_UINT64:
		return (data._UInt64 == a.data._UInt64);
	case TYPE_FLOAT:
		return (data._Float == a.data._Float);
	case TYPE_DOUBLE:
		return (data._Double == a.data._Double);
	case TYPE_STRING:
		return (*data._String == *a.data._String);
	default:
		throw std::runtime_error("compare operator not implemented");
	}
}


void Variant::copy(const Variant &a)
{
	Type t = a.type;
	if (t == TYPE_BOOL)
	{
		operator =(a.data._Bool);
	}
	else if (t == TYPE_CHAR)
	{
		operator =(a.data._Char);
	}
	else if (t == TYPE_UCHAR)
	{
		operator =(a.data._UChar);
	}
	else if (t == TYPE_INT16)
	{
		operator =(a.data._Int16);
	}
	else if (t == TYPE_UINT16)
	{
		operator =(a.data._UInt16);
	}
	else if (t == TYPE_INT32)
	{
		operator =(a.data._Int32);
	}
	else if (t == TYPE_UINT32)
	{
		operator =(a.data._UInt32);
	}
	else if (t == TYPE_INT64)
	{
		operator =(a.data._Int64);
	}
	else if (t == TYPE_UINT64)
	{
		operator =(a.data._UInt64);
	}
	else if (t == TYPE_FLOAT)
	{
		operator =(a.data._Float);
	}
	else if (t == TYPE_DOUBLE)
	{
		operator =(a.data._Double);
	}
	else if (t == TYPE_STRING)
	{
		operator =(*a.data._String);
	}
	else
	{
		type = TYPE_NONE;
	}
}

bool Variant::toBool() const
{
	switch (type)
	{
	case TYPE_BOOL:
		return data._Bool;
		break;
	case TYPE_CHAR:
		return data._Char != 0;
		break;
	case TYPE_UCHAR:
		return data._UChar != 0;
		break;
	case TYPE_INT16:
		return data._Int16 != 0;
		break;
	case TYPE_UINT16:
		return data._UInt16 != 0;
		break;
	case TYPE_INT32:
		return data._Int32 != 0;
		break;
	case TYPE_UINT32:
		return data._UInt32 != 0;
		break;
	case TYPE_INT64:
		return data._Int64 != 0;
		break;
	case TYPE_UINT64:
		return data._UInt64 != 0;
		break;
	case TYPE_STRING:
	{
		std::string upperstr(*data._String);
		std::transform(upperstr.begin(), upperstr.end(), upperstr.begin(),
				(int(*)(int))toupper);if
(		upperstr == "YES")
		return true;
		else if (upperstr == "NO")
		return false;
		if (upperstr == "TRUE")
			return true;
		else if (upperstr == "FALSE")
			return false;
		if (upperstr == "1")
			return true;
		else if (upperstr == "0")
			return false;
		else
			throw bad_conversion(type, TYPE_BOOL);
	}
		break;
	case TYPE_FLOAT:
	case TYPE_DOUBLE:
	case TYPE_NONE:
		throw bad_conversion(type, TYPE_BOOL);
		break;
	}
	return false;
}

#define INT_CASE(from_var, from_type, to_type, to) \
	case Variant::from_type:\
		if (data._##from_var < std::numeric_limits<to>::min() || data._##from_var > std::numeric_limits<to>::max())\
			throw bad_conversion(type, to_type);\
		else\
			return static_cast<to>(data._##from_var);\
		break;\

#define INT_FUNCTION(to_type, fun, to) \
to Variant::fun() const { \
	switch (type) { \
	case Variant::TYPE_BOOL: \
		return data._Bool ? 1 : 0; \
		break; \
	INT_CASE(Char, TYPE_CHAR, to_type, to) \
	INT_CASE(UChar, TYPE_UCHAR, to_type, to) \
	INT_CASE(Int16, TYPE_INT16, to_type, to) \
	INT_CASE(UInt16, TYPE_UINT16, to_type, to) \
	INT_CASE(Int32, TYPE_INT32, to_type, to) \
	INT_CASE(UInt32, TYPE_UINT32, to_type, to) \
	INT_CASE(Int64, TYPE_INT64, to_type, to) \
	INT_CASE(UInt64, TYPE_UINT64, to_type, to) \
	INT_CASE(Float, TYPE_FLOAT, to_type, to) \
	INT_CASE(Double, TYPE_DOUBLE, to_type, to) \
	case Variant::TYPE_STRING: \
		{ \
		long l = atol(data._String->c_str()); \
		if (l < std::numeric_limits<to>::min() || l > std::numeric_limits<to>::max()) \
			throw bad_conversion(type, to_type); \
		else \
			return l; \
		} \
		break; \
	case Variant::TYPE_NONE: \
		throw bad_conversion(type, TYPE_INT16); \
		break;\
	}\
	return 0;\
}

INT_FUNCTION( TYPE_CHAR, toChar, char)
INT_FUNCTION( TYPE_UCHAR, toUChar, unsigned char)
INT_FUNCTION( TYPE_INT16, toInt16, int16_t)
INT_FUNCTION( TYPE_UINT16, toUInt16, uint16_t)
INT_FUNCTION( TYPE_INT32, toInt32, int32_t)
INT_FUNCTION( TYPE_UINT32, toUInt32, uint32_t)
INT_FUNCTION( TYPE_INT64, toInt64, int64_t)
INT_FUNCTION( TYPE_UINT64, toUInt64, uint64_t)

std::ostream& operator <<(std::ostream& os, const Variant &v)
{
	switch (v.getType())
	{
	case Variant::TYPE_BOOL:
		os << v.asBool();
		break;
	case Variant::TYPE_CHAR:
		os << v.asChar();
		break;
	case Variant::TYPE_UCHAR:
		os << v.asUChar();
		break;
	case Variant::TYPE_INT16:
		os << v.asInt16();
		break;
	case Variant::TYPE_UINT16:
		os << v.asUInt16();
		break;
	case Variant::TYPE_INT32:
		os << v.asInt32();
		break;
	case Variant::TYPE_UINT32:
		os << v.asUInt32();
		break;
	case Variant::TYPE_INT64:
		os << v.asInt64();
		break;
	case Variant::TYPE_UINT64:
		os << v.asUInt64();
		break;
	case Variant::TYPE_FLOAT:
		os << v.asFloat();
		break;
	case Variant::TYPE_DOUBLE:
		os << v.asDouble();
		break;
	case Variant::TYPE_STRING:
		os << v.asString();
		break;
	default:
		break;
	}
	return os;
}



float Variant::toFloat() const
{
	if (type == TYPE_CHAR)
	{
		return static_cast<float>(data._Char);
	}
	else if (type == TYPE_UCHAR)
	{
		return static_cast<float>(data._UChar);
	}
	else if (type == TYPE_INT16)
	{
		return static_cast<float>(data._Int16);
	}
	else if (type == TYPE_UINT16)
	{
		return static_cast<float>(data._UInt16);
	}
	else if (type == TYPE_INT32)
	{
		return static_cast<float>(data._Int32);
	}
	else if (type == TYPE_UINT32)
	{
		return static_cast<float>(data._UInt32);
	}
	else if (type == TYPE_INT64)
	{
		return static_cast<float>(data._Int64);
	}
	else if (type == TYPE_UINT64)
	{
		return static_cast<float>(data._UInt64);
	}
	else if (type == TYPE_FLOAT)
	{
		return static_cast<float>(data._Float);
	}
	else if (type == TYPE_DOUBLE)
	{
		return static_cast<float>(data._Double);
	}
	else if (type == TYPE_STRING)
	{
		return static_cast<float>(std::atof(data._String->c_str()));
	}
	else if (type == TYPE_BOOL)
	{
		return data._Bool ? 1.0f : 0.0f;
	}
	else
	{
		return 0.0;
	}
}

double Variant::toDouble() const
{
	if (type == TYPE_CHAR)
	{
		return static_cast<double>(data._Char);
	}
	else if (type == TYPE_UCHAR)
	{
		return static_cast<double>(data._UChar);
	}
	else if (type == TYPE_INT16)
	{
		return static_cast<double>(data._Int16);
	}
	else if (type == TYPE_UINT16)
	{
		return static_cast<double>(data._UInt16);
	}
	else if (type == TYPE_INT32)
	{
		return static_cast<double>(data._Int32);
	}
	else if (type == TYPE_UINT32)
	{
		return static_cast<double>(data._UInt32);
	}
	else if (type == TYPE_INT64)
	{
		return static_cast<double>(data._Int64);
	}
	else if (type == TYPE_UINT64)
	{
		return static_cast<double>(data._UInt64);
	}
	else if (type == TYPE_FLOAT)
	{
		return static_cast<double>(data._Float);
	}
	else if (type == TYPE_DOUBLE)
	{
		return static_cast<double>(data._Double);
	}
	else if (type == TYPE_STRING)
	{
		return std::atof(data._String->c_str());
	}
	else if (type == TYPE_BOOL)
	{
		return data._Bool ? 1.0 : 0.0;
	}
	else
	{
		return 0.0;
	}
}


#define MEMCPYRET(VAR) \
	memcpy(buffer, &VAR, sizeof( VAR) );\
  return sizeof( VAR );

size_t Variant::copyToBuffer(void* buffer)
{
  if (type == TYPE_CHAR)
	{
		MEMCPYRET( data._Char )
	}
	else if (type == TYPE_UCHAR)
	{
		MEMCPYRET( data._UChar )
	}
	else if (type == TYPE_INT16)
	{
		MEMCPYRET(data._Int16);
	}
	else if (type == TYPE_UINT16)
	{
		MEMCPYRET(data._UInt16);
	}
	else if (type == TYPE_INT32)
	{
		MEMCPYRET(data._Int32);
	}
	else if (type == TYPE_UINT32)
	{
		MEMCPYRET(data._UInt32);
	}
	else if (type == TYPE_INT64)
	{
		MEMCPYRET(data._Int64);
	}
	else if (type == TYPE_UINT64)
	{
		MEMCPYRET(data._UInt64);
	}
	else if (type == TYPE_FLOAT)
	{
		MEMCPYRET(data._Float);
	}
	else if (type == TYPE_DOUBLE)
	{
		MEMCPYRET(data._Double);
	}
	else if (type == TYPE_STRING)
	{
		size_t len = data._String->size();
		memcpy(buffer, data._String->c_str(), len);
		return len;
	}
	else if (type == TYPE_BOOL)
	{
		MEMCPYRET(data._Bool);
	}
	else if (type == TYPE_NONE)
	{
		return 0;
	}
	throw std::runtime_error("This is serious: Type not handled in copyToBuffer()!");
};

size_t Variant::getSize() const
{
  if (type == TYPE_CHAR)
	{
		return sizeof(data._Char);
	}
	else if (type == TYPE_UCHAR)
	{
		return sizeof(data._UChar);
	}
	else if (type == TYPE_INT16)
	{
		return sizeof(data._Int16);
	}
	else if (type == TYPE_UINT16)
	{
		return sizeof(data._UInt16);
	}
	else if (type == TYPE_INT32)
	{
		return sizeof(data._Int32);
	}
	else if (type == TYPE_UINT32)
	{
		return sizeof(data._UInt32);
	}
	else if (type == TYPE_INT64)
	{
		return sizeof(data._Int64);
	}
	else if (type == TYPE_UINT64)
	{
		return sizeof(data._UInt64);
	}
	else if (type == TYPE_FLOAT)
	{
		return sizeof(data._Float);
	}
	else if (type == TYPE_DOUBLE)
	{
		return sizeof(data._Double);
	}
	else if (type == TYPE_STRING)
	{
		size_t len = strlen(data._String->c_str()+1);
		return len;
	}
	else if (type == TYPE_BOOL)
	{
		return sizeof(data._Bool);
	}
	else if (type == TYPE_NONE)
	{
		return 0;
	}
	throw std::runtime_error("This is serious: Type not handled in getSize()!");
};



} // namespace pxl
