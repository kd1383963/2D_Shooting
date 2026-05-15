#include "PlayerUpGrade.h"
#include "../System/Battle/Turn.h"
#include "../System/Main/Scene/GameScene.h"
#include "../System/Main/Scene/SceneManager.h"
#include "../System/Utility/MouseHit.h"
#include "../System/Utility/KeyManager.h"
#include "Player.h"
#include "../System/Audio.h"
void C_PlayerUpGrade::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_BrackBackMat);
	SHADER.m_spriteShader.DrawTex(m_BrackBackTex, { 0,0,1280,720 }, 0.5f);
	for (int i = 0; i < UpGradeStatuNum; i++)
	{
		SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
		SHADER.m_spriteShader.DrawString(-300, 280, "自身を強化するスキルを選択してください。", { 1,1,1,1 });
		SCENEMANAGER.DrawEndBegin();
		SHADER.m_spriteShader.SetMatrix(m_UpGradeStatu[i].m_Mat);
		switch (m_UpGradeStatu[i].m__SkillStatus)
		{
		case UpBulletEnemyBound:
			SHADER.m_spriteShader.DrawTex(m_UpGradeBulletEnemyBoundTex, { 0,0,32,32 }, 1.0f);
			SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
			SHADER.m_spriteShader.DrawString(m_UpGradeStatu[i].m_Pos.x * m_Scale + m_UpGradeStatu[i].m_TextAddPos.x * strlen(m_UpGradeStatu[i].UpGradeText),
				m_UpGradeStatu[i].m_Pos.y + m_UpGradeStatu[i].m_TextAddPos.y,
				m_UpGradeStatu[i].UpGradeText, { 1,1,1,1 });
			break;
		case UpBulletWallBound:
			SHADER.m_spriteShader.DrawTex(m_UpGradeBulletWallBoundTex, { 0,0,32,32 }, 1.0f);
			SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
			SHADER.m_spriteShader.DrawString(m_UpGradeStatu[i].m_Pos.x * m_Scale + m_UpGradeStatu[i].m_TextAddPos.x * strlen(m_UpGradeStatu[i].UpGradeText),
				m_UpGradeStatu[i].m_Pos.y + m_UpGradeStatu[i].m_TextAddPos.y,
				m_UpGradeStatu[i].UpGradeText, { 1,1,1,1 });
			break;
		case UpDoubleBullet:
			SHADER.m_spriteShader.DrawTex(m_UpGradeDoubleBulletTex, { 0,0,32,32 }, 1.0f);
			SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
			SHADER.m_spriteShader.DrawString(m_UpGradeStatu[i].m_Pos.x * m_Scale + m_UpGradeStatu[i].m_TextAddPos.x * strlen(m_UpGradeStatu[i].UpGradeText),
				m_UpGradeStatu[i].m_Pos.y + m_UpGradeStatu[i].m_TextAddPos.y,
				m_UpGradeStatu[i].UpGradeText, { 1,1,1,1 });
			break;
		case UpHp:
			SHADER.m_spriteShader.DrawTex(m_UpGradeHpTex, { 0,0,32,32 }, 1.0f);
			SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
			SHADER.m_spriteShader.DrawString(m_UpGradeStatu[i].m_Pos.x * m_Scale + m_UpGradeStatu[i].m_TextAddPos.x * strlen(m_UpGradeStatu[i].UpGradeText),
				m_UpGradeStatu[i].m_Pos.y + m_UpGradeStatu[i].m_TextAddPos.y,
				m_UpGradeStatu[i].UpGradeText, { 1,1,1,1 });
			break;
		case HealHp:
			SHADER.m_spriteShader.DrawTex(m_HealHpTex, { 0,0,32,32 }, 1.0f);
			SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
			SHADER.m_spriteShader.DrawString(m_UpGradeStatu[i].m_Pos.x * m_Scale + m_UpGradeStatu[i].m_TextAddPos.x * strlen(m_UpGradeStatu[i].UpGradeText),
				m_UpGradeStatu[i].m_Pos.y + m_UpGradeStatu[i].m_TextAddPos.y,
				m_UpGradeStatu[i].UpGradeText, { 1,1,1,1 });
			break;
		case UpAtk:
			SHADER.m_spriteShader.DrawTex(m_UpGradeAtkTex, { 0,0,32,32 }, 1.0f);
			SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
			SHADER.m_spriteShader.DrawString(m_UpGradeStatu[i].m_Pos.x * m_Scale + m_UpGradeStatu[i].m_TextAddPos.x * strlen(m_UpGradeStatu[i].UpGradeText),
				m_UpGradeStatu[i].m_Pos.y + m_UpGradeStatu[i].m_TextAddPos.y,
				m_UpGradeStatu[i].UpGradeText, { 1,1,1,1 });
			break;
		case UpBulletSplit:
			SHADER.m_spriteShader.DrawTex(m_UpGradeBulletSplitTex, { 0,0,32,32 }, 1.0f);
			if (!C_Player::GetInstance().GetShot3way())
			{
				SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
				SHADER.m_spriteShader.DrawString(m_UpGradeStatu[i].m_Pos.x * m_Scale + m_UpGradeStatu[i].m_TextAddPos.x * strlen(m_UpGradeStatu[i].UpGradeText),
					m_UpGradeStatu[i].m_Pos.y + m_UpGradeStatu[i].m_TextAddPos.y,
					m_UpGradeStatu[i].UpGradeText, { 1,1,1,1 });
			}
			else
			{
				SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
				SHADER.m_spriteShader.DrawString(m_UpGradeStatu[i].m_Pos.x * m_Scale + m_UpGradeStatu[i].m_TextAddPos.x * strlen(m_UpGradeStatu[i].UpGradeText),
					m_UpGradeStatu[i].m_Pos.y + m_UpGradeStatu[i].m_TextAddPos.y, 
					m_UpGradeStatu[i].UpGradeText, { 1,1,1,1 });
			}
			break;
		case TurnAdd:
			SHADER.m_spriteShader.DrawTex(m_TurnAddTex, { 0,0,32,32 }, 1.0f);
			SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
			SHADER.m_spriteShader.DrawString(m_UpGradeStatu[i].m_Pos.x * m_Scale + m_UpGradeStatu[i].m_TextAddPos.x * strlen(m_UpGradeStatu[i].UpGradeText),
				m_UpGradeStatu[i].m_Pos.y * m_Scale + m_UpGradeStatu[i].m_TextAddPos.y,
				m_UpGradeStatu[i].UpGradeText, { 1,1,1,1 });
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
			if (!m_UpGradeStatu[i].m_CursorHitSe)
			{
				m_UpGradeStatu[i].m_CursorHitSe = true;
				C_Audio::GetInstans().AddSe("Asset/Sound/CursorHit.wav");
			}
			if (C_KeyManager::GetInstance().GetSpaceKey() || C_KeyManager::GetInstance().GetLClick())
			{
				C_Audio::GetInstans().AddSe("Asset/Sound/Select.wav");
				switch (m_UpGradeStatu[i].m__SkillStatus)
				{
				case UpBulletEnemyBound:
					C_Player::GetInstance().AddEnemyBounce();
					break;
				case UpBulletWallBound:
					C_Player::GetInstance().AddWallbounce();
					break;
				case UpDoubleBullet:
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
				case UpBulletSplit:
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

			m_UpGradeStatu[i].m_CursorHitSe = false;

			

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
		m_UpGradeStatu[i].m_CursorHitSe = false;
		int Rand = 0;
		if (i==0)
		{
			m_UpGradeStatu[i].m_Pos = { m_Radius * (i - 1) * m_MultiAddPos ,-m_Radius/2 };
			Rand = rand() % 120;
			if (Rand < 10)
			{
				if (C_Player::GetInstance().GetShot5way())
				{
					Rand = rand() % 120;

					if (Rand < 10)
					{
						m_UpGradeStatu[i].m__SkillStatus = UpBulletWallBound;
					}
					else if (Rand < 20)
					{
						m_UpGradeStatu[i].m__SkillStatus = UpBulletEnemyBound;
					}
					else if (Rand < 30)
					{
						m_UpGradeStatu[i].m__SkillStatus = UpAtk;
					}
					else if (Rand < 40)
					{
						m_UpGradeStatu[i].m__SkillStatus = HealHp;
					}
					else if (Rand < 50)
					{
						m_UpGradeStatu[i].m__SkillStatus = UpHp;
					}
					else
					{
						m_UpGradeStatu[i].m__SkillStatus = UpDoubleBullet;
					}
				}
				else
				{
					m_UpGradeStatu[i].m__SkillStatus = UpBulletSplit;
				}
			}
			else if (Rand < 20)
			{
				m_UpGradeStatu[i].m__SkillStatus = UpBulletWallBound;
			}
			else if (Rand < 30)
			{
				m_UpGradeStatu[i].m__SkillStatus = UpBulletEnemyBound;
			}
			else if (Rand < 40)
			{
				m_UpGradeStatu[i].m__SkillStatus = UpAtk;
			}
			else if (Rand < 80)
			{
				m_UpGradeStatu[i].m__SkillStatus = HealHp;
			}
			else
			{
				m_UpGradeStatu[i].m__SkillStatus = UpHp;
			}
		}
		else if (i == 1)
		{
			m_UpGradeStatu[i].m_TextAddPos.y = 150;
			m_UpGradeStatu[i].m_Pos = { m_Radius * (i - 1) * m_MultiAddPos ,0 };
			do {
				Rand = rand() % 120;
				ShuffleOkFlg = true;
				if (Rand < 10)
				{
					if (C_Player::GetInstance().GetShot5way())
					{
						Rand = rand() % 100;

						if (Rand < 10)
						{
							m_UpGradeStatu[i].m__SkillStatus = UpBulletWallBound;
						}
						else if (Rand < 20)
						{
							m_UpGradeStatu[i].m__SkillStatus = UpBulletEnemyBound;
						}
						else if (Rand < 30)
						{
							m_UpGradeStatu[i].m__SkillStatus = UpAtk;
						}
						else if (Rand < 40)
						{
							m_UpGradeStatu[i].m__SkillStatus = HealHp;
						}
						else if (Rand < 50)
						{
							m_UpGradeStatu[i].m__SkillStatus = UpHp;
						}
						else
						{
							m_UpGradeStatu[i].m__SkillStatus = UpDoubleBullet;
						}
					}
					else
					{
						m_UpGradeStatu[i].m__SkillStatus = UpBulletSplit;
					}
				}
				else if (Rand < 20)
				{
					m_UpGradeStatu[i].m__SkillStatus = UpBulletWallBound;
				}
				else if (Rand < 30)
				{
					m_UpGradeStatu[i].m__SkillStatus = HealHp;
				}
				else if (Rand < 40)
				{
					m_UpGradeStatu[i].m__SkillStatus = UpHp;
				}
				else if (Rand < 80)
				{
					m_UpGradeStatu[i].m__SkillStatus = UpBulletEnemyBound;
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
			m_UpGradeStatu[i].m_Pos = { m_Radius * (i - 1) * m_MultiAddPos ,-m_Radius/2 };
			do {
				Rand = rand() % 120;
				ShuffleOkFlg = true;
				if (Rand < 10)
				{
					if (C_Player::GetInstance().GetShot5way())
					{
						Rand = rand() % 100;

						if (Rand < 10)
						{
							m_UpGradeStatu[i].m__SkillStatus = UpBulletWallBound;
						}
						else if (Rand < 20)
						{
							m_UpGradeStatu[i].m__SkillStatus = UpBulletEnemyBound;
						}
						else if (Rand < 30)
						{
							m_UpGradeStatu[i].m__SkillStatus = UpAtk;
						}
						else if (Rand < 40)
						{
							m_UpGradeStatu[i].m__SkillStatus = HealHp;
						}
						else if (Rand < 50)
						{
							m_UpGradeStatu[i].m__SkillStatus = UpHp;
						}
						else
						{
							m_UpGradeStatu[i].m__SkillStatus = UpDoubleBullet;
						}
					}
					else
					{
						m_UpGradeStatu[i].m__SkillStatus = UpBulletSplit;
					}
				}
				else if (Rand < 30)
				{
					m_UpGradeStatu[i].m__SkillStatus = UpBulletEnemyBound;
				}
				else if (Rand < 50)
				{
					m_UpGradeStatu[i].m__SkillStatus = HealHp;
				}
				else if (Rand < 70)
				{
					m_UpGradeStatu[i].m__SkillStatus = UpHp;
				}
				else if (Rand < 90)
				{
					m_UpGradeStatu[i].m__SkillStatus = UpAtk;
				}
				else
				{
					m_UpGradeStatu[i].m__SkillStatus = UpBulletWallBound;
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
			m_UpGradeStatu[i].m_Pos = { m_Radius * (i - 1) * m_MultiAddPos ,-m_Radius/2 };
			m_UpGradeStatu[i].m__SkillStatus = TurnAdd;
		}
		

		switch (m_UpGradeStatu[i].m__SkillStatus)
		{
			case UpBulletEnemyBound:
				sprintf_s(m_UpGradeStatu[i].UpGradeText, sizeof(m_UpGradeStatu[i].UpGradeText), "弾が敵で跳ねる回数 + 1");
				break;
			case UpBulletWallBound:
				sprintf_s(m_UpGradeStatu[i].UpGradeText, sizeof(m_UpGradeStatu[i].UpGradeText), "弾が壁で跳ねる回数 + 1");
				break;
			case UpBulletSplit:
				if (!C_Player::GetInstance().GetShot3way())
				{
					sprintf_s(m_UpGradeStatu[i].UpGradeText, sizeof(m_UpGradeStatu[i].UpGradeText), "一度に弾を発射する個数( 1 -> 3 )");
				}
				else
				{
					sprintf_s(m_UpGradeStatu[i].UpGradeText, sizeof(m_UpGradeStatu[i].UpGradeText), "一度に弾を発射する個数( 3 -> 5 )");
				}
				break;
			case UpDoubleBullet:
				sprintf_s(m_UpGradeStatu[i].UpGradeText, sizeof(m_UpGradeStatu[i].UpGradeText), "一度に弾を発射する回数 + 1");
				break;
			case UpAtk:
				sprintf_s(m_UpGradeStatu[i].UpGradeText, sizeof(m_UpGradeStatu[i].UpGradeText), "攻撃力 + 10 ");
				break;
			case UpHp:
				sprintf_s(m_UpGradeStatu[i].UpGradeText, sizeof(m_UpGradeStatu[i].UpGradeText), "最大体力 + 50 ");
				break;
			case HealHp:
				sprintf_s(m_UpGradeStatu[i].UpGradeText, sizeof(m_UpGradeStatu[i].UpGradeText), "最大体力の半分回復する");
				break;
			case TurnAdd:
				sprintf_s(m_UpGradeStatu[i].UpGradeText, sizeof(m_UpGradeStatu[i].UpGradeText), "魔力補給(ターン追加3ターン)");
				break;
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