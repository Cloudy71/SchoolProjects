package cz.mil0068.test2;

/*
 * User: MIL0068
 * Date: 20.12.2018
 * Time: 17:25
 */

public class Pair<T1, T2> {
    private T1 t1;
    private T2 t2;

    public Pair(T1 t1, T2 t2) {
        this.t1 = t1;
        this.t2 = t2;
    }

    public T1 getVal1() {
        return t1;
    }

    public void setVal1(T1 t1) {
        this.t1 = t1;
    }

    public T2 getVal2() {
        return t2;
    }

    public void setVal2(T2 t2) {
        this.t2 = t2;
    }
}
