#pragma once

#include <algorithm>
#include <climits>
#include <iostream>
#include <memory>
#include <vector>
#include <version>


#ifndef _STD
	#define _STD ::std::
#endif // !_STD

#ifndef _NORETURN
	#define _NORETURN [[noreturn]]
#endif // !_NORETURN

#ifndef _NODISCARD
	#define _NODISCARD [[nodiscard]]
#endif // !_NODISCARD


#if __has_include(<string>)
using _str = _STD string;
#endif


#if __has_include(<QWidget>)

	#include <qstring.h>
	#include <qvector.h>

	#ifndef _QT
		#define _QT ::Qt::
	#endif // !_QT

using _qstr = QString;

#endif // __has_include(<QWidget>)


#ifndef __myFun__

	#define _cove_type(cont, type)	   static_cast<type>(cont)
	#define _init_type(initCont, type) _cove_type(initCont, type)

	#define _def_uptr(type)		  ::std::unique_ptr<type>
	#define _init_uptr(type, ...) ::std::make_unique<type>(##__VA_ARGS__)

	#define _def_pair(type1, type2)	 ::std::pair<type1, type2>
	#define _make_pair(type1, type2) ::std::make_pair(type1, type2)

	#define _def_vec(type) ::std::vector<type>

	#if __has_include(<qvector.h>)
		#define _def_qvec ::std::vector<_qstr>
	#endif // __has_include(<qvector.h>)

#endif	   // !__myFun__
