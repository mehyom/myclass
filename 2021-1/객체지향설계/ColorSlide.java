import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;

public class ColorSlide extends JFrame implements ChangeListener {
    ColorPanel canvas = new ColorPanel();
    JSlider red = new JSlider(0, 255, 255);
    JSlider green = new JSlider(0, 255, 0);
    JSlider blue = new JSlider(0, 255, 0);
    public ColorSlide() {
        super("Color Slide");
        setSize(270, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
        
        red.setMajorTickSpacing(50);
        red.setMinorTickSpacing(10);
        red.setPaintTicks(true);
        red.setPaintLabels(true);
        red.addChangeListener(this);
        
        green.setMajorTickSpacing(50);
        green.setMinorTickSpacing(10);
        green.setPaintTicks(true);
        green.setPaintLabels(true);
        green.addChangeListener(this);
        
        blue.setMajorTickSpacing(50);
        blue.setMinorTickSpacing(10);
        blue.setPaintTicks(true);
        blue.setPaintLabels(true);
        blue.addChangeListener(this);
        
        JLabel redLabel = new JLabel("Red: ");
        JLabel greenLabel = new JLabel("Green: ");
        JLabel blueLabel = new JLabel("Blue: ");
        GridLayout grid = new GridLayout(4, 1);
        FlowLayout right = new FlowLayout(FlowLayout.RIGHT);
        Container pane = getContentPane();
        pane.setLayout(grid);
        
        JPanel redPanel = new JPanel();
        redPanel.setLayout(right);
        redPanel.add(redLabel);
        redPanel.add(red);
        pane.add(redPanel);
        JPanel greenPanel = new JPanel();
        greenPanel.setLayout(right);
        greenPanel.add(greenLabel);
        greenPanel.add(green);
        pane.add(greenPanel);
        JPanel bluePanel = new JPanel();
        bluePanel.setLayout(right);
        bluePanel.add(blueLabel);
        bluePanel.add(blue);
        pane.add(bluePanel);        
        pane.add(canvas);
        setContentPane(pane);
    }
    public void stateChanged(ChangeEvent evt) {
        JSlider source = (JSlider)evt.getSource();
        if (source.getValueIsAdjusting() != true) {
            Color current = new Color(red.getValue(), green.getValue(),
                blue.getValue());
            canvas.changeColor(current);
            canvas.repaint();
        }
    }
    public Insets getInsets() {
        Insets border = new Insets(45, 10, 10, 10);
        return border;
    }
    public static void main(String[] arguments) {
        ColorSlide cs = new ColorSlide();
    }
}
class ColorPanel extends JPanel {
    Color background;
    ColorPanel() {
        background = Color.red;
    }
    public void paintComponent(Graphics comp) {
        Graphics2D comp2D = (Graphics2D)comp;
        comp2D.setColor(background);
        comp2D.fillRect(0, 0, getSize().width, getSize().height);
    }
    void changeColor(Color newBackground) {
        background = newBackground;
    }
}
