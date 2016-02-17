/* --------------------------------------------------------------------------
*author: Danilo Assis, Felipe Alves
*date: 16/02/2016
* --------------------------------------------------------------------------
*/

public class Sumarizeimplements  iSumarize{
	
	/* Native methods */
	
	/**
	 *  this method is implemented on cplusplus code
	 *	@Param	A string path for a file
	 */
	public native void summarized(String filepath);

	
	/* Methods called from native code */
	public static int summarize(String filepath)
	{
		System.out.println("Java ainda nao integrado com sumarizador: " + _script_path);
		System.out.println("Devemos fazer a chamada do codigo de virginia aqui.");	

		return 1;
	}
}