public class Hanoi
{
	public static void main(String args[])
	{

		int n	= 0;
		char rod1	= 'D';
		char rod2	= 'D';
		char rod3	= 'D';

		System.out.println("Please enter the quantity of disks:");
		try{
			n = System.in.read();
			System.out.println("Please enter the srcRod:");
			rod1 = (char)System.in.read();
			System.out.println("Please enter the midRod:");
			rod2 = (char)System.in.read();
			System.out.println("Please enter the destRod:");
			rod3 = (char)System.in.read();
			System.out.println("Move " + n + " disks from " + rod1 + " to " + rod2); 
		}catch(Exception e)
		{

		}

		n = 3;
		rod1 = 'A';
		rod2 = 'B';
		rod3 = 'C';

		move(n,rod1,rod2,rod3);
	}

	public static void move(int num,char rod1,char rod2,char rod3)
	{
		if(1 == num)
		{
			System.out.println(rod1 + "-->" + rod3);
			return;
		}

		move(num-1,rod1,rod3,rod2);
		System.out.println(rod1 + "-->" + rod3);
		move(num-1,rod2,rod1,rod3);
	}
}

