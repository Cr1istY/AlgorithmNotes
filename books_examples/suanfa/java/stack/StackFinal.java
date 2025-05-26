package cn.foreveryang.stratofdream.stack;

import java.util.Iterator;

@SuppressWarnings("unchecked")
public class StackFinal<Item> implements Iterable<Item> {
    private Item[] a = (Item[]) new Object[1]; // 栈元素
    private int N = 0; //
    public boolean isEmpty() {
        return N == 0;
    }
    public int size() {
        return N;
    }
    private void resize(int max) {
        Item[] temp = (Item[]) new Object[max];
        if (N > 0) {
            System.arraycopy(a, 0, temp, 0, N);
        }
        a = temp;
    }
    public void push(Item item) {
        if (N == a.length) {
            resize(2 * a.length);
        }
        a[N++] = item;
    }
    public Item pop() {
        Item item = a[--N];
        a[N] = null;
        if (N > 0 && N == a.length/4) {
            resize(a.length / 2);
        }
        return item;
    }

    @Override
    public Iterator<Item> iterator() {
        return new ReverseIterator();
    }

    private class ReverseIterator implements Iterator<Item> {
        private int i = N;
        public boolean hasNext() {
            return i > 0;
        }
        public Item next() {
            return a[--i];
        }
        public void remove() {}
    }
}
