#pragma once

class C_Audio
{
public:

	~C_Audio() {}


	void AddBgm(std::string FileName, std::shared_ptr<KdSoundEffect> newBgm);
	void AddSe(std::string FileName);
	std::shared_ptr<KdSoundInstance> GetInst() { return bgmInst; }

private:

	C_Audio() {}

	std::shared_ptr<KdSoundEffect>		currentBgm = NULL;
	std::shared_ptr<KdSoundInstance>	 bgmInst;

public:

	static C_Audio& GetInstans()
	{
		static C_Audio instans;
		return instans;
	}

};
