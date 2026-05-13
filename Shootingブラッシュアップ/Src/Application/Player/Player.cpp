#include "Player.h"
#include"PlayerBullet.h"
#include "../System/Main/Scene/GameScene.h"
#include"../System/Main/Scene/SceneManager.h"
#include"../System/Utility/KeyManager.h"
#include "../Enemy/Prism/Prism.h"
#include "../Enemy/Enemy.h"
#include "../System/Battle/Turn.h"
#include "../Mouse.h"

C_Player::C_Player()
{
}

C_Player::~C_Player()
{
}

void C_Player::Draw()
{
	if (C_Turn::GetInstance().GetNowTurn() == C_Turn::Player)
	{
		if (m_CharaStatus.m_AnimStatus != Dead)
		{
			if (!m_ShotFlg)
			{
				if (PlayerSkillBase.Shot5way)
				{
					SHADER.m_spriteShader.SetMatrix(m_Line1Mat);
					SHADER.m_spriteShader.DrawTex(m_BulletLineTex, { 0,0,2560,16 }, m_LineBlinking);
					SHADER.m_spriteShader.SetMatrix(m_Line5Mat);
					SHADER.m_spriteShader.DrawTex(m_BulletLineTex, { 0,0,2560,16 }, m_LineBlinking);
				}
				if (PlayerSkillBase.Shot3way)
				{
					SHADER.m_spriteShader.SetMatrix(m_Line2Mat);
					SHADER.m_spriteShader.DrawTex(m_BulletLineTex, { 0,0,2560,16 }, m_LineBlinking);
					SHADER.m_spriteShader.SetMatrix(m_Line4Mat);
					SHADER.m_spriteShader.DrawTex(m_BulletLineTex, { 0,0,2560,16 }, m_LineBlinking);
				}
				SHADER.m_spriteShader.SetMatrix(m_Line3Mat);
				SHADER.m_spriteShader.DrawTex(m_BulletLineTex, { 0,0,2560,16 }, m_LineBlinking);
			}
		}
	}
	switch (m_CharaStatus.m_AnimStatus)
	{
	case Move:
		SHADER.m_spriteShader.SetMatrix(m_PlayerMat);
		SHADER.m_spriteShader.DrawTex(m_PlayerMoveTex, { 0,CharaHeight * (int)CharaAnimCnt,CharaWidth,CharaHeight }, 1.0f);

		break;
	case Atk:
		SHADER.m_spriteShader.SetMatrix(m_PlayerMat);
		SHADER.m_spriteShader.DrawTex(m_PlayerAtkTex, { 0,CharaHeight * (int)CharaAnimCnt,CharaWidth,CharaHeight }, 1.0f);

		break;
	case Hurt:
		SHADER.m_spriteShader.SetMatrix(m_PlayerMat);
		SHADER.m_spriteShader.DrawTex(m_PlayerHurtTex, { 0,CharaHeight * (int)CharaAnimCnt,CharaWidth,CharaHeight }, 1.0f);

		break;
	case Dead:
		SHADER.m_spriteShader.SetMatrix(m_PlayerMat);
		SHADER.m_spriteShader.DrawTex(m_PlayerDeadTex, { 0,CharaHeight * (int)CharaAnimCnt,CharaWidth,CharaHeight }, 1.0f);

		break;
	}
	int HpBerCnt;

	//HPˆ—
	SHADER.m_spriteShader.SetMatrix(m_HpBackMat);
	SHADER.m_spriteShader.DrawTex(m_HpBackTex, { 0,0,66,8 }, 1.0f);
	HpBerCnt = (m_CharaStatus.m_MaxHp - m_CharaStatus.m_BreakHp);
	if (HpBerCnt > m_CharaStatus.m_MaxHp)
	{
		HpBerCnt = m_CharaStatus.m_MaxHp;
	}
	SHADER.m_spriteShader.SetMatrix(m_HpBreakMat);
	SHADER.m_spriteShader.DrawTex(m_HpBreakTex, { 0,0,(66 - (int)(66 * (HpBerCnt / m_CharaStatus.m_MaxHp))),8 }, 1.0f);
	HpBerCnt = (m_CharaStatus.m_MaxHp - m_CharaStatus.m_Hp);
	if (HpBerCnt > m_CharaStatus.m_MaxHp)
	{
		HpBerCnt = m_CharaStatus.m_MaxHp;
	}
	SHADER.m_spriteShader.SetMatrix(m_HpMat);
	SHADER.m_spriteShader.DrawTex(m_HpTex, { 0,0,(66 - (int)(66 * (HpBerCnt / m_CharaStatus.m_MaxHp))),8 }, 1.0f);
	
	int Max = m_CharaStatus.m_MaxHp;
	SHADER.m_spriteShader.SetMatrix(m_HpMax1Mat);
	SHADER.m_spriteShader.DrawTex(m_NumTex, { NumberWidth * (Max % 10),0,64,64 }, 1.0f);
	Max = Max / 10;
	SHADER.m_spriteShader.SetMatrix(m_HpMax10Mat);
	SHADER.m_spriteShader.DrawTex(m_NumTex, { NumberWidth * (Max % 10),0,64,64 }, 1.0f);
	Max = Max / 10;
	SHADER.m_spriteShader.SetMatrix(m_HpMax100Mat);
	SHADER.m_spriteShader.DrawTex(m_NumTex, { NumberWidth * (Max % 10),0,64,64 }, 1.0f);

	SHADER.m_spriteShader.SetMatrix(m_HpBerMat);
	SHADER.m_spriteShader.DrawTex(m_HpBerTex, { 0,0,64,64 }, 1.0f);

	int NowHp = m_CharaStatus.m_Hp;
	SHADER.m_spriteShader.SetMatrix(m_NowHp1Mat);
	SHADER.m_spriteShader.DrawTex(m_NumTex, { NumberWidth * (NowHp % 10),0,64,64 }, 1.0f);
	if (m_NowHp10Flg)
	{
		NowHp = NowHp / 10;
		SHADER.m_spriteShader.SetMatrix(m_NowHp10Mat);
		SHADER.m_spriteShader.DrawTex(m_NumTex, { NumberWidth * (NowHp % 10),0,64,64 }, 1.0f);
	}
	if (m_NowHp100Flg)
	{
		NowHp = NowHp / 10;
		SHADER.m_spriteShader.SetMatrix(m_NowHp100Mat);
		SHADER.m_spriteShader.DrawTex(m_NumTex, { NumberWidth * NowHp,0,64,64 }, 1.0f);
	}

	for (int i = 0; i < m_Bullet.size(); i++)
	{
		m_Bullet[i]->Draw();
	}

	
}

