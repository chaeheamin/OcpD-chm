import java.util.Scanner;

public class ChargeProgram {
	
public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("�ݾ��� �Է��ϼ��� >> ");
		int money = scanner.nextInt();
		
		int []coin = {500,100};
		int []count = {0,0};
		
		for(int i=0;i<2;i++) 
			while(money>=coin[i])
			{
				count[i]++;
				money-=coin[i];
			}
		System.out.println("500��¥�� ���� "+count[0]+"��, 100��¥�� ���� "+count[1]+"���� ��ȯ�Ǿ����ϴ�.");
		
		scanner.close();
	}

}
