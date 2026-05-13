#include "EnemyBase.h"
#include "EnemyBullet.h"
#include "../System/Battle/Turn.h"
#include "../Player/Player.h"
#include "Enemy.h"
#include "../System/Main/Scene/GameScene.h"

void C_EnemyBase::Draw()
{
	if (m_EnemyStatus.m_DeadFlg)return;
	SHADER.m_spriteShader.SetMatrix(m_EnemyMat);
	switch (m_EnemyStatus.m_EAnimStatus)
	{
		case EStart:
			SHADER.m_spriteShader.DrawTex(m_EnemyDeadTex, { m_EnemyStatus.m_DeadTexWidthMax - CharaWidth * (int)CharaAnimCnt,0,CharaWidth,CharaHeight }, 1.0f);
			break;
		case EIdle:
			SHADER.m_spriteShader.DrawTex(m_EnemyIdleTex, { CharaWidth * (int)CharaAnimCnt,0,CharaWidth,CharaHeight }, 1.0f);
			break;
		case EAtk:
			SHADER.m_spriteShader.DrawTex(m_EnemyAtkTex, { CharaWidth * (int)CharaAnimCnt,0,CharaWidth,CharaHeight }, 1.0f);
			break;
		case EHurt:
			SHADER.m_spriteShader.DrawTex(m_EnemyHurtTex, { CharaWidth * (int)CharaAnimCnt,0,CharaWidth,CharaHeight }, 1.0f);
			break;
		case EDead:
			SHADER.m_spriteShader.DrawTex(m_EnemyDeadTex, { CharaWidth * (int)CharaAnimCnt,0,CharaWidth,CharaHeight }, 1.0f);
			break;
	}
	
	if (C_Turn::GetInstance().GetNowTurn() != C_Turn::EnemyInit)
	{

		int HpBerCnt;

		//HPèàóù
		SHADER.m_spriteShader.SetMatrix(m_HpBackMat);
		SHADER.m_spriteShader.DrawTex(m_HpBackTex, { 0,0,66,8 }, 1.0f);
		HpBerCnt = (m_EnemyStatus.m_MaxHp - m_EnemyStatus.m_BreakHp);
		if (HpBerCnt > m_EnemyStatus.m_MaxHp)
		{
			HpBerCnt = m_EnemyStatus.m_MaxHp;
		}
		SHADER.m_spriteShader.SetMatrix(m_HpBreakMat);
		SHADER.m_spriteShader.DrawTex(m_HpBreakTex, { 0,0,(66 - (int)(66 * (HpBerCnt / m_EnemyStatus.m_MaxHp))),8 }, 1.0f);
		HpBerCnt = (m_EnemyStatus.m_MaxHp - m_EnemyStatus.m_Hp);
		if (HpBerCnt > m_EnemyStatus.m_MaxHp)
		{
			HpBerCnt = m_EnemyStatus.m_MaxHp;
		}
		SHADER.m_spriteShader.SetMatrix(m_HpMat);
		SHADER.m_spriteShader.DrawTex(m_HpTex, { 0,0,(66 - (int)(66 * (HpBerCnt / m_EnemyStatus.m_MaxHp))),8 }, 1.0f);

		int Max = m_EnemyStatus.m_MaxHp;
		SHADER.m_spriteShader.SetMatrix(m_HpMax1Mat);
		SHADER.m_spriteShader.DrawTex(m_HpNumTex, { NumberWidth * (Max % 10),0,64,64 }, 1.0f);
		Max = Max / 10;
		SHADER.m_spriteShader.SetMatrix(m_HpMax10Mat);
		SHADER.m_spriteShader.DrawTex(m_HpNumTex, { NumberWidth * (Max % 10),0,64,64 }, 1.0f);
		if (m_MaxHp100Flg)
		{
			Max = Max / 10;
			SHADER.m_spriteShader.SetMatrix(m_HpMax100Mat);
			SHADER.m_spriteShader.DrawTex(m_HpNumTex, { NumberWidth * (Max % 10),0,64,64 }, 1.0f);
		}
		SHADER.m_spriteShader.SetMatrix(m_HpBerMat);
		SHADER.m_spriteShader.DrawTex(m_HpBerTex, { 0,0,64,64 }, 1.0f);

		int Now = m_EnemyStatus.m_Hp;
		SHADER.m_spriteShader.SetMatrix(m_NowHp1Mat);
		SHADER.m_spriteShader.DrawTex(m_HpNumTex, { NumberWidth * (Now % 10),0,64,64 }, 1.0f);
		if (m_NowHp10Flg)
		{
			Now = Now / 10;
			SHADER.m_spriteShader.SetMatrix(m_NowHp10Mat);
			SHADER.m_spriteShader.DrawTex(m_HpNumTex, { NumberWidth * (Now % 10),0,64,64 }, 1.0f);
		}
		if (m_NowHp100Flg)
		{
			Now = Now / 10;
			SHADER.m_spriteShader.SetMatrix(m_NowHp100Mat);
			SHADER.m_spriteShader.DrawTex(m_HpNumTex, { NumberWidth * Now,0,64,64 }, 1.0f);
		}


		switch (m_EnemyStatus.m_MoveCmd)
		{
		case Attack:
			SHADER.m_spriteShader.SetMatrix(m_IconMat);
			SHADER.m_spriteShader.DrawTex(m_AttackIconTex, { 0,0,32,32 }, 1.0f);
			if (m_AtkExpFlg)
			{
				SHADER.m_spriteShader.SetMatrix(m_AtkExpMat);
				SHADER.m_spriteShader.DrawTex(m_AtkExpTex, { 128 * (int)m_AtkExpAnimCnt,0,128,128 }, 1.0f);
			}
			break;
		case Beam5:
			if (!m_EnemyStatus.m_ShotFlg)
			{
				SHADER.m_spriteShader.SetMatrix(m_Line1Mat);
				SHADER.m_spriteShader.DrawTex(m_BulletLineTex, { 0,0,2560,16 }, m_LineBlinking);
				SHADER.m_spriteShader.SetMatrix(m_Line5Mat);
				SHADER.m_spriteShader.DrawTex(m_BulletLineTex, { 0,0,2560,16 }, m_LineBlinking);
			}
		case Beam3:
			if (!m_EnemyStatus.m_ShotFlg)
			{
				SHADER.m_spriteShader.SetMatrix(m_Line2Mat);
				SHADER.m_spriteShader.DrawTex(m_BulletLineTex, { 0,0,2560,16 }, m_LineBlinking);
				SHADER.m_spriteShader.SetMatrix(m_Line4Mat);
				SHADER.m_spriteShader.DrawTex(m_BulletLineTex, { 0,0,2560,16 }, m_LineBlinking);
			}
		case Beam:
			SHADER.m_spriteShader.SetMatrix(m_IconMat);
			SHADER.m_spriteShader.DrawTex(m_BeamIconTex, { 0,0,32,32 }, 1.0f);
			if (!m_EnemyStatus.m_ShotFlg)
			{
				SHADER.m_spriteShader.SetMatrix(m_Line3Mat);
				SHADER.m_spriteShader.DrawTex(m_BulletLineTex, { 0,0,2560,16 }, m_LineBlinking);
			}
			break;
		}

		if (m_EnemyStatus.AttackDamage / 100 != 0)
		{
			int i = m_EnemyStatus.AttackDamage;
			SHADER.m_spriteShader.SetMatrix(m_IconNumber1Mat);
			SHADER.m_spriteShader.DrawTex(m_NumberTex, { 64 * (i % 10),0,64,64 }, 1.0f);
			i /= 10;
			SHADER.m_spriteShader.SetMatrix(m_IconNumber10Mat);
			SHADER.m_spriteShader.DrawTex(m_NumberTex, { 64 * (i % 10),0,64,64 }, 1.0f);
			i /= 10;
			SHADER.m_spriteShader.SetMatrix(m_IconNumber100Mat);
			SHADER.m_spriteShader.DrawTex(m_NumberTex, { 64 * i,0,64,64 }, 1.0f);
		}
		else if (m_EnemyStatus.AttackDamage / 10 != 0)
		{
			int i = m_EnemyStatus.AttackDamage;
			SHADER.m_spriteShader.SetMatrix(m_IconNumber1Mat);
			SHADER.m_spriteShader.DrawTex(m_NumberTex, { 64 * (i % 10),0,64,64 }, 1.0f);
			i /= 10;
			SHADER.m_spriteShader.SetMatrix(m_IconNumber10Mat);
			SHADER.m_spriteShader.DrawTex(m_NumberTex, { 64 * (i % 10),0,64,64 }, 1.0f);
		}
		else
		{
			SHADER.m_spriteShader.SetMatrix(m_IconNumber1Mat);
			SHADER.m_spriteShader.DrawTex(m_NumberTex, { 64 * m_EnemyStatus.AttackDamage,0,64,64 }, 1.0f);
		}

		for (auto& i : m_EnemyBullet)
		{
			i->Draw();
		}
	}
}

