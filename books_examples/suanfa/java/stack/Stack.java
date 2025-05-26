package cn.foreveryang.stratofdream.stack;

@SuppressWarnings("unchecked")
public class Stack<T> {
    private T[] a;
    private int n;

    public Stack(int cap) {
        a = (T[]) new Object[cap];
        n = -1;
    }
    public boolean isEmpty() {
        return n == -1;
    }

    public int size() {
        return n + 1;
    }

    // 当栈的长度不够时，考虑对栈进行扩容
    public void push(T x) {
        if (n + 1 == a.length) {
            resize(2 * a.length);
        }
        n += 1;
        a[n] = x;
    }

    // 当栈的长度过长时，考虑对栈进行缩容
    public T pop() {
        T temp = a[n];
        a[n] = null;
        n -= 1;
        if (n <= a.length / 4 && n >= 0) {
            resize(a.length / 2);
        }

        return temp;
    }

    private void resize(int cap) {
        T[] temp = (T[]) new Object[cap];
        if (n + 1 > 0) System.arraycopy(a, 0, temp, 0, n + 1);
        a = temp;
    }
}