void C_Player::MiniUpDraw()
{
	if (GetAsyncKeyState(VK_TAB) & 0x8000)
	{
		SHADER.m_spriteShader.SetMatrix(m_MiniUpGradeBackMat);
		SHADER.m_spriteShader.DrawTex(m_UpBackTex, { 0,0,300,720 }, 0.2f);

		SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
		SHADER.m_spriteShader.DrawString(m_UpGradePos.x, m_UpGradePos.y - m_UpAddGradePos.y * 2, "UŒ‚—Í", { 1,1,1,1 });
		SCENEMANAGER.DrawEndBegin();

		int NowAtk = m_CharaStatus.m_Atk;
		SHADER.m_spriteShader.SetMatrix(m_NowAtk1Mat);
		SHADER.m_spriteShader.DrawTex(m_NumTex, { NumberWidth * (NowAtk % 10),0,64,64 }, 1.0f);
		NowAtk = NowAtk / 10;
		SHADER.m_spriteShader.SetMatrix(m_NowAtk10Mat);
		SHADER.m_spriteShader.DrawTex(m_NumTex, { NumberWidth * (NowAtk % 10),0,64,64 }, 1.0f);
		if (m_NowAtk100Flg)
		{
			NowAtk = NowAtk / 10;
			SHADER.m_spriteShader.SetMatrix(m_NowAtk100Mat);
			SHADER.m_spriteShader.DrawTex(m_NumTex, { NumberWidth * (NowAtk % 10),0,64,64 }, 1.0f);
		}

		
		SHADER.m_spriteShader.SetMatrix(m_UpGradeBulletWallBoundMat);
		SHADER.m_spriteShader.DrawTex(m_UpGradeBulletWallBoundTex, { 0,0,32,32 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(m_Cross1Mat);
		SHADER.m_spriteShader.DrawTex(m_CrossTex, { 0,0,64,64 }, 1.0f);
		int SkillNum = PlayerSkillBase.m_WallbounceLeft;
		SHADER.m_spriteShader.SetMatrix(m_UpGrade1Num1Mat);
		SHADER.m_spriteShader.DrawTex(m_NumTex, { NumberWidth * (SkillNum % 10),0,64,64 }, 1.0f);
		SkillNum = SkillNum / 10;
		SHADER.m_spriteShader.SetMatrix(m_UpGrade1Num10Mat);
		SHADER.m_spriteShader.DrawTex(m_NumTex, { NumberWidth * (SkillNum % 10),0,64,64 }, 1.0f);

		SHADER.m_spriteShader.SetMatrix(m_UpGradeBulletEnemyBoundMat);
		SHADER.m_spriteShader.DrawTex(m_UpGradeBulletEnemyBoundTex, { 0,0,32,32 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(m_Cross2Mat);
		SHADER.m_spriteShader.DrawTex(m_CrossTex, { 0,0,64,64 }, 1.0f);
		SkillNum = PlayerSkillBase.m_BulletEnemyBoundFlg;
		SHADER.m_spriteShader.SetMatrix(m_UpGrade2Num1Mat);
		SHADER.m_spriteShader.DrawTex(m_NumTex, { NumberWidth * (SkillNum % 10),0,64,64 }, 1.0f);
		SkillNum = SkillNum / 10;
		SHADER.m_spriteShader.SetMatrix(m_UpGrade2Num10Mat);
		SHADER.m_spriteShader.DrawTex(m_NumTex, { NumberWidth * (SkillNum % 10),0,64,64 }, 1.0f);

		SHADER.m_spriteShader.SetMatrix(m_UpGradeDoubleBulletMat);
		SHADER.m_spriteShader.DrawTex(m_UpGradeDoubleBulletTex, { 0,0,32,32 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(m_Cross3Mat);
		SHADER.m_spriteShader.DrawTex(m_CrossTex, { 0,0,64,64 }, 1.0f);
		SkillNum = PlayerSkillBase.m_DoubleShot;
		SHADER.m_spriteShader.SetMatrix(m_UpGrade3Num1Mat);
		SHADER.m_spriteShader.DrawTex(m_NumTex, { NumberWidth * (SkillNum % 10),0,64,64 }, 1.0f);
		SkillNum = SkillNum / 10;
		SHADER.m_spriteShader.SetMatrix(m_UpGrade3Num10Mat);
		SHADER.m_spriteShader.DrawTex(m_NumTex, { NumberWidth * (SkillNum % 10),0,64,64 }, 1.0f);

	}
}

void C_Player::Update()
{
	switch (m_CharaStatus.m_AnimStatus)
	{
	case Move:
		CharaAnimCnt += 0.1f;
		if (CharaAnimCnt > 8.0f)
		{
			CharaAnimCnt = 0.0f;
		}
		break;
	case Atk:
		CharaAnimCnt += 0.1f;
		if (CharaAnimCnt > 9.0f)
		{
			CharaAnimCnt = 0.0f;
			m_CharaStatus.m_AtkFlg = true;
			SetAnimStatus(Move);
		}
		break;
	case Hurt:
		CharaAnimCnt += 0.1f;
		if (CharaAnimCnt > 3.0f)
		{
			CharaAnimCnt = 0.0f;
			SetAnimStatus(Move);
		}
		break;
	case Dead:
		CharaAnimCnt += 0.1f;
		if (CharaAnimCnt > 12.0f)
		{
			CharaAnimCnt = 11.0f;
			SCENEMANAGER.SetNextScene(SceneManager::SceneType::Result);
		}
		break;
	}
	if (m_CharaStatus.m_DamageFlg)
	{
		m_CharaStatus.m_BreakHp -= 1;
	}
	if (m_CharaStatus.m_Hp == m_CharaStatus.m_BreakHp)
	{
		m_CharaStatus.m_DamageFlg = false;
	}

	if (m_CharaStatus.m_Hp <= 0)
	{
		m_CharaStatus.m_Hp = 0;
		if (m_CharaStatus.m_AnimStatus != Dead)
		{
			SetAnimStatus(Dead);
		}
		m_CharaStatus.m_Alive = false;
	}
	Math::Vector2 MousePos = { (float)C_Mouse::GetInstance().GetMousePos().x,(float)C_Mouse::GetInstance().GetMousePos().y };
	Math::Vector2 vec = MousePos - m_CharaStatus.Pos;
	vec.Normalize();
	float angle = atan2(vec.y, vec.x);
	switch (C_Turn::GetInstance().GetNowTurn())
	{
	case C_Turn::Player:
		if (m_CharaStatus.m_AnimStatus != Dead)
		{
			if (!m_ShotFlg)
			{
				if (m_CanMoveFlg)
				{
					if (GetAsyncKeyState('W') & 0x8000)
					{
						m_CharaStatus.Pos.y += m_MoveSpeed;
					}
					if (GetAsyncKeyState('S') & 0x8000)
					{
						m_CharaStatus.Pos.y -= m_MoveSpeed;
					}
				}

				if (C_KeyManager::GetInstance().GetSpaceKey()||C_KeyManager::GetInstance().GetLClick())
				{
					if (m_CharaStatus.m_AnimStatus != Atk)
					{
						SetAnimStatus(Atk);
						m_ShotVec = vec;
						m_ShotAngle = angle;
						m_CanMoveFlg = false;
					}
				}
				if (m_CharaStatus.m_AtkFlg && ShotWait == 0)
				{
					if (PlayerSkillBase.Shot5way)
					{
						m_Bullet.push_back(std::make_shared<C_PlayerBullet>());
						for (auto& i : m_Bullet)
						{
							if (!i->GetAlive())
							{
								i->SetPlayerSkill(PlayerSkillBase);
								i->SetTex(&m_BulletTex);
								i->Shot(m_CharaStatus.Pos, Rotate(m_ShotVec, +m_CharaStatus.offset * 2));

								break;
							}
						}
						m_Bullet.push_back(std::make_shared<C_PlayerBullet>());
						for (auto& i : m_Bullet)
						{
							if (!i->GetAlive())
							{
								i->SetPlayerSkill(PlayerSkillBase);
								i->SetTex(&m_BulletTex);
								i->Shot(m_CharaStatus.Pos, Rotate(m_ShotVec, -m_CharaStatus.offset * 2));

								break;
							}
						}
					}
					if (PlayerSkillBase.Shot3way)
					{
						m_Bullet.push_back(std::make_shared<C_PlayerBullet>());
						for (auto& i : m_Bullet)
						{
							if (!i->GetAlive())
							{
								i->SetPlayerSkill(PlayerSkillBase);
								i->SetTex(&m_BulletTex);
								i->Shot(m_CharaStatus.Pos, Rotate(m_ShotVec, +m_CharaStatus.offset));

								break;
							}
						}
						m_Bullet.push_back(std::make_shared<C_PlayerBullet>());
						for (auto& i : m_Bullet)
						{
							if (!i->GetAlive())
							{
								i->SetPlayerSkill(PlayerSkillBase);
								i->SetTex(&m_BulletTex);
								i->Shot(m_CharaStatus.Pos, Rotate(m_ShotVec, -m_CharaStatus.offset));

								break;
							}
						}
					}
					m_Bullet.push_back(std::make_shared<C_PlayerBullet>());
					for (auto& i : m_Bullet)
					{
						if (!i->GetAlive())
						{
							i->SetPlayerSkill(PlayerSkillBase);
							i->SetTex(&m_BulletTex);
							i->Shot(m_CharaStatus.Pos, m_ShotVec);

							break;
						}
					}
					if (MultiShotCnt == PlayerSkillBase.m_DoubleShot)
					{
						m_CharaStatus.m_AtkFlg = false;
						m_ShotFlg = true;
						MultiShotCnt = 0;
						ShotWait = 0;
					}
					else
					{
						MultiShotCnt++;
						ShotWait = 20;
					}
				}

				m_LineBlinking += m_LineBlinkingAdd;
				if (m_LineBlinking >= 0.4f || m_LineBlinking <= 0.1f)
				{
					m_LineBlinkingAdd *= -1;
				}

			}
			else
			{
				m_Bullet.erase(
					std::remove_if(
						m_Bullet.begin(),
						m_Bullet.end(),
						[](const std::shared_ptr<C_PlayerBullet>& e) {
							return!(e->GetAlive());  // © GetAlive ‚ª false ‚Ì’e‚¾‚¯Á‚·
						}
					),
					m_Bullet.end()
				);
				if (m_Bullet.size() == 0)
				{
					m_ShotFlg = false;
					C_Turn::GetInstance().SetNextTurn(C_Turn::Enemy);
				}
			}
			if (m_CharaStatus.Pos.y > 360 - 32)
			{
				m_CharaStatus.Pos.y = 360 - 32;
			}
			if (m_CharaStatus.Pos.y < -360 + 32)
			{
				m_CharaStatus.Pos.y = -360 + 32;
			}
			switch (m_CharaStatus.m_AnimStatus)
			{
			case Move:
			case Hurt:
				
				if (PlayerSkillBase.Shot5way)
				{
					m_Line1Mat = Math::Matrix::CreateRotationZ(angle + m_CharaStatus.offset * 2) * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x, m_CharaStatus.Pos.y, 0);
					m_Line5Mat = Math::Matrix::CreateRotationZ(angle - m_CharaStatus.offset * 2) * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x, m_CharaStatus.Pos.y, 0);
				}
				if (PlayerSkillBase.Shot3way)
				{
					m_Line2Mat = Math::Matrix::CreateRotationZ(angle + m_CharaStatus.offset) * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x, m_CharaStatus.Pos.y, 0);
					m_Line4Mat = Math::Matrix::CreateRotationZ(angle - m_CharaStatus.offset) * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x, m_CharaStatus.Pos.y, 0);
				}
				m_Line3Mat = Math::Matrix::CreateRotationZ(angle) * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x, m_CharaStatus.Pos.y, 0);
				break;
			case Atk:
				if (PlayerSkillBase.Shot5way)
				{
					m_Line1Mat = Math::Matrix::CreateRotationZ(m_ShotAngle + m_CharaStatus.offset * 2) * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x, m_CharaStatus.Pos.y, 0);
					m_Line5Mat = Math::Matrix::CreateRotationZ(m_ShotAngle - m_CharaStatus.offset * 2) * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x, m_CharaStatus.Pos.y, 0);
				}
				if (PlayerSkillBase.Shot3way)
				{
					m_Line2Mat = Math::Matrix::CreateRotationZ(m_ShotAngle + m_CharaStatus.offset) * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x, m_CharaStatus.Pos.y, 0);
					m_Line4Mat = Math::Matrix::CreateRotationZ(m_ShotAngle - m_CharaStatus.offset) * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x, m_CharaStatus.Pos.y, 0);
				}
				m_Line3Mat = Math::Matrix::CreateRotationZ(m_ShotAngle) * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x, m_CharaStatus.Pos.y, 0);
				break;
			}
		}
		break;
		case C_Turn::UpGrade:

			for (auto& i : m_Bullet)
			{
				i->SetAlive(false);
			}
			m_Bullet.erase(
				std::remove_if(
					m_Bullet.begin(),
					m_Bullet.end(),
					[](const std::shared_ptr<C_PlayerBullet>& e) {
						return!(e->GetAlive());  // © GetAlive ‚ª false ‚Ì’e‚¾‚¯Á‚·
					}
				),
				m_Bullet.end()
			);
			m_ShotFlg = false;
			MultiShotCnt = 0;
			ShotWait = 0;
			break;
	}
	
	if (ShotWait > 0)
	{
		ShotWait--;
	}

	if (m_CharaStatus.Pos.y < -300.0f)
	{
		m_CharaStatus.HpAddPos.y = 42;
	}
	else
	{
		m_CharaStatus.HpAddPos.y = -42;
	}

	m_HpMat = Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x - ((int)(66 * (((m_CharaStatus.m_MaxHp - m_CharaStatus.m_Hp) / 2) / m_CharaStatus.m_MaxHp))), m_CharaStatus.Pos.y + m_CharaStatus.HpAddPos.y, 0);
	m_HpBackMat = Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x, m_CharaStatus.Pos.y + m_CharaStatus.HpAddPos.y, 0);
	m_HpBreakMat = Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x - ((int)(66 * (((m_CharaStatus.m_MaxHp - m_CharaStatus.m_BreakHp) / 2) / m_CharaStatus.m_MaxHp))), m_CharaStatus.Pos.y + m_CharaStatus.HpAddPos.y, 0);
	if (m_NowHp100Flg && m_NowHp10Flg)
	{
		m_NowHp100Mat =Math::Matrix::CreateScale(m_HpNumScale, m_HpNumScale,0) * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x + AddHpNumPos.x * 3, m_CharaStatus.Pos.y + m_CharaStatus.HpAddPos.y + AddHpNumPos.y, 0);
		m_NowHp10Mat = Math::Matrix::CreateScale(m_HpNumScale, m_HpNumScale, 0) * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x + AddHpNumPos.x * 2, m_CharaStatus.Pos.y + m_CharaStatus.HpAddPos.y + AddHpNumPos.y, 0);
		m_NowHp1Mat = Math::Matrix::CreateScale(m_HpNumScale, m_HpNumScale, 0) * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x + AddHpNumPos.x , m_CharaStatus.Pos.y + m_CharaStatus.HpAddPos.y + AddHpNumPos.y, 0);
	}
	else if (m_NowHp10Flg)
	{
		m_NowHp10Mat = Math::Matrix::CreateScale(m_HpNumScale, m_HpNumScale, 0) * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x + AddHpNumPos.x * 2, m_CharaStatus.Pos.y + m_CharaStatus.HpAddPos.y + AddHpNumPos.y, 0);
		m_NowHp1Mat = Math::Matrix::CreateScale(m_HpNumScale, m_HpNumScale, 0) * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x + AddHpNumPos.x , m_CharaStatus.Pos.y + m_CharaStatus.HpAddPos.y + AddHpNumPos.y, 0);
	}
	else
	{
		m_NowHp1Mat = Math::Matrix::CreateScale(m_HpNumScale, m_HpNumScale, 0) * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x + AddHpNumPos.x, m_CharaStatus.Pos.y + m_CharaStatus.HpAddPos.y + AddHpNumPos.y, 0);
	}
	m_HpMax100Mat		= Math::Matrix::CreateScale(m_HpNumScale, m_HpNumScale, 0) * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x - AddHpNumPos.x, m_CharaStatus.Pos.y + m_CharaStatus.HpAddPos.y + AddHpNumPos.y, 0);
	m_HpMax10Mat		= Math::Matrix::CreateScale(m_HpNumScale, m_HpNumScale, 0) * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x - AddHpNumPos.x * 2, m_CharaStatus.Pos.y + m_CharaStatus.HpAddPos.y + AddHpNumPos.y, 0);
	m_HpMax1Mat			= Math::Matrix::CreateScale(m_HpNumScale, m_HpNumScale, 0) * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x - AddHpNumPos.x * 3, m_CharaStatus.Pos.y + m_CharaStatus.HpAddPos.y + AddHpNumPos.y, 0);
	m_HpBerMat			= Math::Matrix::CreateScale(m_HpNumScale, m_HpNumScale, 0) * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x, m_CharaStatus.Pos.y + m_CharaStatus.HpAddPos.y + AddHpNumPos.y, 0);
	m_PlayerScaleMat	= Math::Matrix::CreateScale(2, 2, 1);
	m_PlayerMat			= m_PlayerScaleMat * Math::Matrix::CreateTranslation(m_CharaStatus.Pos.x, m_CharaStatus.Pos.y, 0);
	
	m_UpGradeBulletWallBoundMat = Math::Matrix::CreateScale(m_MiniUpScale, m_MiniUpScale, 0) * Math::Matrix::CreateTranslation(m_UpGradePos.x, m_UpGradePos.y + m_UpAddGradePos.y * 0, 0);
	m_Cross1Mat					= Math::Matrix::CreateScale(m_MiniCrossScale, m_MiniCrossScale, 0) * Math::Matrix::CreateTranslation(m_UpGradePos.x + m_UpAddGradeNumPos.x * 2, m_UpGradePos.y + (m_UpAddGradePos.y * 0) + m_UpAddGradeNumPos.y, 0);
	m_UpGrade1Num1Mat			= Math::Matrix::CreateScale(m_MiniNumScale, m_MiniNumScale, 0) * Math::Matrix::CreateTranslation(m_UpGradePos.x + m_UpAddGradeNumPos.x * 4, m_UpGradePos.y + (m_UpAddGradePos.y * 0) + m_UpAddGradeNumPos.y, 0);
	m_UpGrade1Num10Mat			= Math::Matrix::CreateScale(m_MiniNumScale, m_MiniNumScale, 0) * Math::Matrix::CreateTranslation(m_UpGradePos.x + m_UpAddGradeNumPos.x * 3, m_UpGradePos.y + (m_UpAddGradePos.y * 0) + m_UpAddGradeNumPos.y, 0);
	
	m_UpGradeBulletEnemyBoundMat = Math::Matrix::CreateScale(m_MiniUpScale, m_MiniUpScale, 0) * Math::Matrix::CreateTranslation(m_UpGradePos.x, m_UpGradePos.y + m_UpAddGradePos.y * 1, 0);
	m_Cross2Mat = Math::Matrix::CreateScale(m_MiniCrossScale, m_MiniCrossScale, 0) * Math::Matrix::CreateTranslation(m_UpGradePos.x + m_UpAddGradeNumPos.x * 2, m_UpGradePos.y + (m_UpAddGradePos.y * 1) + m_UpAddGradeNumPos.y, 0);
	m_UpGrade2Num1Mat = Math::Matrix::CreateScale(m_MiniNumScale, m_MiniNumScale, 0) * Math::Matrix::CreateTranslation(m_UpGradePos.x + m_UpAddGradeNumPos.x * 4, m_UpGradePos.y + (m_UpAddGradePos.y * 1) + m_UpAddGradeNumPos.y, 0);
	m_UpGrade2Num10Mat = Math::Matrix::CreateScale(m_MiniNumScale, m_MiniNumScale, 0) * Math::Matrix::CreateTranslation(m_UpGradePos.x + m_UpAddGradeNumPos.x * 3, m_UpGradePos.y + (m_UpAddGradePos.y * 1) + m_UpAddGradeNumPos.y, 0);


	m_UpGradeDoubleBulletMat	= Math::Matrix::CreateScale(m_MiniUpScale, m_MiniUpScale, 0)* Math::Matrix::CreateTranslation(m_UpGradePos.x, m_UpGradePos.y + m_UpAddGradePos.y * 2, 0);
	m_Cross3Mat					= Math::Matrix::CreateScale(m_MiniCrossScale, m_MiniCrossScale, 0) * Math::Matrix::CreateTranslation(m_UpGradePos.x + m_UpAddGradeNumPos.x * 2, m_UpGradePos.y + (m_UpAddGradePos.y * 2) + m_UpAddGradeNumPos.y, 0);
	m_UpGrade3Num1Mat			= Math::Matrix::CreateScale(m_MiniNumScale, m_MiniNumScale, 0) * Math::Matrix::CreateTranslation(m_UpGradePos.x + m_UpAddGradeNumPos.x * 4, m_UpGradePos.y + (m_UpAddGradePos.y * 2) + m_UpAddGradeNumPos.y, 0);
	m_UpGrade3Num10Mat			= Math::Matrix::CreateScale(m_MiniNumScale, m_MiniNumScale, 0) * Math::Matrix::CreateTranslation(m_UpGradePos.x + m_UpAddGradeNumPos.x * 3, m_UpGradePos.y + (m_UpAddGradePos.y * 2) + m_UpAddGradeNumPos.y, 0);

	
	m_MiniUpGradeBackMat = Math::Matrix::CreateTranslation(m_UpGradePos.x, 0, 0);
	
	
	m_NowAtk1Mat = Math::Matrix::CreateTranslation(m_AtkNumPos.x + AddAtkNumPos.x, m_UpGradePos.y - m_UpAddGradePos.y , 0);
	m_NowAtk10Mat = Math::Matrix::CreateTranslation(m_AtkNumPos.x, m_UpGradePos.y - m_UpAddGradePos.y, 0);
	m_NowAtk100Mat = Math::Matrix::CreateTranslation(m_AtkNumPos.x - AddAtkNumPos.x, m_UpGradePos.y - m_UpAddGradePos.y , 0);

	m_NowHp100Flg = false;
	m_NowHp10Flg = false;
	if (m_CharaStatus.m_Hp / 100 >= 1)
	{
		m_NowHp100Flg = true;
		m_NowHp10Flg = true;
	}
	else if (m_CharaStatus.m_Hp / 10 >= 1)
	{
		m_NowHp10Flg = true;
	}

	for (auto& i : m_Bullet)
	{
		i->Update();
	}
	if (C_KeyManager::GetInstance().GetJKey())
	{
		SetAnimStatus(Dead);
	}
	if (C_KeyManager::GetInstance().GetHKey())
	{
		m_CharaStatus.m_Hp = m_CharaStatus.m_MaxHp;
	}
	if (C_KeyManager::GetInstance().GetYKey())
	{
		AddBulletShot();
	}
	if (C_KeyManager::GetInstance().GetUKey())
	{
		AddWallbounce();
	}
	if (C_KeyManager::GetInstance().GetIKey())
	{
		AddEnemyBounce();
	}
	if (C_KeyManager::GetInstance().GetOKey())
	{
		SetShot3way();
	}
	if (C_KeyManager::GetInstance().GetPKey())
	{
		SetShot5way();
	}


}

