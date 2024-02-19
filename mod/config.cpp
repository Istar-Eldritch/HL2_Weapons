class CfgPatches
{
	class VRP_Weapons_StunBaton
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
	class VRP_Weapons_StunBaton
	{
		type = "mod";
		author = "Istar Eldritch";
    	dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"VRP/weapons/StunBaton/scripts/4_World"};
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
		model="\VRP\weapons\StunBaton\data\stunbaton.p3d";
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
								"RVP\weapons\StunBaton\data\stunbaton.rvmap"
							}
						},
						
						{
							0.69999999,
							
							{
								"RVP\weapons\StunBaton\data\stunbaton.rvmap"
							}
						},
						
						{
							0.5,
							
							{
								"RVP\weapons\StunBaton\data\stunbaton_damage.rvmap"
							}
						},
						
						{
							0.30000001,
							
							{
								"RVP\weapons\StunBaton\data\stunbaton_damage.rvmap"
							}
						},
						
						{
							0,
							
							{
								"RVP\weapons\StunBaton\data\stunbaton_destruct.rvmap"
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
}