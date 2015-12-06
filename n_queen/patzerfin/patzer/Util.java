// Jeff Somers
// 1/7/2000

public final class Util 
{
	Util() {};

	private static boolean _assertsOn = false;

	static void setAsserts(boolean newval)
	{
		_assertsOn = newval;
	}

	static void assert(boolean expression) throws patzException
	{
		if (_assertsOn && !expression) {
			throw new patzException("Assertion failed!");
		}
	}
	
}