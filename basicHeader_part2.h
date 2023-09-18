#pragma once

#include "basicHeader_part1.h"

// 定义基本数据类型
using Type = unsigned short;

// 定义基本错误代码
constexpr Type BasicErrCode = 0;

// 预定义 关键性单词
enum class KeyWord : Type
{
	sin = _init_type(101, Type),
	cos,
	tan,
	tg,

	arcsin,
	arccos,
	arctan,
	arctg,

	log, // 自定义底数
	lg,	 // 预定义底数 10
	ln,	 // 预定义底数 e

	exp,
	pow,

	abs,

	sqrt,

	solve,	// 解方程
	dsolve, // 求导函数
};

// 预定义 关键性按钮
enum class KeyButton : Type
{
	add = _init_type(201, Type), // 加
	sub,						 // 减
	mul,						 // 乘
	div,						 // 除

	fact,						 // 阶乘
	exp,						 // 求幂
	mod,						 // 求余

	lift_bk_1,					 // " ( "
	lift_bk_2,					 // “ [ ”
	lift_bk_3,					 // " { "

	right_bk_1,					 // " ) "
	right_bk_2,					 // " ] "
	right_bk_3,					 // " } "

	semicolon,					 // " ; "
};


// 关键词指认
const _def_vec(_def_pair(KeyWord, _qstr)) KeyWordIdentification = {
	_make_pair(KeyWord::sin, "sin"),	   _make_pair(KeyWord::cos, "cos"),
	_make_pair(KeyWord::tan, "tan"),	   _make_pair(KeyWord::tg, "tg"),
	_make_pair(KeyWord::arcsin, "arcsin"), _make_pair(KeyWord::arccos, " arccos"),
	_make_pair(KeyWord::arctan, "arctan"), _make_pair(KeyWord::arctg, "arctg"),
	_make_pair(KeyWord::log, "log"),	   _make_pair(KeyWord::lg, "lg"),
	_make_pair(KeyWord::ln, "ln"),		   _make_pair(KeyWord::exp, "exp"),
	_make_pair(KeyWord::pow, "pow"),	   _make_pair(KeyWord::abs, "abs"),
	_make_pair(KeyWord::sqrt, "sqrt"),	   _make_pair(KeyWord::solve, "solve"),
	_make_pair(KeyWord::dsolve, "dsolve")
};


// 关键按钮指认
const _def_vec(_def_pair(KeyButton, _qstr)) KeyButtonIdentification = {
	_make_pair(KeyButton::add, "+"),		_make_pair(KeyButton::sub, "-"),
	_make_pair(KeyButton::mul, "*"),		_make_pair(KeyButton::div, "/"),
	_make_pair(KeyButton::fact, "!"),		_make_pair(KeyButton::exp, "^"),
	_make_pair(KeyButton::mod, "%"),		_make_pair(KeyButton::lift_bk_1, "("),
	_make_pair(KeyButton::lift_bk_2, "["),	_make_pair(KeyButton::lift_bk_3, "{"),
	_make_pair(KeyButton::right_bk_1, ")"), _make_pair(KeyButton::right_bk_2, "]"),
	_make_pair(KeyButton::right_bk_3, "}"), _make_pair(KeyButton::semicolon, ";")
};


// 运算符优先级
const _def_vec(_def_pair(KeyButton, Type)) Priority = {
	_make_pair(KeyButton::add, 100), _make_pair(KeyButton::sub, 100), _make_pair(KeyButton::mul, 101),
	_make_pair(KeyButton::div, 101), _make_pair(KeyButton::mod, 101), _make_pair(KeyButton::fact, 102),
	_make_pair(KeyButton::exp, 102)
};


// 定义 单词事件 与 按钮事件
using KeyWordEvent = _STD pair<KeyWord, _qstr>;
using KeyButtonEvent = _STD pair<KeyButton, _qstr>;
