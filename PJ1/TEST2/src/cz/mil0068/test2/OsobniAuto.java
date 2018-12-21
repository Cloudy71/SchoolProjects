package cz.mil0068.test2;

/*
 * User: MIL0068
 */

public class OsobniAuto extends Auto implements ITransportOsob {
    private int pocetOsob;

    /**
     * @param typ
     */
    public OsobniAuto(String typ, int pocetOsob) {
        super(typ);
        this.pocetOsob = pocetOsob;
    }

    @Override
    public void jed() {
        System.out.println(String.format("%s: jedu a vezu %d osob%s.", getTyp(), getPocetOsob(),
                                         pocetOsob == 1 ? "u" : (pocetOsob >= 2 && pocetOsob <= 4 ? "y" : "")));
    }

    public int getPocetOsob() {
        return pocetOsob;
    }

    public void setPocetOsob(int pocetOsob) {
        this.pocetOsob = pocetOsob;
    }

    @Override
    public void transportuj() {
        jed();
    }
}
