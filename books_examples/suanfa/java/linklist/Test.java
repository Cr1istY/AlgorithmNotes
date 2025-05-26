package cn.foreveryang.stratofdream.linklist;

public class Test {
    public static void main(String[] args) {
        // at first, we should create some Nodes work for our linklist
        Node<String> first = new Node<>();
        Node<String> second = new Node<>();
        Node<String> third = new Node<>();
        // and then, we need make each of them has a real data
        first.data = "first";
        second.data = "second";
        third.data = "third";
        // to make sure those Nodes work, we need set their next value by hand
        first.next = second;
        second.next = third;
        // add Node at the head of a linklist
        // 1. create a Node
        // 2. midNode.next = first
        Node<String> oldFirst = first;
        first = new Node<>();
        first.data = "zero";
        first.next = oldFirst;
        // check the result
        Node<String> temp = first;
        while (temp != null) {
            System.out.println(temp.data);
            temp = temp.next;
        }
        System.out.println(" ");
        // delete the zero node
        first = first.next;

        Node<String> temp_1 = first;
        while (temp_1 != null) {
            System.out.println(temp_1.data);
            temp_1 = temp_1.next;
        }


    }
}
