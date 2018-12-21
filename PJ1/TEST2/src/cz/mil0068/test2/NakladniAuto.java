package cz.mil0068.test2;

/*
 * User: MIL0068
 */

public class NakladniAuto extends Auto {
    private int hmotnostNakladu; // Kg

    /**
     * @param typ
     */
    public NakladniAuto(String typ, int hmotnostNaklad) {
        super(typ);
        this.hmotnostNakladu = hmotnostNaklad;
    }

    @Override
    public void jed() {
        System.out.println(String.format("%s: jedu a vezu naklad o %.2f tun.", getTyp(), getHmotnostVTunach()));
    }

    public int getHmotnostNakladu() {
        return hmotnostNakladu;
    }

    public void setHmotnostNakladu(int hmotnostNakladu) {
        this.hmotnostNakladu = hmotnostNakladu;
    }

    public double getHmotnostVTunach() {
        return this.hmotnostNakladu / 1000.0;
    }
}
