import canvas.Canvas;
import javafx.animation.AnimationTimer;
import shapes.EllipseInRectangle;
import types.Dimension;
import types.Position;

import java.util.LinkedList;
import java.util.Random;
import java.util.Scanner;

public class Main {
    private static Scanner                        scanner;
    private static Random                         random;
    private static LinkedList<EllipseInRectangle> objects;
    private static LinkedList<EllipseInRectangle> removeQueue;

    static {
        scanner = new Scanner(System.in);
        random = new Random();
    }

    public static void main(String[] args) {
        Canvas canvas = Canvas.getInstance();

        final int minX = read("Zadejte minX", new Range(0, (int) canvas.getWidth()));
        final int maxX = read("Zadejte maxX", new Range(minX, (int) canvas.getWidth()));
        final int minY = read("Zadejte minY", new Range(0, (int) canvas.getHeight()));
        final int maxY = read("Zadejte maxY", new Range(minY, (int) canvas.getHeight()));
        final int count = read("Pocet", new Range(0, 100));
        final int vecX = read("Zadejte vektor X", new Range(Integer.MIN_VALUE, Integer.MAX_VALUE));
        final int vecY = read("Zadejte vektor Y", new Range(Integer.MIN_VALUE, Integer.MAX_VALUE));
        final int ms = read("Zadejte cas (ms)", new Range(0, Integer.MAX_VALUE));

        /*TESTVALUES
        final int minX = 100;
        final int maxX = 300;
        final int minY = 100;
        final int maxY = 300;
        final int count = 50;
        final int vecX = 2;
        final int vecY = 2;
        final int ms = 100;*/

        objects = new LinkedList<>();
        removeQueue = new LinkedList<>();
        for (int i = 0; i < count; i++) {
            objects.add(new EllipseInRectangle(
                    new Position(random.nextInt(maxX - minX + 1) + minX,
                                 random.nextInt(maxY - minY + 1) + minY), // Bound must be at least 1
                    new Dimension(random.nextInt(30 - 5) + 5, random.nextInt(30 - 5) + 5)
            ));
        }


        AnimationTimer timer = new AnimationTimer() {
            long last = -1;

            @Override
            public void handle(long now) {
                if (last == -1)
                    last = now;

                if (now < last + ms * 1_000_000)
                    return;

                for (EllipseInRectangle ellipseInRectangle : objects) {


                    Position actual =
                            ellipseInRectangle.setPosition(new Position(ellipseInRectangle.getPosition().x + vecX,
                                                                        ellipseInRectangle.getPosition().y + vecY))
                                              .getPosition();

                    if (actual.x + ellipseInRectangle.getDimension().width < 0 ||
                        actual.x > canvas.getWidth() ||
                        actual.y + ellipseInRectangle.getDimension().height < 0 ||
                        actual.y > canvas.getHeight()) {
                        // Bylo psáno mimo plátno, tudíž se nejspíše nepočítá s min a max hodnotama.

                        removeQueue.add(ellipseInRectangle);
                    }
                }

                for (EllipseInRectangle ellipseInRectangle : removeQueue) {
                    ellipseInRectangle.erase();
                    objects.remove(ellipseInRectangle);
                }
                removeQueue.clear();
                last = now;
            }
        };

        timer.start();
    }

    private static int read(String text, Range range) {
        String input = null;
        int ret = 0;

        while (input == null) {
            System.out.print(String.format("%s <%s, %s>: ", text, range.min != Integer.MIN_VALUE ? range.min : "-∞",
                                           range.max != Integer.MAX_VALUE ? range.max : "+∞"));
            input = scanner.next();

            try {
                ret = Integer.parseInt(input);
                if (ret < range.min || ret > range.max)
                    input = null;
            } catch (Exception e) {
                input = null;
            } finally {
                if (input != null)
                    break;
                else
                    System.out.println("Hodnota neni spravna, prosim opakujte.");
            }
        }

        return ret;
    }

    public static class Range {
        public final int min, max;

        public Range(int min, int max) {
            this.min = min;
            this.max = max;
        }
    }
}