void C_EnemyBase::ShotBeam()
{
	m_EnemyBullet.push_back(std::make_shared<C_EnemyBullet>());
	m_BulletTotal++;
	m_EnemyStatus.m_ShotFlg = true;
	m_Vec.Length();
	for (auto& i : m_EnemyBullet)
	{
		if (!i->GetAlive())
		{
			i->SetTex(m_BulletTex);
			i->Shot(m_EnemyStatus.m_Pos,m_Vec);
			break;
		}
	}
}

void C_EnemyBase::ShootWay(int a_way)
{
	Math::Vector2 forward(cosf(0), sinf(0));
	m_BulletTotal++;
	m_EnemyStatus.m_ShotFlg = true;
	switch (a_way)
	{
	case 5:
		// ç∂
		m_EnemyBullet.push_back(std::make_shared<C_EnemyBullet>());
		for (auto& i : m_EnemyBullet)
		{
			if (!i->GetAlive())
			{
				i->SetTex(m_BulletTex);
				i->Shot(m_EnemyStatus.m_Pos, Rotate(forward, -m_EnemyStatus.offset*2));
				break;
			}
		}
		// âE
		m_EnemyBullet.push_back(std::make_shared<C_EnemyBullet>());
		for (auto& i : m_EnemyBullet)
		{
			if (!i->GetAlive())
			{
				i->SetTex(m_BulletTex);
				i->Shot(m_EnemyStatus.m_Pos, Rotate(forward, +m_EnemyStatus.offset*2 ));
				break;
			}
		}
	case 3:
		// ç∂
		m_EnemyBullet.push_back(std::make_shared<C_EnemyBullet>());
		for (auto& i : m_EnemyBullet)
		{
			if (!i->GetAlive())
			{
				i->SetTex(m_BulletTex);
				i->Shot(m_EnemyStatus.m_Pos, Rotate(forward, -m_EnemyStatus.offset));
				break;
			}
		}
		// âE
		m_EnemyBullet.push_back(std::make_shared<C_EnemyBullet>());
		for (auto& i : m_EnemyBullet)
		{
			if (!i->GetAlive())
			{
				i->SetTex(m_BulletTex);
				i->Shot(m_EnemyStatus.m_Pos, Rotate(forward, +m_EnemyStatus.offset));
				break;
			}
		}
	case 1:
		// íÜ
		m_EnemyBullet.push_back(std::make_shared<C_EnemyBullet>());
		for (auto& i : m_EnemyBullet)
		{
			if (!i->GetAlive())
			{
				i->SetTex(m_BulletTex);
				i->Shot(m_EnemyStatus.m_Pos, forward);
				break;
			}
		}
	default:
		break;
	}
	
	
	
}

