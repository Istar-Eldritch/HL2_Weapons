modded class ModItemRegisterCallbacks
{
	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterOneHanded(pType, pBehavior);
		pType.AddItemInHandsProfileIK("HL2_Mag_USP", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fnp45.anm");
	}

	override void RegisterPistol(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterPistol(pType, pBehavior);
		pType.AddItemInHandsProfileIK("HL2_USPPistolBase","dz/anims/workspaces/player/player_main/weapons/player_main_1911.asi", pBehavior, "dz/anims/anm/player/ik/weapons/1911.anm", "dz/anims/anm/player/reloads/1911/w_1911_states.anm");
	}
}
