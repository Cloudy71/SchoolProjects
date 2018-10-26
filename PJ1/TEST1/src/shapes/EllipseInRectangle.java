package shapes;

import canvas.Canvas;
import types.Dimension;
import types.MyColor;
import types.Position;

public class EllipseInRectangle {
    private Position  position;
    private Dimension dimension;

    private static Canvas CANVAS = Canvas.getInstance();

    public EllipseInRectangle(Position position, Dimension dimension) {
        this.position = position;
        this.dimension = dimension;
        erase();
        paint();
    }

    public EllipseInRectangle(Position position) {
        this(position, new Dimension(50, 50));
    }

    public EllipseInRectangle() {
        this(new Position(0, 0));
    }

    public EllipseInRectangle setPosition(Position position) {
        erase();
        this.position = position;
        paint();
        return this;
    }

    public Position getPosition() {
        return position;
    }

    public Dimension getDimension() {
        return dimension;
    }

    public void erase() {
        CANVAS.erase(new java.awt.geom.Ellipse2D.Double(position.x, position.y, dimension.width,
                                                        dimension.height));
        CANVAS.erase(new java.awt.geom.Rectangle2D.Double(position.x, position.y, dimension.width,
                                                          dimension.height));
        // Had to add ellipse erasing, because artifacts from ellipse were appearing, i could use rectangle2d and add +- 1, but it would make mess,
        // like erasing some space out of rectangle, which could clear space where was another shape.
        // It still makes some artifacts, cause is unknown...
    }

    public void paint() {
        CANVAS.setColorOfForeground(MyColor.BLUE);
        CANVAS.fill(new java.awt.geom.Rectangle2D.Double(position.x, position.y, dimension.width, dimension.height));
        CANVAS.setColorOfForeground(MyColor.YELLOW);
        CANVAS.fill(new java.awt.geom.Ellipse2D.Double(position.x, position.y, dimension.width, dimension.height));
    }
}
