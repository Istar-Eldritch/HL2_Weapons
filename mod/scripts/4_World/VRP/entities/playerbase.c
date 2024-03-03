modded class PlayerBase
{
    override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
        super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		HL2_StunBaton baton = HL2_StunBaton.Cast(source);
		if(baton)
		{
			baton.OnHit();
			if (baton.IsPoweredOn())
			{
				GiveShock(50);			
			}
		}
	}

	override void OnCommandMelee2Start()
	{
		super.OnCommandMelee2Start();
		if (GetGame().IsServer())
		{
			ItemBase itemInHands = GetItemInHands();
			HL2_StunBaton baton = HL2_StunBaton.Cast(itemInHands);
			if (baton)
			{
				baton.OnSwing(m_MeleeCombat.GetHitType());
			}
		}
	}
}