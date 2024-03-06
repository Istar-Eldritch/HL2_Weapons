class CfgPatches
{
	class VRP_HL2Weapons_Grenade
	{
		units[] = {
			"HL2_Grenade"
		};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
			{
				"DZ_Data",
				"DZ_Scripts"
			};
	};
};

class CfgMods
{
	class VRP_HL2Weapons_Grenade
	{
		type = "mod";
		author = "Istar Eldritch";
    	dependencies[] = { "World", "Mission" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"VRP/HL2Weapons/HL2_Grenade/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"VRP/HL2Weapons/HL2_Grenade/scripts/5_Mission"};
			};
		};
	};
};

class CfgVehicles
{
	class M67Grenade;
	class M18SmokeGrenade_Red;
	class M18SmokeGrenade_Green;
	class M18SmokeGrenade_Yellow;
	class M18SmokeGrenade_Purple;
	class M18SmokeGrenade_White;

	class HL2_Grenade: M67Grenade
	{
		scope=2;
		displayName="MK3A2 Grenade ";
		descriptionShort="A Combine weapon that explodes a few seconds after it is thrown.";
		hiddenSelectionsTextures[]=
		{
			"VRP\HL2Weapons\HL2_Grenade\data\grenade_co.paa"
		};
		model="\dz\weapons\explosives\smokegrenade.p3d";
		hiddenSelectionsMaterials[]=
		{
			"dz\weapons\explosives\data\smokegrenade.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=20;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\weapons\explosives\data\smokegrenade.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\explosives\data\smokegrenade.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\explosives\data\smokegrenade_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\explosives\data\smokegrenade_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\explosives\data\smokegrenade_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};

	class HL2_SmokeGrenade_Red: M18SmokeGrenade_Red
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"VRP\HL2Weapons\HL2_Grenade\data\smokered_co.paa"
		};
	};
	class HL2_SmokeGrenade_Green: M18SmokeGrenade_Green
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"VRP\HL2Weapons\HL2_Grenade\data\smokegreen_co.paa"
		};
	};
	class HL2_SmokeGrenade_Yellow: M18SmokeGrenade_Yellow
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"VRP\HL2Weapons\HL2_Grenade\data\smokeyellow_co.paa"
		};
	};
	class HL2_SmokeGrenade_Purple: M18SmokeGrenade_Purple
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"VRP\HL2Weapons\HL2_Grenade\data\smokepurple_co.paa"
		};
	};
	class HL2_SmokeGrenade_White: M18SmokeGrenade_White
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"VRP\HL2Weapons\HL2_Grenade\data\smokewhite_co.paa"
		};
	};
}

class CfgSoundShaders {

	class baseCharacter_SoundShader;
	class HL2_Grenade_Tick_SoundShader: baseCharacter_SoundShader {
		range = 20;
		samples[]=
		{
			
			{
				"VRP\HL2Weapons\HL2_Grenade\data\nade_tick",
				1
			}
		};
		volume=1;
	};
};

class CfgSoundSets {

	class baseCharacter_SoundSet;
	class HL2_Grenade_Tick_SoundSet: baseCharacter_SoundSet {
		soundShaders[]=
		{
			"HL2_Grenade_Tick_SoundShader"
		};
	};
};