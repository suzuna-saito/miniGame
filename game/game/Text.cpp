#include "Text.h"

Text::Text()
    : Object()
    , mText("")
{
    if (SceneBase::mIsSceneTag == SceneBase::Scene::eTitle)
    {
        mText = "これはタイトルです";
    }
    else if(SceneBase::mIsSceneTag == SceneBase::Scene::eResult)
    {
        if (SceneBase::mNowGameType == SceneBase::NowGameType::eGameClear)
        {
            mText = "ゲームクリアです";
        }
        else if (SceneBase::mNowGameType == SceneBase::NowGameType::eGameOver)
        {
            mText = "ゲームオーバーです";
        }
    }
}

Text::~Text()
{
}

void Text::Update(float _deltaTime)
{
}

void Text::Draw()
{
    DrawString(mPos.x, mPos.y, mText, GetColor(255, 255, 255));
}
