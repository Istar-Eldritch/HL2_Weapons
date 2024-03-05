class CfgPatches
{
	class VRP_HL2Weapons_USPMatch
	{
		units[] = {
			"HL2_USPMatch",
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
	class VRP_HL2Weapons_USPMatch
	{
		type = "mod";
		author = "Istar Eldritch";
    	dependencies[] = { "World", "Mission" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"VRP/HL2Weapons/HL2_USPMatch/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"VRP/HL2Weapons/HL2_USPMatch/scripts/5_Mission"};
			};
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
			recoil="recoil_fnx";
			recoilProne="recoil_fnx_prone";
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
					overridePoint="Nabojnicestart";
				};
			};
			class OnBulletCasingEject
			{
				class ChamberSmokeRaise
				{
					overrideParticle="weapon_shot_chamber_smoke";
					overridePoint="Nabojnicestart";
				};
			};
		};
		weaponStateAnim="dz\anims\anm\player\reloads\FNP45\w_fnp45_states.anm";
		boneRemap[]=
		{
			"bolt",
			"Weapon_Bolt",
			"magazine",
			"Weapon_Magazine",
			"bullet",
			"Weapon_Bullet",
			"trigger",
			"Weapon_Trigger",
			"hammer",
			"Weapon_Bone_01"
		};
	};
	class HL2_USPMatch: HL2_USPPistolBase
	{
		scope=2;
		displayName="USP Match";
		descriptionShort="The USP Match appears to be the Combine's standard sidearm, and is often carried by Civil Protection officers.";
		hiddenSelections[]=
		{
		};
		model="\VRP\HL2Weapons\HL2_USPMatch\data\pistol\usp_match.p3d";
		attachments[]=
		{
		};
		itemSize[]={3,2};
		hiddenSelectionsTextures[]=
		{
			"\VRP\HL2Weapons\HL2_USPMatch\data\pistol\usp_match_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"\VRP\HL2Weapons\HL2_USPMatch\data\pistol\usp_match.rvmat"
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
								"\VRP\HL2Weapons\HL2_USPMatch\data\pistol\usp_match.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"\VRP\HL2Weapons\HL2_USPMatch\data\pistol\usp_match.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"\VRP\HL2Weapons\HL2_USPMatch\data\pistol\usp_match_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"\VRP\HL2Weapons\HL2_USPMatch\data\pistol\usp_match_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"\VRP\HL2Weapons\HL2_USPMatch\data\pistol\usp_match_destruct.rvmat"
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
		model="\VRP\HL2Weapons\HL2_USPMatch\data\mag\usp_mag.p3d";
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
								"\VRP\HL2Weapons\HL2_USPMatch\data\pistol\usp_match.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"\VRP\HL2Weapons\HL2_USPMatch\data\pistol\usp_match.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"\VRP\HL2Weapons\HL2_USPMatch\data\pistol\usp_match_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"\VRP\HL2Weapons\HL2_USPMatch\data\pistol\usp_match_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"\VRP\HL2Weapons\HL2_USPMatch\data\pistol\usp_match_destruct.rvmat"
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
		model="\VRP\HL2Weapons\HL2_USPMatch\data\pistol\model.p3d";
	};
	class Proxy_HL2_Mag_USP
	{
		scope=2;
		inventorySlot="magazine";
		model="\VRP\HL2Weapons\HL2_USPMatch\data\mag\model.p3d"
	}
};