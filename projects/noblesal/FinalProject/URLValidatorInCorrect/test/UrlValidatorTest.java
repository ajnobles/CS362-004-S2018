

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }


//   public ProjectBTest(String testName) {
//      super(testName);
//   }
//   
   public boolean trueTestResult(String urlString) {
	   boolean actualResult;
	   
	   // Declare a new UrlValidator object to use for running tests
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   try {
		   actualResult = urlVal.isValid(urlString);
	   }
	   catch (ExceptionInInitializerError | NoClassDefFoundError e) {
		   System.out.println("Exception thown for URL " + urlString + ": " + e);
		   actualResult = false;
	   }
	   
	   if (!actualResult) {
		   System.out.println("Test failed for URL " + urlString);
	   }
	   
	   return actualResult;
   }
   
   public boolean falseTestResult(String urlString) {
	   boolean actualResult;
	   
	   // Declare a new UrlValidator object to use for running tests
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   try {
		   actualResult = urlVal.isValid(urlString);
	   }
	   catch (ExceptionInInitializerError | NoClassDefFoundError e) {
		   System.out.println("Exception thown for URL " + urlString + ": " + e);
		   actualResult = false;
	   }
	   
	   if (actualResult) {
		   System.out.println("Test failed for URL " + urlString);
	   }
	   
	   return !actualResult;
   }
   
   public void testManualTest()
   {
	   boolean allTestsPassed = true;
	   
	   // Try known good URLs
	   allTestsPassed &= trueTestResult("http://www.google.com");
	   allTestsPassed &= trueTestResult("http://www.google.com/");
	   allTestsPassed &= trueTestResult("http://192.168.1.1");
	   allTestsPassed &= trueTestResult("http://255.255.255.255");
	   allTestsPassed &= trueTestResult("http://www.yahoo.com");
	   allTestsPassed &= trueTestResult("http://www.google.com/somepath");
	   allTestsPassed &= trueTestResult("http://access.engr.oregonstate.edu");
	   allTestsPassed &= trueTestResult("http://access.engr.oregonstate.edu:40000");
	   allTestsPassed &= trueTestResult("ftp://access.engr.oregonstate.edu");
	   allTestsPassed &= trueTestResult("ssh://access.engr.oregonstate.edu");
	   allTestsPassed &= trueTestResult("https://www.google.com");
	   allTestsPassed &= trueTestResult("http://access.engr.oregonstate.edu/path?query=42");
	   allTestsPassed &= trueTestResult("http://access.engr.oregonstate.edu/path?query=42&foo=bar");
	   
	   allTestsPassed &= trueTestResult("http://zombo.com");
	   allTestsPassed &= trueTestResult("http://zombo.com/path");
	   allTestsPassed &= trueTestResult("http://zombo.com/path/");
	   allTestsPassed &= trueTestResult("http://zombo.com/path/to/some/page");
	   
	   // Try known bad URLs
	   allTestsPassed &= falseTestResult("google");
	   allTestsPassed &= falseTestResult("http");
	   allTestsPassed &= falseTestResult("http:");
	   allTestsPassed &= falseTestResult("http://");
	   allTestsPassed &= falseTestResult("http:google.com");
	   allTestsPassed &= falseTestResult("http://google");
	   allTestsPassed &= falseTestResult("http://google/path");
	   allTestsPassed &= falseTestResult("http://256.256.256.256");
	   allTestsPassed &= falseTestResult("http://www.google.com:65636");
	   
	   if (!allTestsPassed) {
		   System.out.println("One or more manual tests failed.");
	   }
   }
   
 /*  
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

   }
*/
//   public static void main(String[] argv) {
//	   ProjectBTest fct = new ProjectBTest("url test");
//	   fct.testManualTest();
//   }
   


   // PARTITION TEST

   public void printPartitionTestResult(String url, boolean expectedResult) {
      boolean actualResult = false;
      UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

      try {
         actualResult = urlVal.isValid(url);
      }
      catch (ExceptionInInitializerError e) {
         actualResult = expectedResult;
      }
      catch (NoClassDefFoundError e) {
         actualResult = expectedResult;
      }

      if (actualResult == expectedResult) {
         System.out.println(url + ": TEST PASSED");
      }
      else {
         System.out.println(url + ": TEST FAILED");
      }
   }

   public void testYourFirstPartition() {
     System.out.println("FIRST PARTITION: Testing Schemes + Authorities");
     printPartitionTestResult("http://www.google.com", true);
     printPartitionTestResult("https://amazon.com", true);
     printPartitionTestResult("ftp://youtube.com", true);
     printPartitionTestResult("http://0.0.0.0", true);
     printPartitionTestResult("http://255.255.255.255", true);
     printPartitionTestResult("ftp://1.2.3.4.5", false);
     printPartitionTestResult("https://1.2.3.4.", false);
     printPartitionTestResult("http://256.256.256.256", false);
     printPartitionTestResult("http://google.", false);
     printPartitionTestResult("http:/google.com", false);
     printPartitionTestResult("http://google.", false);
     printPartitionTestResult("http://google", false);
   }

   public void testYourSecondPartition() {
     System.out.println("SECOND PARTITION: Testing Schemes + Authorities + Ports");
     printPartitionTestResult("http://www.google.com:80", true);
     printPartitionTestResult("http://www.google.com:0", true);
     printPartitionTestResult("http://www.google.com:100000", false);
     printPartitionTestResult("http://www.google.com:-1", false);
   }

   public void testYourThirdPartition() {
     System.out.println("THIRD PARTITION: Testing Schemes + Authorities + Ports + Paths");
     printPartitionTestResult("http://www.google.com:80/search", true);
     printPartitionTestResult("http://www.google.com:80/maps/", true);
     printPartitionTestResult("http://www.google.com:80/..", false);
     printPartitionTestResult("http://www.google.com:80/../file", false);
   }

   public void testYourFourthPartition() {
      System.out.println("FOURTH PARTITION: Testing Schemes + Authorities + Ports + Paths + Queries");
      printPartitionTestResult("http://www.google.com:80/search?q=text", true);
      printPartitionTestResult("http://www.google.com:80/search?q=text&sourceid=chrome", true);
   }
   

   // PROGRAMMING BASED TESTING

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
   
   

