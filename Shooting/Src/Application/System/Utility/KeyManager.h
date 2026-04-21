#pragma once

class C_KeyManager
{

public:

	bool GetEscKey()
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			if (!EscKeyFlg)
			{
				EscKeyFlg = true;
				return true;
			}
		}
		else
		{
			EscKeyFlg = false;
		}
		return false;
	}

	bool GetUpKey()
	{
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			if (!UpKeyFlg)
			{
				UpKeyFlg = true;
				return true;
			}
		}
		else
		{
			UpKeyFlg = false;
		}
		return false;
	}

	bool GetDownKey()
	{
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			if (!DownKeyFlg)
			{
				DownKeyFlg = true;
				return true;
			}
		}
		else
		{
			DownKeyFlg = false;
		}
		return false;
	}

	bool GetLeftKey()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			if (!LeftKeyFlg)
			{
				LeftKeyFlg = true;
				return true;
			}
		}
		else
		{
			LeftKeyFlg = false;
		}
		return false;
	}

	bool GetRightKey()
	{
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			if (!RightKeyFlg)
			{
				RightKeyFlg = true;
				return true;
			}
		}
		else
		{
			RightKeyFlg = false;
		}
		return false;
	}

	bool GetLClick()
	{
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			if (!LClickFlg)
			{
				LClickFlg = true;
				return true;
			}
		}
		else
		{
			LClickFlg = false;
		}
		return false;
	}

	//長押し用
	bool GetLDown()
	{
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			return true;
		}
		else
		{
			return	false;
		}
	}

	bool GetRClick()
	{
		if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
		{
			if (!RClickFlg)
			{
				RClickFlg = true;
				return true;
			}
		}
		else
		{
			RClickFlg = false;
		}
		return false;
	}

private:

	C_KeyManager() 
	{
		EscKeyFlg = false;
		LClickFlg = false;
		RClickFlg = false;
	}

	//キーごとに必要

	bool EscKeyFlg;
	bool UpKeyFlg;
	bool DownKeyFlg;
	bool LeftKeyFlg;
	bool RightKeyFlg;
	bool LClickFlg;
	bool RClickFlg;

public:

	static C_KeyManager& GetInstance()
	{
		static C_KeyManager instance;
		return instance;
	}

};

#define KEYMANAGER C_KeyManager::GetInstance()