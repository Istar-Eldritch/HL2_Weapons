class CfgPatches
{
	class HL_SBAS12_Sounds
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Weapons_Firearms"
		};
	};
};
class CfgSoundShaders
{
	class base_closeShot_SoundShader;
	class base_midShot_SoundShader;
	class base_distShot_SoundShader;
	class base_HomeSilenced_closeShot_SoundShader;
	class base_HomeSilenced_midShot_SoundShader;
	class HLSBAS12_closeShot_SoundShader: base_closeShot_SoundShader
	{
		samples[] = {{"HL2_Weapons\HL2_Spas_12\sounds\Sbas",1}};
		volume=1;
	};
	class HLSBAS12_midShot_SoundShader: base_midShot_SoundShader
	{
		samples[] = {{"HL2_Weapons\HL2_Spas_12\sounds\Sbas",1}};
		volume = 0.5;
	};
	class HLSBAS12_distShot_SoundShader: base_distShot_SoundShader
	{
		samples[] = {{"HL2_Weapons\HL2_Spas_12\sounds\Sbas",1}};
		volume = 0.35;
	};
};

class CfgSoundSets
{
	class Rifle_Shot_Base_SoundSet;	
	class Rifle_silencerHomemade_Base_SoundSet;
	class HL_SBAS12_Shot_SoundSet: Rifle_Shot_Base_SoundSet
	{
		soundShaders[] = {"HLSBAS12_closeShot_SoundShader","HLSBAS12_midShot_SoundShader","HLSBAS12_distShot_SoundShader"};
	};
};