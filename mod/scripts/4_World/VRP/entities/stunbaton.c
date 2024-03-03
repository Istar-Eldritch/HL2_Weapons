class HL2_StunBaton extends Inventory_Base
{
    static const string	STUN_BATON_HIT_SOUND = "HL2_StunBaton_Hit_SoundSet";
    static const string	STUN_BATON_ON_SOUND = "HL2_StunBaton_On_SoundSet";
    static const string	STUN_BATON_SWING_SOUND = "HL2_StunBaton_Swing_SoundSet";

	protected EffectSound m_hitSoundEffect;
	protected EffectSound m_onSoundEffect;
	protected EffectSound m_swingSoundEffect;

	protected bool m_poweredOnPrev;
	protected bool m_poweredOn;
	protected int m_playHitSoundPrev = 0;
	protected int m_playHitSound = 0;
	protected int m_playSwingSoundPrev = 0;
	protected int m_playSwingSound = 0;
	protected bool m_isHeavyHit = false;

	void HL2_StunBaton()
	{
		m_poweredOn = false;
		RegisterNetSyncVariableBool("m_poweredOn");
		RegisterNetSyncVariableInt("m_playHitSound");
		RegisterNetSyncVariableInt("m_playSwingSound");
		RegisterNetSyncVariableBool("m_isHeavyHit");
	}
	
	void OnHit()
	{
		if (m_poweredOn)
		{
			m_playHitSound++;
			SetSynchDirty();
		}
	}

	void OnSwing(EMeleeHitType hitType)
	{
		if (m_poweredOn)
		{
			m_isHeavyHit = hitType == EMeleeHitType.HEAVY;
			m_playSwingSound++;
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

		if (m_poweredOn && !m_poweredOnPrev)
		{
			PlayOnSound();
		}

		if (m_poweredOn && m_playSwingSound != m_playSwingSoundPrev)
		{
			m_playSwingSoundPrev = m_playSwingSound;
			int soundDelay = 300;
			if (m_isHeavyHit)
			{
				soundDelay = 500;
			}
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PlaySwingSound, soundDelay);
		}
		
		m_poweredOnPrev = m_poweredOn;
	}

    void PlayHitSound()
    {
        PlaySoundSet(m_hitSoundEffect, STUN_BATON_HIT_SOUND, 0, 0);
    }

    void PlayOnSound()
    {
        PlaySoundSet(m_onSoundEffect, STUN_BATON_ON_SOUND, 0, 0);
    }

    void PlaySwingSound()
    {
        PlaySoundSet(m_swingSoundEffect, STUN_BATON_SWING_SOUND, 0, 0);
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

	override bool IsMeleeWeapon()
	{
		return true;
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