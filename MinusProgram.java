import java.util.Scanner;

public class MinusProgram {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("�� ���� ���ڸ� �Է��ϼ��� : ");
		double a = scanner.nextDouble();
		double b = scanner.nextDouble();
		
		double result = a-b;
		System.out.println("�� ���� ���� = "+result+" �Դϴ�");
		
		scanner.close();
	}

}
