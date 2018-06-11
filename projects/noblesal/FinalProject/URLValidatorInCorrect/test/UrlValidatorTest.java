

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing	   
	   
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing
	   System.out.print("\n\n*********PROGRAMMING BASED TESTING*********\n");

	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   assertTrue(urlVal.isValid("http://www.google.com"));
	   assertTrue(urlVal.isValid("http:"));
	   
	   
	   boolean expectedResult,
	           actualResult,
	           testRunFail; 
	   
	   // TEST CASES FOR EACH OF scheme, authority, port, and path ALTERNATE FROM TRUE TO FALSE
	   // <TEST STRING ELEMENT NUMBER(ZERO BASED)> % 2 IS USED TO DETERMINE EXPECTED OUTCOME 
	   // EXAMPLE: scheme[0] is a passing case and scheme[1] is a failing test case
	   // 

	   String[] scheme = {
			   "http://",	// TRUE
			   "http??",	// FALSE
			   "ftp://",	// TRUE
			   "ftp:/",		// FALSE
			   "https://",	// TRUE
			   "https:/",	// FALSE
			   ""			// TRUE
			   };
	   
	   String[] authority = {
			   "www.google.com",	// TRUE
			   "ww.google.com",		// FALSE
			   "go.au",				// TRUE
			   "go.a",				// FALSE
			   "255.255.255.255",	// TRUE
			   "256.256.256.256",	// FALSE
			   "255.com",			// TRUE
			   "go.a1a"				// FALSE
			   };
	   
	   String[] port = {
			   ":80", 	// TRUE
			   ":-1",	// FALSE
			   ""		// TRUE
			   };
	   
	   String[] path = {
			   "/path",	// TRUE
			   "//..",		// FALSE
			   "/path/to/some/page", 	// TRUE
			   "/..",		// FALSE
			   ""
			   };
	   
	   String[] query = {
			   ""	// TRUE
			   };
	      
	   // TEST PARTITION COUNT VARIABLES
	   int sCase = 0,
	       aCase = 0,   
	   	   poCase = 0,
	       paCase = 0,
	       quCase = 0,
	       numTest = 0,
	       failedTest = 0,
	       failedRun = 0;

	   for (String s : scheme) {

		   for (String a : authority) {
			   
			   for (String po : port) {

				   for (String pa : path) {

					   testRunFail = false;

					   
					   expectedResult = (
							   (sCase % 2 == 0) 
							   && (aCase % 2 == 0)
							   && (poCase % 2 == 0) 
							   && (paCase % 2 == 0) 
							   && (quCase % 2 == 0)
							   ) ? true : false;

					   
					   StringBuilder testUrl = new StringBuilder();
					   testUrl.append(s);
					   testUrl.append(a);
					   testUrl.append(po);
					   testUrl.append(pa);
					   testUrl.append(query[quCase]);
					   
					   String url = testUrl.toString();

					   try {
					       actualResult = urlVal.isValid(url);
					   }
					   catch (ExceptionInInitializerError | NoClassDefFoundError e) {
						   testRunFail = true;
						   actualResult = expectedResult;
						   System.out.print(e + "\t");
					   }

					   if (testRunFail) {
						   failedRun++;
						   System.out.print(url + "\n");
					   }
					   
					   else if (expectedResult != actualResult) {
						   failedTest++;
						   System.out.print("TEST RESULT FAILED"+ "\tExpected " + expectedResult + "\tReturned " + actualResult + "\t" + url + "\n");
					   }
					   
					   numTest++;
					   paCase++;
				   }
				   
				   poCase++;
			   }
			   
			   aCase++;
		   }
		   
		   sCase++;
	   }
	   System.out.print("numTest: " + numTest + "\n");
	   System.out.print("failedTest: " + failedTest + "\n");
	   System.out.print("failedRuns: " + failedRun + "\n");
   }
}
   
   

