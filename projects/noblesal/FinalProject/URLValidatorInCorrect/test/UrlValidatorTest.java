

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
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //boolean test = urlVal.isValid("http://ww.google.com");
	   //System.out.print(test + "\n");
	   
	   boolean expectedResult,
	           actualResult,
	           testRunFail; 
	   /*
	   String[] trueURL = {"http://www.google.com:80?action=view", 
			   "https://www.google.com:80?action=view",
			   "http://www.google.com:80?action=view",
			   "http://www.google.com?action=view"};
	   
	   String[] falseURL = {"http:///aaa.google.com:80?action=view",
			   "http://www.google.com:-1?action=view",
			   "http://www.google.m:80?action=view",
			   "http:///www.google.com:-1?action=view",
			   "http://www.google.com?80?action=view"};
	   
	   
	   // TRUE TEST LOOP
	   expectedResult = true;
	   for (String s: trueURL) {
		   actualResult = urlVal.isValid(s);
		   
		   if (expectedResult != actualResult) {
			   System.out.print(s + "\tTEST FAILED\n");
		   }
	   }
	  
	   // FALSE TEST LOOP
	   expectedResult = false;
	   for (String s: falseURL) {
		   actualResult = urlVal.isValid(s);
		   
		   if (expectedResult != actualResult) {
			   System.out.print(s + "\tTEST FAILED\n");
		   }
	   }
	   */
	   
	   // ftp;// causing error
	   String[] scheme = {
			   "http://", 
			   "http??",
			   "ftp://",
			   "ftp:/",
			   "https://",
			   "https:/"
			   };
	   
	   String[] authority = {
			   "www.google.com",
			   "ww.google.com",
			   "go.au",
			   "go.a",
			   "255.255.255.255",
			   "255.255.256.256"
			   };
	   
	   String[] port = {
			   "",
			   "80",
			   ":80", 
			   ":-1"
			   };
	   
	   String[] path = {
			   "",
			   "//..",
			   "/test1", 
			   "/.."		   
			   };
	      
	   int sCase = 0;
	   int aCase = 0;	   
	   int poCase = 0;
	   int paCase = 0;
	   int numTest = 0;

	   for (String s : scheme) {
		   
		   
		   for (String a : authority) {

			   
			   for (String po : port) {


				   for (String pa : path) {

					   testRunFail = false;

					   expectedResult = (sCase % 2 == 0 && aCase % 2 == 0 
							   && poCase % 2 == 0 && paCase % 2 == 0) 
							   ? true : false;

					   
					   StringBuilder testUrl = new StringBuilder();
					   testUrl.append(s);
					   testUrl.append(a);
					   testUrl.append(po);
					   testUrl.append(pa);
					   
					   String url = testUrl.toString();

					   try {
					       actualResult = urlVal.isValid(url);
					   }
					   catch (ExceptionInInitializerError e) {
						   testRunFail = true;
						   actualResult = expectedResult;
					   }
					   catch (NoClassDefFoundError e) {
						   testRunFail = true;
						   actualResult = expectedResult;
					   }
					   
					   
					   if (testRunFail) {
						   System.out.print("TEST RUN FAILED\t" + url + "\n");
					   }
					   
					   else if (expectedResult != actualResult) {
						   System.out.print("TEST RESULT FAILED"+ "\tExpected " + expectedResult + "\tReturned " + actualResult + "\t" + url + "\n");
					   }
					   
					   //System.out.print(url + "\tExpected " + expectedResult + "\tReturned " + actualResult + "\n");

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
   }
}
   
   