void C_Player::Init()
{
	TotalScore = 0;
	m_CharaStatus.m_Alive = true;
	m_CharaStatus.m_AnimStatus = Move;
	m_CharaStatus.Pos.x = -500;
	m_CharaStatus.Pos.y = 0;
	m_ShotFlg = false;
	m_LineBlinking = 0.1f;
	m_LineBlinkingAdd = 0.01f;
	m_CharaStatus.m_Hp = 100;
	m_CharaStatus.m_MaxHp = m_CharaStatus.m_Hp;
	m_CharaStatus.m_BreakHp = m_CharaStatus.m_Hp;
	m_CharaStatus.m_Atk = 30;
	PlayerSkillBase.m_BulletEnemyBoundFlg = 1;
	PlayerSkillBase.m_WallbounceLeft = 1;
	PlayerSkillBase.m_DoubleShot = 0;
	//PlayerSkillBase.Shot3way = true;
	//PlayerSkillBase.Shot5way = true;
	ShotWait = 0;
	MultiShotCnt = 0;
	m_CanMoveFlg = true;
	CanMovePosXMin = -180;
	CanMovePosXMax = 180;
	NowMovePosX = 0;
}

void C_Player::SetTex( KdTexture* playermovetex, KdTexture* playeratktex,
	KdTexture* playerhurttex, KdTexture* playerdeadtex, KdTexture* bulletlinetex,
	KdTexture* hpbartex, KdTexture* hpbarbraektex, KdTexture* hpbarbacktex,
	KdTexture* ugwallboundtex, KdTexture* ugdoubleshottex, KdTexture* ugenemyboundtex, KdTexture* ugsplittex,
	KdTexture* hpnumtex, KdTexture* hpbarnumtex, KdTexture* upbacktex, KdTexture* crosstex)
{
	m_BulletTex.Load("Texture/Player/PlayerBullet.png");
	
	m_PlayerMoveTex = playermovetex;
	m_PlayerAtkTex = playeratktex;
	m_PlayerHurtTex = playerhurttex;
	m_PlayerDeadTex = playerdeadtex;
	m_BulletLineTex = bulletlinetex;
	m_HpTex = hpbartex;
	m_HpBreakTex = hpbarbraektex;
	m_HpBackTex = hpbarbacktex;
	m_UpGradeBulletWallBoundTex = ugwallboundtex;
	m_UpGradeDoubleBulletTex = ugdoubleshottex;
	m_UpGradeBulletEnemyBoundTex = ugenemyboundtex;
	m_UpGradeBulletSplitTex = ugsplittex;
	m_NumTex = hpnumtex;
	m_HpBerTex = hpbarnumtex;
	m_UpBackTex = upbacktex;
	m_CrossTex = crosstex;
}

