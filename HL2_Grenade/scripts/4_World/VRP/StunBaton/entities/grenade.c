class HL2_Grenade: M67Grenade
{
    static const string	NADE_TICK_SOUND_SET = "HL2_Grenade_Tick_SoundSet";

	protected EffectSound m_tickSoundEffect;
	protected HL2_GrenadeLight m_BlinkLight;
    protected bool m_Activated;

    void HL2_Grenade()
    {
        RegisterNetSyncVariableBool("m_Activated");
    }

	override void OnVariablesSynchronized() {
		super.OnVariablesSynchronized();
		if (m_Activated)
		{
			PlayTickSound();
		}
        else
        {
            StopTickSound();
        }
	}

    void PlayTickSound()
    {
        PlaySoundSetLoop(m_tickSoundEffect, NADE_TICK_SOUND_SET, 0, 0);
    }

    void StopTickSound()
    {
        if(m_tickSoundEffect)
        {
            m_tickSoundEffect.Stop();
        }
    }

	void CreateHLLight()
	{
		if (!m_BlinkLight)
			m_BlinkLight = HL2_GrenadeLight.Cast(ScriptedLightBase.CreateLight( HL2_GrenadeLight, "0 0 0"));
		
		m_BlinkLight.PerformVisibilityCheck(this);
		
		EntityAI owner = GetHierarchyParent();
		
		m_BlinkLight.AttachOnObject(this, "0 0.2 0");
	}

    void SetActivated(bool active)
    {
        m_Activated = active;
        SetSynchDirty();
    }

	override protected void Activate()
	{
        super.Activate();
		if (m_FuseTimer.IsRunning())
		{
            CreateHLLight();
            SetActivated(true);
		}
	}

	override protected void OnDeactivate()
	{
        super.OnDeactivate();
		m_BlinkLight.Destroy();
        SetActivated(false);
	}

	override protected void OnActivateFinished()
	{
		super.OnActivateFinished();
		m_BlinkLight.Destroy();
        SetActivated(false);
	}
}

class HL2_GrenadeLight: ScriptedLightBase
{
	private static float m_DefaultBrightness = 500;
	private static float m_DefaultRadius = 0.25;

    void HL2_GrenadeLight()
    {
        SetLightType(LightSourceType.PointLight);
		SetVisibleDuringDaylight( true );
		SetRadiusTo( m_DefaultRadius );
		SetCastShadow( false );
		FadeIn( 0.06 );
		SetBrightnessTo( m_DefaultBrightness );
		SetAmbientColor( 1.0, 0.1, 0.1 );
		SetDiffuseColor( 1.0, 0.1, 0.1 );
		SetFadeOutTime( 0.1 );
	}
	
	void SetIntensity( float coef, float time )
	{
		FadeBrightnessTo( m_DefaultBrightness * coef, time );
		FadeRadiusTo( m_DefaultRadius * coef, time );
	}
	
	void PerformVisibilityCheck(EntityAI owner)
	{
		if (!owner.IsFlagSet(EntityFlags.VISIBLE) && IsEnabled())
		{
			SetEnabled(false);
		}
		else if (owner.IsFlagSet(EntityFlags.VISIBLE) && !IsEnabled())
		{
			SetEnabled(true);
		}
	}
}


class HL2_SmokeGrenade_Red: M18SmokeGrenade_Red {}
class HL2_SmokeGrenade_Green: M18SmokeGrenade_Green {}
class HL2_SmokeGrenade_Yellow: M18SmokeGrenade_Yellow {}
class HL2_SmokeGrenade_Purple: M18SmokeGrenade_Purple {}
class HL2_SmokeGrenade_White: M18SmokeGrenade_White {}