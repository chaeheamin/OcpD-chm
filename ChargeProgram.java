import java.util.Scanner;

public class ChargeProgram {
	
public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("금액을 입력하세요 >> ");
		int money = scanner.nextInt();
		
		int []coin = {500,100};
		int []count = {0,0};
		
		for(int i=0;i<2;i++) 
			while(money>=coin[i])
			{
				count[i]++;
				money-=coin[i];
			}
		System.out.println("500원짜리 동전 "+count[0]+"개, 100원짜리 동전 "+count[1]+"개로 교환되었습니다.");
		
		scanner.close();
	}

}
