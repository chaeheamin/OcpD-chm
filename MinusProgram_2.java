import java.util.Scanner;

public class MinusProgram_2 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("�� ���� ���ڸ� �Է��ϼ��� : ");
		double a = scanner.nextDouble();
		double b = scanner.nextDouble();
		
		double result;
		if(a>b) result=a-b;
		else result = b-a;
		System.out.println("�� ���� ���� = "+result+" �Դϴ�");
		
		scanner.close();
	}

}
