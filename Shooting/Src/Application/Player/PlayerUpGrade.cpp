#include "PlayerUpGrade.h"
#include "../System/Battle/Turn.h"
#include "../System/Main/Scene/GameScene.h"
#include "../System/Main/Scene/SceneManager.h"
#include "../System/Utility/MouseHit.h"
#include "../System/Utility/KeyManager.h"
#include "Player.h"
void C_PlayerUpGrade::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_BrackBackMat);
	SHADER.m_spriteShader.DrawTex(m_BrackBackTex, { 0,0,1280,720 }, 0.5f);
	for (int i = 0; i < UpGradeStatuNum; i++)
	{
		SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
		SHADER.m_spriteShader.DrawString(-300, 230, "é©êgÇã≠âªÇ∑ÇÈÉXÉLÉãÇëIëÇµÇƒÇ≠ÇæÇ≥Ç¢ÅB", { 1,1,1,1 });
		SCENEMANAGER.DrawEndBegin();
		SHADER.m_spriteShader.SetMatrix(m_UpGradeStatu[i].m_Mat);
		switch (m_UpGradeStatu[i].m__SkillStatus)
		{
		case BulletEnemyBound:
			SHADER.m_spriteShader.DrawTex(m_UpGradeBulletEnemyBoundTex, { 0,0,32,32 }, 1.0f);
			if (MOUSEHIT.MouseBlockHit(m_UpGradeStatu[i].m_Pos * m_Scale, m_Radius / 2 * m_Scale, m_Radius / 2 * m_Scale))
			{
				SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
				SHADER.m_spriteShader.DrawString(-210, -150, "íeÇ™ìGìØémÇ≈íµÇÀÇÈâÒêî + 1 ", { 1,1,1,1 });
			}
			break;
		case UpBulletWallBound:
			SHADER.m_spriteShader.DrawTex(m_UpGradeBulletWallBoundTex, { 0,0,32,32 }, 1.0f);
			if (MOUSEHIT.MouseBlockHit(m_UpGradeStatu[i].m_Pos * m_Scale, m_Radius / 2 * m_Scale, m_Radius / 2 * m_Scale))
			{
				SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
				SHADER.m_spriteShader.DrawString(-190, -150, "íeÇ™ï«Ç≈íµÇÀÇÈâÒêî + 1 ", { 1,1,1,1 });
			}
			break;
		case DoubleBullet:
			SHADER.m_spriteShader.DrawTex(m_UpGradeDoubleBulletTex, { 0,0,32,32 }, 1.0f);
			if (MOUSEHIT.MouseBlockHit(m_UpGradeStatu[i].m_Pos * m_Scale, m_Radius / 2 * m_Scale, m_Radius / 2 * m_Scale))
			{
				SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
				SHADER.m_spriteShader.DrawString(-230, -150, "àÍìxÇ…íeÇî≠éÀÇ∑ÇÈâÒêî + 1 ", { 1,1,1,1 });
			}
			break;
		case UpHp:
			SHADER.m_spriteShader.DrawTex(m_UpGradeHpTex, { 0,0,32,32 }, 1.0f);
			if (MOUSEHIT.MouseBlockHit(m_UpGradeStatu[i].m_Pos * m_Scale, m_Radius / 2 * m_Scale, m_Radius / 2 * m_Scale))
			{
				SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
				SHADER.m_spriteShader.DrawString(-110, -150, "ç≈ëÂëÃóÕ + 20", { 1,1,1,1 });
			}
			break;
		case HealHp:
			SHADER.m_spriteShader.DrawTex(m_HealHpTex, { 0,0,32,32 }, 1.0f);
			if (MOUSEHIT.MouseBlockHit(m_UpGradeStatu[i].m_Pos * m_Scale, m_Radius / 2 * m_Scale, m_Radius / 2 * m_Scale))
			{
				SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
				SHADER.m_spriteShader.DrawString(-110, -150, "ç≈ëÂëÃóÕÇÃîºï™âÒïúÇ∑ÇÈ", { 1,1,1,1 });
			}
			break;
		case UpAtk:
			SHADER.m_spriteShader.DrawTex(m_UpGradeAtkTex, { 0,0,32,32 }, 1.0f);
			if (MOUSEHIT.MouseBlockHit(m_UpGradeStatu[i].m_Pos * m_Scale, m_Radius / 2 * m_Scale, m_Radius / 2 * m_Scale))
			{
				SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
				SHADER.m_spriteShader.DrawString(-90, -150, "çUåÇóÕ + 10", { 1,1,1,1 });
			}
			break;
		case BulletSplit:
			SHADER.m_spriteShader.DrawTex(m_UpGradeBulletSplitTex, { 0,0,32,32 }, 1.0f);
			if (MOUSEHIT.MouseBlockHit(m_UpGradeStatu[i].m_Pos * m_Scale, m_Radius / 2 * m_Scale, m_Radius / 2 * m_Scale))
			{
				if (!C_Player::GetInstance().GetShot3way())
				{
					SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
					SHADER.m_spriteShader.DrawString(-280, -150, "àÍìxÇ…íeÇî≠éÀÇ∑ÇÈå¬êî( 1 -> 3 ) ", { 1,1,1,1 });
				}
				else
				{
					SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
					SHADER.m_spriteShader.DrawString(-280, -150, "àÍìxÇ…íeÇî≠éÀÇ∑ÇÈå¬êî( 3 -> 5 ) ", { 1,1,1,1 });
				}
			}
			break;
		case TurnAdd:
			SHADER.m_spriteShader.DrawTex(m_TurnAddTex, { 0,0,32,32 }, 1.0f);
			if (MOUSEHIT.MouseBlockHit(m_UpGradeStatu[i].m_Pos * m_Scale, m_Radius / 2 * m_Scale, m_Radius / 2 * m_Scale))
			{
				SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
				SHADER.m_spriteShader.DrawString(-310, -150, "ñÇóÕï‚ãã(É^Å[Éìí«â¡3É^Å[Éì)", { 1,1,1,1 });
			}
			break;
		}
		SCENEMANAGER.DrawEndBegin();
	}
}


