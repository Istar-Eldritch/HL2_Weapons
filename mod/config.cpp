class CfgPatches
{
	class VRP_HL2Weapons
	{
		units[] = {};
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
	class VRP_HL2Weapons
	{
		type = "mod";
		author = "Istar Eldritch";
    	dependencies[] = { "World", "Mission" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"VRP/HL2Weapons/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"VRP/HL2Weapons/scripts/5_Mission"};
			};
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class Powered_Base;
	class HL2_StunBaton: Powered_Base
	{
		scope=2;
		displayName="Stun Baton";
		descriptionShort="Is an electrified baton used by Civil Protection officers to enforce the law on unruly citizens";
		model="\VRP\HL2Weapons\data\stunbaton.p3d";
		debug_ItemCategory=2;
		rotationFlags=12;
		repairableWithKits[]={};
		repairCosts[]={20};
		weight=800;
		absorbency=0.5;
		itemSize[]={1,4};
		fragility=0.001;
		itemBehaviour=1;
		openItemSpillRange[]={20,50};
		inventorySlot[]=
		{
			"Melee"
		};
		isMeleeWeapon=1;
		attachments[]=
		{
			"BatteryD"
		};
		class EnergyManager
		{
			hasIcon=1;
			autoSwitchOff=1;
			energyUsagePerSecond=0.1;
			plugType=1;
			attachmentAction=1;
			wetnessExposure=0.1;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"VRP\HL2Weapons\data\stunbaton.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"VRP\HL2Weapons\data\stunbaton.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"VRP\HL2Weapons\data\stunbaton_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"VRP\HL2Weapons\data\stunbaton_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"VRP\HL2Weapons\data\stunbaton_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeBluntLight_2";
				range=1.5;
			};
			class Heavy
			{
				ammo="MeleeBluntHeavy_2";
				range=1.8;
			};
			class Sprint
			{
				ammo="MeleeBluntHeavy_2";
				range=2.5;
			};
		};
		soundImpactType="metal";
		class AnimEvents
		{
			class SoundWeapon
			{
				class drop
				{
					soundset="crowbar_drop_SoundSet";
					id=898;
				};
			};
		};
	};
};

class CfgSoundShaders {

	class baseCharacter_SoundShader;
	class HL2_StunBaton_Hit_SoundShader: baseCharacter_SoundShader {
		range = 20;
		samples[]=
		{
			
			{
				"VRP\HL2Weapons\data\stunbaton_hit",
				1
			}
		};
		volume=1;
	};

	class HL2_StunBaton_On_SoundShader: baseCharacter_SoundShader {
		range = 10;
		samples[]=
		{
			
			{
				"VRP\HL2Weapons\data\stunbaton_on",
				1
			}
		};
		volume=0.5;
	};

	class HL2_StunBaton_Swing_SoundShader: baseCharacter_SoundShader {
		range = 10;
		samples[]=
		{
			
			{
				"VRP\HL2Weapons\data\stunbaton_swing",
				1
			}
		};
		volume=0.5;
	};
};

class CfgSoundSets {

	class baseCharacter_SoundSet;
	class HL2_StunBaton_Hit_SoundSet: baseCharacter_SoundSet {
		soundShaders[]=
		{
			"HL2_StunBaton_Hit_SoundShader"
		};
	};

	class HL2_StunBaton_On_SoundSet: baseCharacter_SoundSet {
		soundShaders[]=
		{
			"HL2_StunBaton_On_SoundShader"
		};
	};

	class HL2_StunBaton_Swing_SoundSet: baseCharacter_SoundSet {
		soundShaders[]=
		{
			"HL2_StunBaton_Swing_SoundShader"
		};
	};
};
