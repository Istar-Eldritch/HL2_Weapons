class HL2_StunBaton extends Inventory_Base
{
    static const string	STUN_BATON_HIT_SOUND = "HL2_StunBaton_Hit_SoundSet";
	
	protected EffectSound m_hitSoundEffect;

	protected bool m_poweredOn;
	protected int m_playHitSoundPrev = 0;
	protected int m_playHitSound = 0;
	
	void HL2_StunBaton()
	{
		m_poweredOn = false;
		RegisterNetSyncVariableBool("m_poweredOn");
		RegisterNetSyncVariableInt("m_playHitSound");
	}
	
	void OnHit()
	{
		if (m_poweredOn)
		{
			m_playHitSound++;
			SetSynchDirty();
		}
	}
	
	override void OnVariablesSynchronized() {
		super.OnVariablesSynchronized();
		if (m_poweredOn && m_playHitSound != m_playHitSoundPrev)
		{
			m_playHitSoundPrev = m_playHitSound;
			PlayHitSound();
		}
	}

    void PlayHitSound()
    {
        PlaySoundSet(m_hitSoundEffect, STUN_BATON_HIT_SOUND, 0, 0);
    }

    bool IsPoweredOn()
    {
        return m_poweredOn;
    }

	override void OnWorkStart()
	{
		m_poweredOn = true;
		SetSynchDirty();
	}
	
	override void OnWorkStop()
	{
		m_poweredOn = false;
		SetSynchDirty();
	}
	
	override int GetMeleeMode()
	{
		return 0;
	}

	override int GetMeleeHeavyMode()
	{
		return 1;
	}
	
	override int GetMeleeSprintMode()
	{
		return 2;
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTurnOnWhileInHands);
		AddAction(ActionTurnOffWhileInHands);
	}
}