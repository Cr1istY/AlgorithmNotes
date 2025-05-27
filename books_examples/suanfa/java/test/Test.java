package cn.foreveryang.stratofdream.test;

public class Test {
    static public int change(int p) {
        p = p + 2;
        return p;
    }
    public static void main(String[] args) {
        int i = 3;
        System.out.println(change(i));
        int q = change(i);
        System.out.println(q);
    }
}