bool C_PlayerUpGrade::Update()
{
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		C_Turn::GetInstance().SetNextTurn(C_Turn::Player);
		return true;
	}
	for (int i = 0; i < UpGradeStatuNum; i++)
	{
		if (MOUSEHIT.MouseBlockHit(m_UpGradeStatu[i].m_Pos * m_Scale, m_Radius/2 * m_Scale, m_Radius/2 * m_Scale))
		{
			if (C_KeyManager::GetInstance().GetSpaceKey() || C_KeyManager::GetInstance().GetLClick())
			{
				switch (m_UpGradeStatu[i].m__SkillStatus)
				{
				case BulletEnemyBound:
					C_Player::GetInstance().AddEnemyBounce();
					break;
				case UpBulletWallBound:
					C_Player::GetInstance().AddWallbounce();
					break;
				case DoubleBullet:
					C_Player::GetInstance().AddBulletShot();
					break;
				case UpHp:
					C_Player::GetInstance().HpUp();
					break;
				case HealHp:
					C_Player::GetInstance().HealHp();
					break;
				case UpAtk:
					C_Player::GetInstance().AtkUp();
					break;
				case BulletSplit:
					if (C_Player::GetInstance().GetShot3way())
					{
						C_Player::GetInstance().SetShot5way();
					}
					else
					{
						C_Player::GetInstance().SetShot3way();
					}
					break;
				case TurnAdd:
					//C_Player::GetInstance().
					break;
				}
				C_Turn::GetInstance().SetNextTurn(C_Turn::EnemyInit);
				C_Player::GetInstance().SetCanMove(true);
				return true;
			}

			m_UpGradeStatu[i].m_Mat = Math::Matrix::CreateScale(m_ScaleAdd,m_ScaleAdd,0)*
				Math::Matrix::CreateTranslation(m_UpGradeStatu[i].m_Pos.x, m_UpGradeStatu[i].m_Pos.y, 0)
				* Math::Matrix::CreateScale(m_Scale, m_Scale, 0);
		}
		else
		{
			m_UpGradeStatu[i].m_Mat = Math::Matrix::CreateTranslation(m_UpGradeStatu[i].m_Pos.x, m_UpGradeStatu[i].m_Pos.y, 0)
				* Math::Matrix::CreateScale(m_Scale, m_Scale, 0);
		}
	}
	m_BrackBackMat = Math::Matrix::CreateTranslation(0,0,0);
	return false;
}