Math::Vector2 C_EnemyBase::Rotate(Math::Vector2& v, float angle)
{
		float cos = cosf(angle);
		float sin = sinf(angle);
		return Math::Vector2(
			v.x * cos - v.y * sin,
			v.x * sin + v.y * cos
		);
	
}

void C_EnemyBase::BulletHitPlayer()
{
	if (C_Player::GetInstance().GetAlive())
	{
		for (auto& i : m_EnemyBullet)
		{
			if (i->GetAlive())
			{
				if (i->HIT(C_Player::GetInstance().GetPos(), C_Player::GetInstance().GetWidth(), C_Player::GetInstance().GetHegiht()))
				{
					C_Player::GetInstance().HitDamege(m_EnemyStatus.AttackDamage);
					i->SetAlive(false);
				}
			}
		}
	}
}

void C_EnemyBase::PreInit()
{
	m_LineBlinking = 0.1f;
	m_LineBlinkingAdd = 0.01f;
	m_AtkExpAnimCnt = 0.0f;
}

void C_EnemyBase::Update()
{
	if (m_EnemyStatus.m_DeadFlg)return;

	switch (m_EnemyStatus.m_EAnimStatus)
	{
	case EStart:
		CharaAnimCnt += 0.1f;
		if (CharaAnimCnt > 7.0f)
		{
			CharaAnimCnt = 0.0f;
			SetEAnimStatus(EIdle);
			m_owner->TotalInitAnimEndInc();
		}
		break;
	case EIdle:
		CharaAnimCnt += 0.1f;
		if (CharaAnimCnt > 4.0f)
		{
			CharaAnimCnt = 0.0f;
		}
		break;
	case EAtk:
		CharaAnimCnt += 0.1f;
		if (CharaAnimCnt > 8.0f)
		{
			CharaAnimCnt = 0.0f;
			if (m_EnemyStatus.m_MoveCmd == Attack)
			{
				m_AtkExpFlg = true;
				SetEAnimStatus(EIdle);
				
			}
			else
			{
				m_EnemyStatus.AtkFlg = true;
			}
		}
		break;
	case EHurt:
		CharaAnimCnt += 0.1f;
		if (CharaAnimCnt > 4.0f)
		{
			CharaAnimCnt = 0.0f;
			SetEAnimStatus(EIdle);
		}
		break;
	case EDead:
		CharaAnimCnt += 0.1f;
		if (CharaAnimCnt > 7.0f)
		{
			CharaAnimCnt = 0.0f;
			m_EnemyStatus.m_DeadFlg = true;
			C_Player::GetInstance().TotalScorePlus();
		}
		break;

	}

	if (m_EnemyStatus.m_DamageFlg)
	{
		m_EnemyStatus.m_BreakHp -= 1;
	}
	if (m_EnemyStatus.m_Hp == m_EnemyStatus.m_BreakHp)
	{
		m_EnemyStatus.m_DamageFlg = false;
	}
	if (m_AtkExpFlg)
	{
		m_AtkExpAnimCnt += 0.5f;
		if (m_AtkExpAnimCnt > 11.0f)
		{
			m_AtkExpFlg = false;
			m_EnemyStatus.AtkFlg = true;
		}
	}
	

	if (C_Turn::GetInstance().GetNowTurn() == C_Turn::Enemy && !m_EnemyStatus.m_ShotFlg)
	{
		if (m_EnemyStatus.m_EAnimStatus == EIdle)
		{
			SetEAnimStatus(EAtk);
		}
		if (m_EnemyStatus.AtkFlg)
		{
			Move();
			SetEAnimStatus(EIdle);
			
		}
	}
	Math::Vector2 vec(cosf(0), sinf(0));
	float angle = atan2(vec.y, vec.x);
	switch (m_EnemyStatus.m_MoveCmd)
	{
	case Attack:
		m_AtkExpMat = Math::Matrix::CreateTranslation(C_Player::GetInstance().GetPos().x, C_Player::GetInstance().GetPos().y, 0);
		break;
	case Beam5:
		m_Line1Mat = Math::Matrix::CreateRotationZ(angle + m_EnemyStatus.offset * 2) * Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x, m_EnemyStatus.m_Pos.y, 0);
		m_Line5Mat = Math::Matrix::CreateRotationZ(angle - m_EnemyStatus.offset * 2) * Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x, m_EnemyStatus.m_Pos.y, 0);
	case Beam3:
		m_Line2Mat = Math::Matrix::CreateRotationZ(angle + m_EnemyStatus.offset) * Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x, m_EnemyStatus.m_Pos.y, 0);
		m_Line4Mat = Math::Matrix::CreateRotationZ(angle - m_EnemyStatus.offset) * Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x, m_EnemyStatus.m_Pos.y, 0);
		m_LineBlinking += m_LineBlinkingAdd;
		if (m_LineBlinking >= 0.4f || m_LineBlinking <= 0.1f)
		{
			m_LineBlinkingAdd *= -1;
		}
		m_Line3Mat = Math::Matrix::CreateRotationZ(angle) * Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x, m_EnemyStatus.m_Pos.y, 0);

		break;
	case Beam:
		float angle = atan2(m_Vec.y, m_Vec.x);
		m_LineBlinking += m_LineBlinkingAdd;
		if (m_LineBlinking >= 0.4f || m_LineBlinking <= 0.1f)
		{
			m_LineBlinkingAdd *= -1;
		}
		m_Line3Mat = Math::Matrix::CreateRotationZ(angle) * Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x, m_EnemyStatus.m_Pos.y, 0);
		break;
	}

	if (m_EnemyStatus.m_ShotFlg&& m_EnemyStatus.AtkFlg)
	{
		for (auto& i : m_EnemyBullet)
		{
			i->Update();
			
		}
		BulletHitPlayer();
		m_EnemyBullet.erase(
			std::remove_if(
				m_EnemyBullet.begin(),
				m_EnemyBullet.end(),
				[](const std::shared_ptr<C_EnemyBullet>& e) {
					return!(e->GetAlive());  // Å© GetAlive Ç™ false ÇÃíeÇæÇØè¡Ç∑
				}
			),
			m_EnemyBullet.end()
		);
		if (m_EnemyBullet.size() == 0)
		{
			m_EnemyStatus.m_MoveFlg = true;
			m_EnemyStatus.AtkFlg = false;
		}
	}
	m_NowHp100Flg = false;
	m_NowHp10Flg = false;
	if (m_EnemyStatus.m_Hp / 100 >= 1)
	{
		m_NowHp100Flg = true;
		m_NowHp10Flg = true;
	}
	else if (m_EnemyStatus.m_Hp / 10 >= 1)
	{
		m_NowHp10Flg = true;
	}

	m_HpMat = Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x - ((int)(66 * (((m_EnemyStatus.m_MaxHp - m_EnemyStatus.m_Hp) / 2) / m_EnemyStatus.m_MaxHp))), m_EnemyStatus.m_Pos.y + m_EnemyStatus.m_HpAddPos.y, 0);
	m_HpBackMat = Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x, m_EnemyStatus.m_Pos.y + m_EnemyStatus.m_HpAddPos.y, 0);
	m_HpBreakMat = Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x - ((int)(66 * (((m_EnemyStatus.m_MaxHp - m_EnemyStatus.m_BreakHp) / 2) / m_EnemyStatus.m_MaxHp))), m_EnemyStatus.m_Pos.y + m_EnemyStatus.m_HpAddPos.y, 0);
	m_IconMat = Math::Matrix::CreateScale(m_IconScale, m_IconScale, 0) * Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x+m_EnemyStatus.m_IconAddPos.x, m_EnemyStatus.m_Pos.y + m_EnemyStatus.m_IconAddPos.y, 0);
	if (m_NowHp100Flg && m_NowHp10Flg)
	{
		m_NowHp100Mat = Math::Matrix::CreateScale(m_HpNumScale, m_HpNumScale, 0) * Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x + AddHpNumPos.x * 3, m_EnemyStatus.m_Pos.y + m_EnemyStatus.m_HpAddPos.y + AddHpNumPos.y, 0);
		m_NowHp10Mat = Math::Matrix::CreateScale(m_HpNumScale, m_HpNumScale, 0) * Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x + AddHpNumPos.x * 2, m_EnemyStatus.m_Pos.y + m_EnemyStatus.m_HpAddPos.y + AddHpNumPos.y, 0);
		m_NowHp1Mat = Math::Matrix::CreateScale(m_HpNumScale, m_HpNumScale, 0) * Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x + AddHpNumPos.x, m_EnemyStatus.m_Pos.y + m_EnemyStatus.m_HpAddPos.y + AddHpNumPos.y, 0);
	}
	else if (m_NowHp10Flg)
	{
		m_NowHp10Mat = Math::Matrix::CreateScale(m_HpNumScale, m_HpNumScale, 0) * Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x + AddHpNumPos.x * 2, m_EnemyStatus.m_Pos.y + m_EnemyStatus.m_HpAddPos.y + AddHpNumPos.y, 0);
		m_NowHp1Mat = Math::Matrix::CreateScale(m_HpNumScale, m_HpNumScale, 0) * Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x + AddHpNumPos.x, m_EnemyStatus.m_Pos.y + m_EnemyStatus.m_HpAddPos.y + AddHpNumPos.y, 0);
	}
	else
	{
		m_NowHp1Mat = Math::Matrix::CreateScale(m_HpNumScale, m_HpNumScale, 0) * Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x + AddHpNumPos.x, m_EnemyStatus.m_Pos.y + m_EnemyStatus.m_HpAddPos.y + AddHpNumPos.y, 0);
	}
	m_HpMax100Mat = Math::Matrix::CreateScale(m_HpNumScale, m_HpNumScale, 0) * Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x - AddHpNumPos.x, m_EnemyStatus.m_Pos.y + m_EnemyStatus.m_HpAddPos.y + AddHpNumPos.y, 0);
	m_HpMax10Mat = Math::Matrix::CreateScale(m_HpNumScale, m_HpNumScale, 0) * Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x - AddHpNumPos.x * 2, m_EnemyStatus.m_Pos.y + m_EnemyStatus.m_HpAddPos.y + AddHpNumPos.y, 0);
	m_HpMax1Mat = Math::Matrix::CreateScale(m_HpNumScale, m_HpNumScale, 0) * Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x - AddHpNumPos.x * 3, m_EnemyStatus.m_Pos.y + m_EnemyStatus.m_HpAddPos.y + AddHpNumPos.y, 0);
	m_HpBerMat = Math::Matrix::CreateScale(m_HpNumScale, m_HpNumScale, 0) * Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x, m_EnemyStatus.m_Pos.y + m_EnemyStatus.m_HpAddPos.y + AddHpNumPos.y, 0);


	m_IconScaleMat = Math::Matrix::CreateScale(0.2f, 0.2f, 1);
	m_IconTransMat = Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x + m_EnemyStatus.m_IconAddPos.x + m_EnemyStatus.m_IconNumberAddPos.x * 3, m_EnemyStatus.m_Pos.y + m_EnemyStatus.m_IconAddPos.y + m_EnemyStatus.m_IconNumberAddPos.y, 0);
	m_IconNumber1Mat = m_IconScaleMat * m_IconTransMat;
	m_IconTransMat = Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x + m_EnemyStatus.m_IconAddPos.x + m_EnemyStatus.m_IconNumberAddPos.x * 2, m_EnemyStatus.m_Pos.y + m_EnemyStatus.m_IconAddPos.y + m_EnemyStatus.m_IconNumberAddPos.y, 0);
	m_IconNumber10Mat = m_IconScaleMat * m_IconTransMat;
	m_IconTransMat = Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x + m_EnemyStatus.m_IconAddPos.x + m_EnemyStatus.m_IconNumberAddPos.x * 1, m_EnemyStatus.m_Pos.y + m_EnemyStatus.m_IconAddPos.y + m_EnemyStatus.m_IconNumberAddPos.y, 0);
	m_IconNumber100Mat = m_IconScaleMat * m_IconTransMat;

	m_EnemyMat = Math::Matrix::CreateTranslation(m_EnemyStatus.m_Pos.x, m_EnemyStatus.m_Pos.y, 0);




}

