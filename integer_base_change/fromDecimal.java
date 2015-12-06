public int fromDecimal(int n, int b)
{
	   int result=0;
	      int multiplier=1;
	            
	         while(n>0)
			    {
				          result+=n%b*multiplier;
					        multiplier*=10;
						      n/=b;
						         }
		       
		    return result;
}
public String fromDecimal2(int n, int b)
{
	   String chars="0123456789ABCDEFGHIJ";
	      String result="";
	            
	         while(n>0)
			    {
				          result=chars.charAt(n%b) + result;
					        n/=b;
						   }
		       
		    return result;
}
Integer.toBinaryString(n);
Integer.toOctalString(n);
Integer.toHexString(n);
