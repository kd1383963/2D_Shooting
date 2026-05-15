#include "Audio.h"
void C_Audio::AddBgm(std::string FileName, std::shared_ptr<KdSoundEffect> newBgm)
{
	newBgm = std::make_shared<KdSoundEffect>();

	newBgm->Load(FileName);

	/*if (currentBgm != NULL)
	{
		delete& currentBgm;
	}*/
	currentBgm = newBgm;

	if (bgmInst != NULL)
	{
		bgmInst->Stop();
	}
	bgmInst = currentBgm->CreateInstance(false);

	bgmInst->SetVolume(0.01f);
	bgmInst->Play(true);

}

void C_Audio::AddSe(std::string FileName)
{
	std::shared_ptr<KdSoundEffect> SE = std::make_shared<KdSoundEffect>();

	SE->Load(FileName);

	std::shared_ptr<KdSoundInstance>SEInst = SE->CreateInstance(false);

	SEInst->SetVolume(0.05f);
	if (!SEInst->IsPlay())
	{
		SEInst->Play(false);
	}
}
