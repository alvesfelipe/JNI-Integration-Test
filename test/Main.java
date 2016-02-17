/* --------------------------------------------------------------------------
*author: Danilo Assis, Felipe Alves
*date: 16/02/2016
* --------------------------------------------------------------------------
*/

import java.lang.System;
import java.lang.UnsatisfiedLinkError;

public class Main
{
	static {
		System.loadLibrary("main_controller");		
	}

	public static void main (String [] args)
	{
		try
		{
			Sumarize summ = new Sumarize();
			summ.summarized("Here is Java");
		}
		catch (UnsatisfiedLinkError ex)
		{	
			ex.printStackTrace();
			System.out.println(ex.getMessage());
		}		
	}
}