import java.util.Scanner;


public class QuadraticRootTool {

	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		
		System.out.print("Enter a, b, c: ");
		
		double a = input.nextDouble();
		double b = input.nextDouble();
		double c = input.nextDouble();
		
		double discrim = b * b - 4 * a * c;
		
		if(discrim < 0)
		{
			System.out.println("The equation has no real roots.");
		}
		else if(discrim > 0)
		{
			double r1 = (-b + Math.sqrt(discrim)) / (2 * a);
			double r2 = (-b - Math.sqrt(discrim)) / (2 * a);
			
			System.out.println("The equation has two roots: "  + r1 + " and " + r2);
		}
		else // if(discrim == 0)
		{
			double r = -b / (2 * a);
			
			System.out.println("The equation has one root: " + r);
		}
	}

}
