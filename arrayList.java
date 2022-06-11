import java.util.ArrayList;
import java.util.List;

public class arrayList {

    public static void main(String[] args) {

        List<Integer> list = new ArrayList<Integer>();

        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);

        System.out.println(list.size());

        for (int i : list) {
            System.out.println(i);
        }

    }

}