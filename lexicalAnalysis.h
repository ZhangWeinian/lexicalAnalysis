#pragma once

#include <QtWidgets/QWidget>

/* ui */
#include "ui_lexicalAnalysis.h"

/* debug information */
#include <qdebug.h>

/* use myself function */
#include "basicInformation.h"

class lexicalAnalysis: public QWidget
{
	Q_OBJECT

public:

	lexicalAnalysis(QWidget* parent = nullptr);
	~lexicalAnalysis(void);

private:

	/* data */

	Ui::lexicalAnalysisClass ui;

	_def_uptr(Information) info; // 存储基础信息
	_def_uptr(Flag) flag;		 // 存储标识符信息

	/* fun */
	_NORETURN void init(void); // 初始化

	// 获取关键字
	_NODISCARD KeyWord getKeyWord(const _qstr& Str) const;
	_NODISCARD _qstr getKeyWord(const KeyWord WordSign) const;

	// 获取关键 按钮文本
	_NODISCARD KeyButton getKeyButton(const _qstr& Str) const;
	_NODISCARD _qstr getKeyButton(const KeyButton BtnSign) const;

	// 类型识别：KeyWord 还是 KeyButton
	_NODISCARD bool isKeyWord(const _qstr& Str) const;
	_NODISCARD bool isKeyButton(const _qstr& Str) const;

	// 关键字渲染
	_NODISCARD _qstr keyWordRendering(const KeyWord WordSign) const;
	_NODISCARD _qstr keyWordRendering(const KeyButton ButtonSign) const;
	_NODISCARD _qstr keyWordRendering(const _qstr& Str) const;
};
