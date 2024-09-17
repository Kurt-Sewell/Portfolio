import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.RenderingHints;
import java.awt.geom.RoundRectangle2D;
import java.awt.geom.Arc2D;
import javax.swing.JPanel;

public class Burger extends JPanel{
    boolean hasKetchup;
    boolean hasMayo;
    boolean isWheat;
    boolean isSourDough;

    @Override
    public void paintComponent(Graphics g){
        Graphics2D color = (Graphics2D) g;
        color.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON); //smooths out the painting
        color.setRenderingHint(RenderingHints.KEY_STROKE_CONTROL, RenderingHints.VALUE_STROKE_PURE);
        color.setColor(Color.GRAY);
        color.fillRect(0, 0, this.getWidth(), this.getHeight());

        //creates the condiment object
        Rectangle condiment = new Rectangle(15, 40, 100, 10);
        if(hasKetchup){                                                 //handles the color of the condiment field
            Color condType = new Color(255, 0, 0);
            color.setColor(condType);
            color.fill(condiment);
        }

        else if(hasMayo){
            Color condType = new Color(255, 255, 255);
            color.setColor(condType);
            color.fill(condiment);
        }

        else{
            Color condType = new Color(255, 255, 0);
            color.setColor(condType);
            color.fill(condiment);
        }

        //creates meat
        RoundRectangle2D meat = new RoundRectangle2D.Double(15, 45, 100, 20, 10, 10);
        Color meatColor = new Color(101, 67, 33);
        color.setColor(meatColor);
        color.fill(meat);

        //creates the buns
        Arc2D.Double topBun = new Arc2D.Double(15, 15, 100, 50, 0, 180, Arc2D.PIE);
        Arc2D.Double baseBun = new Arc2D.Double(15, 40, 100, 50, 0, -180, Arc2D.PIE);
        if(isSourDough){                                            //handles the color for the bread fields
            Color bunColor = new Color(194, 161, 83);
            color.setColor(bunColor);
            color.fill(topBun);
            color.fill(baseBun);
        }

        else if(isWheat){
            Color bunColor = new Color(122, 104, 60);
            color.setColor(bunColor);
            color.fill(topBun);
            color.fill(baseBun);
        }

        else{
            Color bunColor = new Color(186, 165, 117);
            color.setColor(bunColor);
            color.fill(topBun);
            color.fill(baseBun);
        }
    }

    public void setCondiment(boolean ketchup, boolean mayo){            //handles condiment type
        hasKetchup = ketchup;
        hasMayo = mayo;
        repaint();
    }

    public void setBread(boolean wheat, boolean sourDough){             //handles bread type
        isWheat = wheat;
        isSourDough = sourDough;
        repaint();
    }

}
