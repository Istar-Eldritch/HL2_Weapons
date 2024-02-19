class HL2_StunBaton extends Inventory_Base
{
	protected bool m_poweredOn;

	void StunBaton()
	{
		m_poweredOn = false;
	}

    bool IsPoweredOn()
    {
        return m_poweredOn;
    }

	override void OnWorkStart()
	{
		m_poweredOn = true;
	}
	
	override void OnWorkStop()
	{
		m_poweredOn = false;
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