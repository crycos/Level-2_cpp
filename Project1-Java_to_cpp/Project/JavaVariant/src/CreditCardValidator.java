import java.util.Scanner;

public class CreditCardValidator
{

	public static boolean isValid(long number)
	{
		int numSize = getSize(number);
		
		if(numSize > 16 || numSize < 13) return false;
		
		int sum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
		
		if(sum % 10 != 0) return false;
		
		if(prefixMatched(number, 4)) return true;
		if(prefixMatched(number, 5)) return true;
		if(prefixMatched(number, 37)) return true;
		if(prefixMatched(number, 6)) return true;
		
		return false;
	}
	
	public static int sumOfDoubleEvenPlace(long number)
	{
		int sum = 0;
		
		while(number > 0)
		{
			int digit = (int) ((number % 100) / 10);
			number /= 100;
			
			sum += getDigit(2 * digit);
		}
		
		return sum;
	}
	
	public static int getDigit(int number)
	{
		return (number / 10) + (number % 10); // Still works the same if it's a single digit number.
	}
	
	public static int sumOfOddPlace(long number)
	{
		int sum = 0;
		
		while(number > 0)
		{
			int digit = (int) (number % 10);
			number /= 100;
			
			sum += getDigit(digit);
		}
		
		return sum;
	}
	
	public static boolean prefixMatched(long number, int digit)
	{
		return getPrefix(number, getSize(digit)) == digit;
	}
	
	public static int getSize(long number)
	{
		int digitCount = 0;
		
		while(number > 0)
		{
			number /= 10; // Chop off one digit.
			digitCount++;
		}
		
		return digitCount;
	}
	
	public static long getPrefix(long number, int numDigits)
	{
		int numberSize = getSize(number);
		
		int decimalMovements = numberSize - numDigits;
		
		while(decimalMovements-- > 0)
		{
			number /= 10;
		}
		
		return number;
	}
	
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);

		System.out.print("Enter a credit card number: ");
		long number = input.nextLong();
		System.out.print(number + " is ");
		
		if(isValid(number))
			System.out.println("valid.");
		else
			System.out.println("invalid.");
	}
}
