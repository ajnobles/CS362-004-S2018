

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
//You can use this function to implement y our manual testing	   
	   
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
	   
	   boolean expectedResult;
	   boolean actualResult = true; 
	   
	   String[] trueURL = {"http://www.google.com:80?action=view", 
			   "http://www.google.com:80?action=view"};
	   String[] falseURL = {"http:///aaa.google.com:80?action=view",
			   "http://www.google.com:-1?action=view",
			   "http://www.google.com:80?action=view",
			   "http:///www.google.com:-1?action=view"};
	   
	   
	   // TRUE TEST LOOP
	   expectedResult = true;
	   for (String s: trueURL) {
		   actualResult = urlVal.isValid(s);
		   
		   if (expectedResult != actualResult) {
			   System.out.print(s);
		   }
	   }
	  
	   // FALSE TEST LOOP
	   expectedResult = false;
	   for (String s: falseURL) {
		   actualResult = urlVal.isValid(s);
		   
		   if (expectedResult != actualResult) {
			   System.out.print(s);
		   }
	   }
   }
   
   

}
