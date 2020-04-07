import java.util.Scanner;

public class MinusProgram_2 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("두 개의 숫자를 입력하세요 : ");
		double a = scanner.nextDouble();
		double b = scanner.nextDouble();
		
		double result;
		if(a>b) result=a-b;
		else result = b-a;
		System.out.println("두 수의 차는 = "+result+" 입니다");
		
		scanner.close();
	}

}
