import java.util.Arrays;

public class Anagram {

    static boolean isAnagram(char s1[], char s2[]) {

        if (s1.length != s2.length)
            return false;

        Arrays.sort(s1);
        Arrays.sort(s2);

        for (int i = 0; i < s1.length; i++) {
            if (s1[i] != s2[i]) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        String s1 = "cart";
        String s2 = "trac";

        boolean Anagram = isAnagram(s1.toCharArray(), s2.toCharArray());
        if (Anagram)
            System.out.println("True");
        else
            System.out.println("False");

    }

}