void C_PlayerUpGrade::Init()
{

	for (int i = 0; i < UpGradeStatuNum; i++)
	{
		m_UpGradeStatu[i].m_Pos = { m_Radius * (i - 1) * 2.0f ,0};
		int Rand = 0;
		if (i==0)
		{
			Rand = rand() % 120;
			if (Rand < 20)
			{
				if (C_Player::GetInstance().GetShot5way())
				{
					Rand = rand() % 120;

					if (Rand < 20)
					{
						m_UpGradeStatu[i].m__SkillStatus = UpBulletWallBound;
					}
					else if (Rand < 40)
					{
						m_UpGradeStatu[i].m__SkillStatus = BulletEnemyBound;
					}
					else if (Rand < 60)
					{
						m_UpGradeStatu[i].m__SkillStatus = DoubleBullet;
					}
					else if (Rand < 80)
					{
						m_UpGradeStatu[i].m__SkillStatus = UpHp;
					}
					else if (Rand < 100)
					{
						m_UpGradeStatu[i].m__SkillStatus = HealHp;
					}
					else
					{
						m_UpGradeStatu[i].m__SkillStatus = UpAtk;
					}
				}
				else
				{
					m_UpGradeStatu[i].m__SkillStatus = BulletSplit;
				}
			}
			else if (Rand < 40)
			{
				m_UpGradeStatu[i].m__SkillStatus = UpBulletWallBound;
			}
			else if (Rand < 60)
			{
				m_UpGradeStatu[i].m__SkillStatus = BulletEnemyBound;
			}
			else if (Rand < 80)
			{
				m_UpGradeStatu[i].m__SkillStatus = UpHp;
			}
			else if (Rand < 100)
			{
				m_UpGradeStatu[i].m__SkillStatus = HealHp;
			}
			else
			{
				m_UpGradeStatu[i].m__SkillStatus = UpAtk;
			}
		}
		else if (i == 1)
		{
			do {
				Rand = rand() % 100;
				ShuffleOkFlg = true;
				if (Rand < 20)
				{
					if (C_Player::GetInstance().GetShot5way())
					{
						Rand = rand() % 100;

						if (Rand < 20)
						{
							m_UpGradeStatu[i].m__SkillStatus = UpBulletWallBound;
						}
						else if (Rand < 40)
						{
							m_UpGradeStatu[i].m__SkillStatus = BulletEnemyBound;
						}
						else if (Rand < 60)
						{
							m_UpGradeStatu[i].m__SkillStatus = DoubleBullet;
						}
						else if (Rand < 80)
						{
							m_UpGradeStatu[i].m__SkillStatus = UpHp;
						}
						else if (Rand < 100)
						{
							m_UpGradeStatu[i].m__SkillStatus = HealHp;
						}
						else
						{
							m_UpGradeStatu[i].m__SkillStatus = UpAtk;
						}
					}
					else
					{
						m_UpGradeStatu[i].m__SkillStatus = BulletSplit;
					}
				}
				else if (Rand < 40)
				{
					m_UpGradeStatu[i].m__SkillStatus = UpBulletWallBound;
				}
				else if (Rand < 60)
				{
					m_UpGradeStatu[i].m__SkillStatus = BulletEnemyBound;
				}
				else if (Rand < 80)
				{
					m_UpGradeStatu[i].m__SkillStatus = UpHp;
				}
				else
				{
					m_UpGradeStatu[i].m__SkillStatus = UpAtk;
				}
				if (m_UpGradeStatu[i].m__SkillStatus == m_UpGradeStatu[0].m__SkillStatus)
				{
					ShuffleOkFlg = false;
				}
			} while (!ShuffleOkFlg);
		}
		else if(m_owner->GetBattleStage()==Normal)
		{
			do {
				Rand = rand() % 100;
				ShuffleOkFlg = true;
				if (Rand < 20)
				{
					if (C_Player::GetInstance().GetShot5way())
					{
						Rand = rand() % 100;

						if (Rand < 20)
						{
							m_UpGradeStatu[i].m__SkillStatus = UpBulletWallBound;
						}
						else if (Rand < 40)
						{
							m_UpGradeStatu[i].m__SkillStatus = BulletEnemyBound;
						}
						else if (Rand < 60)
						{
							m_UpGradeStatu[i].m__SkillStatus = DoubleBullet;
						}
						else if (Rand < 80)
						{
							m_UpGradeStatu[i].m__SkillStatus = UpHp;
						}
						else
						{
							m_UpGradeStatu[i].m__SkillStatus = UpAtk;
						}
					}
					else
					{
						m_UpGradeStatu[i].m__SkillStatus = BulletSplit;
					}
				}
				else if (Rand < 40)
				{
					m_UpGradeStatu[i].m__SkillStatus = UpBulletWallBound;
				}
				else if (Rand < 60)
				{
					m_UpGradeStatu[i].m__SkillStatus = BulletEnemyBound;
				}
				else if (Rand < 80)
				{
					m_UpGradeStatu[i].m__SkillStatus = UpHp;
				}
				else
				{
					m_UpGradeStatu[i].m__SkillStatus = UpAtk;
				}
				for (int k = 0; k < UpGradeStatuNum - 1; k++)
				{

					if (m_UpGradeStatu[i].m__SkillStatus == m_UpGradeStatu[k].m__SkillStatus)
					{
						ShuffleOkFlg = false;
					}
				}
			} while (!ShuffleOkFlg);
		}
		else
		{
			m_UpGradeStatu[i].m__SkillStatus = TurnAdd;
		}
	}
}

void C_PlayerUpGrade::SetTex(KdTexture* uphptex, KdTexture* healhptex, KdTexture* upatktex, KdTexture* upbwallboundtex,
	KdTexture* updoubletex, KdTexture* enemyboundtex, KdTexture* turnaddtex,
	KdTexture* upgradebulletsplittex, KdTexture* brackback)
{
	m_UpGradeHpTex = uphptex;
	m_HealHpTex = healhptex;
	m_UpGradeAtkTex = upatktex;
	m_UpGradeBulletWallBoundTex = upbwallboundtex;
	m_UpGradeDoubleBulletTex = updoubletex;
	m_UpGradeBulletEnemyBoundTex = enemyboundtex;
	m_TurnAddTex = turnaddtex;
	m_UpGradeBulletSplitTex = upgradebulletsplittex;
	m_BrackBackTex = brackback;
}