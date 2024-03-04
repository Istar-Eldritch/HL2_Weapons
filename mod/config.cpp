class CfgPatches
{
	class VRP_HL2Weapons
	{
		units[] = {
			"HL2_USPMatch",
			"HL2_StunBaton"
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

class cfgWeapons
{
	class Pistol_Base;
	class Mode_Safe;
	class Mode_SemiAuto;
	class OpticsInfoPistol;
	class HL2_USPPistolBase: Pistol_Base
	{
		scope=0;
		weight=750;
		absorbency=0;
		repairableWithKits[]={1};
		repairCosts[]={25};
		PPDOFProperties[]={1,0.89999998,10,250,4,10};
		WeaponLength=0.20999999;
		ShoulderDistance=0.40000001;
		barrelArmor=1.523;
		initSpeedMultiplier=1.1;
		chamberSize=1;
		chamberedRound="";
		magazines[]=
		{
			"HL2_Mag_USP"
		};
		chamberableFrom[]=
		{
			"Ammo_9x19"
		};
		magazineSwitchTime=0.23999999;
		ejectType=1;
		recoilModifier[]={1,1,1};
		swayModifier[]={1.3,1.3,0.80000001};
		hiddenSelections[]=
		{
		};
		class NoiseShoot
		{
			strength=50;
			type="shot";
		};
		modes[]=
		{
			"SemiAuto"
		};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[]=
			{
				"Colt1911_Shot_SoundSet",
				"Colt1911_Tail_SoundSet",
				"Colt1911_InteriorTail_SoundSet"
			};
			soundSetShotExt[]=
			{
			};
			reloadTime=0.13;
			recoil="recoil_1911";
			recoilProne="recoil_1911_prone";
			dispersion=0.0044999998;
			magazineSlot="magazine";
		};
		class OpticsInfo: OpticsInfoPistol
		{
			memoryPointCamera="eye";
			discreteDistance[]={25};
			discreteDistanceInitIndex=0;
			modelOptics="-";
			distanceZoomMin=100;
			distanceZoomMax=100;
		};
		class Particles
		{
			class OnFire
			{
				class SmokeCloud
				{
					overrideParticle="weapon_shot_winded_smoke";
				};
				class MuzzleFlash
				{
					overrideParticle="weapon_shot_fnx_01";
					ignoreIfSuppressed=1;
					illuminateWorld=1;
					positionOffset[]={0,0,0};
				};
			};
			class OnOverheating
			{
				maxOverheatingValue=8;
				shotsToStartOverheating=8;
				overheatingDecayInterval=1;
				class SmokingBarrel1
				{
					overrideParticle="smoking_barrel_small";
					onlyWithinOverheatLimits[]={0,1};
					positionOffset[]={0,0,0};
					onlyWithinRainLimits[]={0,1};
				};
				class OpenChamberSmoke
				{
					onlyIfBoltIsOpen=1;
					overrideParticle="smoking_barrel_small";
					overridePoint="nabojnicestart";
				};
			};
			class OnBulletCasingEject
			{
				class ChamberSmokeRaise
				{
					overrideParticle="weapon_shot_chamber_smoke";
					overridePoint="nabojnicestart";
				};
			};
		};
		weaponStateAnim="dz\anims\anm\player\reloads\1911\w_1911_states.anm";
	};
	class HL2_USPMatch: HL2_USPPistolBase
	{
		scope=2;
		displayName="USP Match";
		descriptionShort="The USP Match appears to be the Combine's standard sidearm, and is often carried by Civil Protection officers.";
		hiddenSelections[]=
		{
		};
		model="\VRP\HL2Weapons\data\usp_match\model.p3d";
		attachments[]=
		{
		};
		itemSize[]={3,2};
		hiddenSelectionsTextures[]=
		{
			"\VRP\HL2Weapons\data\usp_match\usp_match_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"\VRP\HL2Weapons\data\usp_match\usp_match.rvmat"
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
								"\VRP\HL2Weapons\data\usp_match\usp_match.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"\VRP\HL2Weapons\data\usp_match\usp_match.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"\VRP\HL2Weapons\data\usp_match\usp_match_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"\VRP\HL2Weapons\data\usp_match\usp_match_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"\VRP\HL2Weapons\data\usp_match\usp_match_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
};

class CfgMagazines
{
	class Ammunition_Base;
	class Magazine_Base;
	class HL2_Mag_USP: Magazine_Base
	{
		scope=2;
		displayName="USP 15 round magazine";
		desriptionShort="15 round magazine compatible with USP pistols";
		model="\VRP\HL2Weapons\data\usp_match\mag_model.p3d";
		weight=130;
		weightPerQuantityUnit=8;
		mass=10;
		itemSize[]={1,2};
		count=15;
		ammo="Bullet_9x19";
		ammoItems[]=
		{
			"Ammo_9x19"
		};
		tracersEvery=0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\weapons\attachments\data\p38_mag.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\attachments\data\p38_mag.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\attachments\data\p38_mag_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\attachments\data\p38_mag_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\attachments\data\p38_mag_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SosundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet="MagRifle_fill_in_SoundSet";
					id=1;
				};
				class MagRifle_fill_loop
				{
					soundSet="MagRifle_fill_loop_SoundSet";
					id=2;
				};
				class MagRifle_fill_out
				{
					soundSet="MagRifle_fill_out_SoundSet";
					id=3;
				};
				class MagRifle_empty_in
				{
					soundSet="MagRifle_empty_in_SoundSet";
					id=4;
				};
				class MagRifle_empty_loop
				{
					soundSet="MagRifle_empty_loop_SoundSet";
					id=5;
				};
				class MagRifle_empty_out
				{
					soundSet="MagRifle_empty_out_SoundSet";
					id=6;
				};
				class MagPistol_fill_in
				{
					soundSet="MagPistol_fill_in_SoundSet";
					id=7;
				};
				class MagPistol_fill_loop
				{
					soundSet="MagPistol_fill_loop_SoundSet";
					id=8;
				};
				class MagPistol_fill_out
				{
					soundSet="MagPistol_fill_out_SoundSet";
					id=9;
				};
				class MagPistol_empty_in
				{
					soundSet="MagPistol_empty_in_SoundSet";
					id=10;
				};
				class MagPistol_empty_loop
				{
					soundSet="MagPistol_empty_loop_SoundSet";
					id=11;
				};
				class MagPistol_empty_out
				{
					soundSet="MagPistol_empty_out_SoundSet";
					id=12;
				};
			};
		};
	}
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxy_HL2_USPMatch: ProxyAttachment
	{
		scope=2;
		inventorySlot="pistol";
		model="\VRP\HL2Weapons\data\usp_match\model.p3d";
	};
	class Proxy_HL2_Mag_USP
	{
		scope=2;
		inventorySlot="magazine";
		model="\VRP\HL2Weapons\data\usp_match\mag_model.p3d"
	}
};