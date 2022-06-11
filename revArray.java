public class revArray {

    static void revArrayHere(int a[]) {

        int l = 0;
        int r = a.length - 1;

        while (l < r) {
            int temp;
            temp = a[l];
            a[l] = a[r];
            a[r] = temp;

            r--;
            l++;
        }

        for (int i : a) {
            System.out.print(i + " ");
        }

    }

    public static void main(String[] args) {

        int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
        revArrayHere(a);
    }

}
