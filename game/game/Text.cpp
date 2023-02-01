#include "Text.h"

Text::Text(const char* _text)
    : Object()
    , mText(_text)
{
}

Text::~Text()
{
}

void Text::Update(float _deltaTime)
{
}

void Text::Draw()
{
    DrawString((int)mPos.x, (int)mPos.y, mText, GetColor(255, 255, 255));
}