Math::Vector2 C_Player::Rotate(Math::Vector2& v, float angle)
{
	float cos = cosf(angle);
	float sin = sinf(angle);
	return Math::Vector2(
		v.x * cos - v.y * sin,
		v.x * sin + v.y * cos
	);

}

void C_Player::HitBulletEnemy()
{
	std::shared_ptr<C_Enemy> Enemy = m_owner->GetEnemy();

	std::vector<std::shared_ptr<C_EnemyBase>> EnemyChara = Enemy->GetEnemyChara();


	for (auto& e : EnemyChara) {
		if (e->GetAlive())
		{
			for (int j = 0; j < m_Bullet.size(); j++)
			{
				if (m_Bullet[j]->GetAlive())
				{
					if (m_Bullet[j]->HIT(e->GetPos(), e->GetRadius()))
					{
						e->HitDamege(m_CharaStatus.m_Atk);
						if (m_Bullet[j]->GetPlayerSkill()->m_BulletEnemyBoundFlg > 0)
						{
							m_Bullet.push_back(std::make_shared<C_PlayerBullet>());
							m_Bullet[j]->GetPlayerSkill()->m_BulletEnemyBoundFlg--;
							for (auto& i : m_Bullet)
							{
								if (!i->GetAlive())
								{
									i->SetPlayerSkill(*m_Bullet[j]->GetPlayerSkill());
									i->SetTex(&m_BulletTex);
									float minDistSq = FLT_MAX;
									std::shared_ptr<C_EnemyBase> nearest = nullptr;
									for (auto& r : EnemyChara) {
										if (r->GetAlive()&&e!=r)
										{
											Math::Vector2 diff = r->GetPos() - e->GetPos();
											float distSq = diff.x * diff.x + diff.y * diff.y;

											if (distSq < minDistSq)
											{
												minDistSq = distSq;
												nearest = r;
											}
											
										}

									}
									if (nearest != nullptr)
									{
										Math::Vector2 vec = e->GetPos() - nearest->GetPos();
										i->MoreShot(e->GetPos(),vec);
									}
									break;
								}
							}
						}
						
						
					
						return;
					}
				}
			}
		}


	}
}


