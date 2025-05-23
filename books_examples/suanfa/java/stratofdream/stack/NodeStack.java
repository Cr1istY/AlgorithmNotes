package cn.foreveryang.stratofdream.stack;

import java.util.Iterator;

public class NodeStack<Item> implements Iterable<Item> {
    private class Node {
        Item item;
        Node next;
    }
    private Node head; // the head of Stack
    private int N; // the length of dates in the Stack
    public boolean isEmpty() { return head == null; }
    public int size() { return N; }
    // push
    public void push(Item item) {
        Node oldFirst = head;
        head = new Node();
        head.item = item;
        head.next = oldFirst;
        N++;
    }
    // pop
    public Item pop() {
        Item temp = head.item;
        head = head.next;
        N--;
        return temp;
    }
    // implements Iterable
    public Iterator<Item> iterator() {
        return new StackIterator();
    }

    private class StackIterator implements Iterator<Item> {
        private Node current = head;
        @Override
        public boolean hasNext() { return current.next != null; }

        @Override
        public void remove() {  }

        public Item next() {
            Item item = current.item;
            current = current.next;
            return item;
        }
    }

}
