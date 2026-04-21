#include"SceneManager.h"

C_SceneManager::~C_SceneManager()
{
}

void C_SceneManager::ChangeState(C_State* newState)
{
	delete currentState;
	
	currentState = newState;
	currentState->Init();
}

void C_SceneManager::OptionState(C_State* newState, bool Flg)
{
	optionState = newState;
	TitleFlg = Flg;
	optionState->Init();
	OptionFlg = true;
}

void C_SceneManager::OptionClose()
{
	OptionFlg = false;
	TitleFlg = false;
	delete optionState;
	optionState = nullptr;
}

void C_SceneManager::ChangeFade(C_State* newState)
{
	NextState = newState;

	NowFade = FadeType::Fade_out;
	FadeAlpha = 0.0f;

}

void C_SceneManager::UpdateFade()
{
	if (NowFade == Fade_out)
	{
		FadeAlpha += 0.05f;

		if (FadeAlpha >= 1.0f)
		{

			FadeAlpha += 1.0f;
			ChangeState(NextState);

			NextState = nullptr;
			NowFade = FadeType::Fade_in;
		}

	}
	else if (NowFade == Fade_in)
	{
		FadeAlpha -= 0.05f;

		if (FadeAlpha <= 0.0f)
		{
			FadeAlpha = 0.0f;
			NowFade = FadeType::Fade_no;
		}
	}
}

void C_SceneManager::Init()
{
	currentState->Init();
	if (OptionFlg)
	{
		optionState->Init();
	}
}

void C_SceneManager::Update()
{
	if (!OptionFlg)
	{
		currentState->Update();
	}
	if (OptionFlg)
	{
		optionState->Update();

		if (optionState != nullptr)
		{
			C_OptionScene* opt = static_cast<C_OptionScene*>(optionState);
			
		}

	}
	UpdateFade();

	m_mat = Math::Matrix::CreateTranslation(0, 0, 0);

}

void C_SceneManager::Draw()
{
	currentState->Draw();
	if (OptionFlg)
	{
		optionState->Draw();

		if (optionState != nullptr)
		{
			//ダウンキャスト(親クラスを子クラスに変換する)
			C_OptionScene* opt = static_cast<C_OptionScene*>(optionState);
			
		}
	}

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(&BrackTex, Math::Rectangle{ 0,0,1280,720 }, FadeAlpha);

}
