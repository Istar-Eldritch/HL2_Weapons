modded class DayZPlayerMeleeFightLogic_LightHeavy
{
    override protected void EvaluateHit_Player(InventoryItem weapon, Object target)
	{
        super.EvaluateHit_Player(weapon, target);
		PlayerBase targetPlayer = PlayerBase.Cast(target);

		//! Melee Hit/Impact modifiers
		if (targetPlayer)
		{
			HL2_StunBaton baton = HL2_StunBaton.Cast(weapon);
            if (baton && baton.IsPoweredOn())
            {
                targetPlayer.m_ShockHandler.SetShock(50);
            }
		}
	}
}