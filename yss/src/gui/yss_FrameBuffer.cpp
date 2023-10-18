////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>

#if USE_GUI && YSS_L_HEAP_USE

#include <std_ext/malloc.h>
#include <gui/FrameBuffer.h>
#include <gui/painter.h>

FrameBuffer::FrameBuffer(void)
{
	mSize.height = 0;
	mSize.width = 0;
	mFrameBuffer = 0;
	mAlpha = 0xff;
}

FrameBuffer::~FrameBuffer(void)
{
	if (mFrameBuffer)
		lfree(mFrameBuffer);
}


error FrameBuffer::setSize(Size_t size)
{
	return setSize(size.width, size.height);
}

error FrameBuffer::setSize(uint16_t width, uint16_t height)
{
	if(mFrameBuffer)
		lfree(mFrameBuffer);
	
	mSize.width = width;
	mSize.height = height;
	
	mFrameBuffer = (uint8_t*)lmalloc(width * height * getDotSize());

	return error::ERROR_NONE;
}

void *FrameBuffer::getFrameBuffer(void)
{
	return mFrameBuffer;
}

void FrameBuffer::clear(void)
{
//	Painter::fill(*this, mBgColor);	
}

/*
Size_t FrameBuffer::getSize(void)
{
	return mSize;
}

uint8_t FrameBuffer::getDotSize(void)
{
	return 0;
}

uint8_t FrameBuffer::getColorMode(void)
{
	return 0;
}

uint8_t FrameBuffer::getAlpha(void)
{
	return mAlpha;
}

void FrameBuffer::setAlpha(uint8_t alpha)
{
	mAlpha = alpha;
}

Font* FrameBuffer::getFont(void)
{
	return &mFont;
}

uint8_t FrameBuffer::getType(void)
{
	return COLOR_TYPE_UNDEFINED;
}
*/
#endif
