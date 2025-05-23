package cn.foreveryang.stratofdream.stack;

public class Test {
    public static void main(String[] args) {
        Stack<String> stack = new Stack<>(2);
        stack.push("a");
        stack.push("b");
        stack.push("c");
        stack.push("d");
        stack.push("e");
        System.out.println(stack.isEmpty());
        for (int i = 0; i < 5; i++) {
            System.out.println(stack.pop());
        }
        System.out.println(stack.isEmpty());
    }
}