void C_EnemyBase::SetAlive() {
	m_EnemyStatus.m_Alive = false;
	m_owner->TotalEnemyMainer();
		
}

void C_EnemyBase::SetTex(KdTexture* enemyidletex, KdTexture* enemyatktex, KdTexture* enemyhurttex, KdTexture* enemydeadtex,
	KdTexture* hpbartex, KdTexture* hpbarbraektex, KdTexture* hpbarbacktex
	, KdTexture* attacktex, KdTexture* beamtex, KdTexture* numbertex, KdTexture* bulletlinetex
	, KdTexture* bullettex, KdTexture* atkexptex, KdTexture* hpbertex)
{
	m_EnemyIdleTex = enemyidletex;
	m_EnemyAtkTex = enemyatktex;
	m_EnemyHurtTex = enemyhurttex;
	m_EnemyDeadTex = enemydeadtex;
	m_HpTex = hpbartex;
	m_HpBreakTex = hpbarbraektex;
	m_HpBackTex = hpbarbacktex;
	m_AttackIconTex = attacktex;
	m_BeamIconTex = beamtex;
	m_NumberTex = numbertex;
	m_BulletTex = bullettex;
	m_BulletLineTex = bulletlinetex;
	m_AtkExpTex = atkexptex;
	m_HpBerTex = hpbertex;
	m_HpNumTex = numbertex;
}