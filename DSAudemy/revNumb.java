package DSAudemy;

public class revNumb {

    static int revNumber(int a) {
        int num = 0;

        while (a != 0) {
            int digit = a % 10;
            a = a / 10;
            num = num * 10 + digit;
        }
        return num;
    }

    public static void main(String[] args) {

        int a = 1234;
        int b = revNumber(a);
        System.out.println(b);

    }

}
