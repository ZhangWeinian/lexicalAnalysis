#include "lexicalAnalysis.h"

lexicalAnalysis::lexicalAnalysis(QWidget* parent): QWidget(parent)
{
	ui.setupUi(this);

	init();
}

lexicalAnalysis::~lexicalAnalysis(void) = default;

// 初始化
void lexicalAnalysis::init(void)
{
	info = _init_uptr(Information);
	flag = _init_uptr(Flag);
}

// 获取关键字 获取类型
KeyWord lexicalAnalysis::getKeyWord(const _qstr& Str) const
{
	auto ans = _init_type(BasicErrCode, KeyWord);

	_STD for_each(KeyWordIdentification.begin(),
				  KeyWordIdentification.end(),
				  [&Str, &ans](const auto& i)
				  {
					  if (i.second == Str)
					  {
						  ans = i.first;
					  }
				  });

	return ans;
}

// 获取关键字 获取内容
_qstr lexicalAnalysis::getKeyWord(const KeyWord WordSign) const
{
	_qstr ans = "_err";

	_STD for_each(KeyWordIdentification.begin(),
				  KeyWordIdentification.end(),
				  [WordSign, &ans](const auto& i)
				  {
					  if (i.first == WordSign)
					  {
						  ans = i.second;
					  }
				  });

	return ans;
}

// 获取关键 按钮文本 类型
KeyButton lexicalAnalysis::getKeyButton(const _qstr& Str) const
{
	auto ans = _init_type(BasicErrCode, KeyButton);

	_STD for_each(KeyButtonIdentification.begin(),
				  KeyButtonIdentification.end(),
				  [&Str](const auto& i)
				  {
					  if (i.second == Str)
					  {
						  ans = i.first;
					  }
				  });

	return ans;
}

// 获取关键 按钮文本 文本
_qstr lexicalAnalysis::getKeyButton(const KeyButton BtnSign) const
{
	_qstr ans = "_err";

	_STD for_each(KeyButtonIdentification.begin(),
				  KeyButtonIdentification.end(),
				  [BtnSign](const auto& i)
				  {
					  if (i.first == BtnSign)
					  {
						  ans = i.second;
					  }
				  });

	return ans;
}

// 类型识别 是否为 KeyWord
bool lexicalAnalysis::isKeyWord(const _qstr& Str) const
{
	return _STD any_of(KeyWordIdentification.begin(),
					   KeyWordIdentification.end(),
					   [&Str](const auto& i) { return i.second == Str; });
}

// 类型识别 是否为 KeyButton
bool lexicalAnalysis::isKeyButton(const _qstr& Str) const
{
	return _STD any_of(KeyButtonIdentification.begin(),
					   KeyButtonIdentification.end(),
					   [&Str](const auto& i) { return i.second == Str; });
}

// 文本渲染 KeyWord
_qstr lexicalAnalysis::keyWordRendering(const KeyWord WordSign) const
{
	return _qstr("重载");
}

// 文本渲染 KeyButton
_qstr lexicalAnalysis::keyWordRendering(const KeyButton ButtonSign) const
{
	return _qstr("重载");
}

// 文本渲染 _qstr
_qstr lexicalAnalysis::keyWordRendering(const _qstr& Str) const
{
	_qstr ans = "_err";

	if (isKeyButton(Str))
	{
		ans = keyWordRendering(getKeyButton(Str));
	}
	else if (isKeyWord(Str))
	{
		ans = keyWordRendering(getKeyWord(Str));
	}

	return ans;
}
