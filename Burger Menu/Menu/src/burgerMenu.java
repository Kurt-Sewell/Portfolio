import javax.swing.JFrame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import javax.swing.JLabel;

public class burgerMenu extends JFrame implements ActionListener{
    private double finalPrice = 4.6;//default price
    private double condPrice = -1;//base case value for if the user goes straight to final screen
    private double breadPrice = -1;//                 ^^^^^
    private JButton ketBut; //adds ketchup
    private JButton mustBut; //adds mustard
    private JButton mayoBut; //adds mayo
    private JButton nextPage1; //goes to page 2
    private JButton lastPage1; // goes to page 1
    private JButton wheatBut; //wheat bread
    private JButton whiteBut; //white bread
    private JButton sourDoughBut; //sourdough bread
    private JButton nextPage2; // goes to page 3
    private JButton lastPage2; //goes to page 2
    private JButton quitBut; //quits the program
    private JLabel price;
    private Burger burger;

    burgerMenu(){
        GridBagConstraints layout = null;

        burger = new Burger();

        setTitle("Build Your Burger");

        price = new JLabel();                           //instantiates ands sets object visibility
        price.setVisible(false);

        ketBut = new JButton("Ketchup");
        ketBut.addActionListener(this);                 //starts waiting for user interaction

        mustBut = new JButton("Mustard");
        mustBut.addActionListener(this);

        mayoBut = new JButton("Mayonnaise");
        mayoBut.addActionListener(this);

        nextPage1 = new JButton("Next Page");
        nextPage1.addActionListener(this);

        lastPage1 = new JButton("Previous Page");
        lastPage1.addActionListener(this);
        lastPage1.setEnabled(false);

        wheatBut = new JButton("Wheat Bread");
        wheatBut.addActionListener(this);
        wheatBut.setVisible(false);

        whiteBut = new JButton("White Bread");
        whiteBut.addActionListener(this);
        whiteBut.setVisible(false);

        sourDoughBut = new JButton("Sourdough Bread");
        sourDoughBut.addActionListener(this);
        sourDoughBut.setVisible(false);

        nextPage2 = new JButton("Next Page");
        nextPage2.addActionListener(this);
        nextPage2.setVisible(false);

        lastPage2 = new JButton("Previous Page");
        lastPage2.addActionListener(this);
        lastPage2.setVisible(false);

        quitBut = new JButton("Quit");
        quitBut.addActionListener(this);

        setLayout(new GridBagLayout());

        layout = new GridBagConstraints();              //places all objects in the GUI
        layout.gridx = 1;
        layout.gridy = 0;
        layout.fill = GridBagConstraints.BOTH;
        add(price, layout);

        layout = new GridBagConstraints();
        layout.gridx = 0;
        layout.gridy = 0;
        layout.gridheight = 3;
        layout.fill = GridBagConstraints.BOTH;
        add(burger, layout);
        
        layout = new GridBagConstraints();
        layout.insets = new Insets(1, 10, 10, 0);
        layout.fill = GridBagConstraints.HORIZONTAL;
        layout.gridx = 1;
        layout.gridy = 0;
        add(ketBut, layout);

        layout = new GridBagConstraints();
        layout.insets = new Insets(1, 10, 10, 0);
        layout.fill = GridBagConstraints.HORIZONTAL;
        layout.gridx = 1;
        layout.gridy = 1;
        add(mustBut, layout);

        layout = new GridBagConstraints();
        layout.insets = new Insets(1, 10, 10, 0);
        layout.fill = GridBagConstraints.HORIZONTAL;
        layout.gridx = 1;
        layout.gridy = 2;
        add(mayoBut, layout);

        layout = new GridBagConstraints();
        layout.insets = new Insets(1, 10, 10, 0);
        layout.fill = GridBagConstraints.HORIZONTAL;
        layout.gridx = 1;
        layout.gridy = 5;
        add(nextPage1, layout);

        layout = new GridBagConstraints();
        layout.insets = new Insets(1, 10, 10, 0);
        layout.fill = GridBagConstraints.HORIZONTAL;
        layout.gridx = 0;
        layout.gridy = 5;
        add(lastPage1, layout);

        layout = new GridBagConstraints();
        layout.insets = new Insets(1, 10, 10, 0);
        layout.fill = GridBagConstraints.HORIZONTAL;
        layout.gridx = 1;
        layout.gridy = 0;
        add(wheatBut, layout);

        layout = new GridBagConstraints();
        layout.insets = new Insets(1, 10, 10, 0);
        layout.fill = GridBagConstraints.HORIZONTAL;
        layout.gridx = 1;
        layout.gridy = 1;
        add(whiteBut, layout);

        layout = new GridBagConstraints();
        layout.insets = new Insets(1, 10, 10, 0);
        layout.fill = GridBagConstraints.HORIZONTAL;
        layout.gridx = 1;
        layout.gridy = 2;
        add(sourDoughBut, layout);

        layout = new GridBagConstraints();
        layout.insets = new Insets(1, 10, 10, 0);
        layout.fill = GridBagConstraints.HORIZONTAL;
        layout.gridx = 1;
        layout.gridy = 5;
        add(nextPage2, layout);

        layout = new GridBagConstraints();
        layout.insets = new Insets(1, 10, 10, 0);
        layout.fill = GridBagConstraints.HORIZONTAL;
        layout.gridx = 0;
        layout.gridy = 5;
        add(lastPage2, layout);

        layout = new GridBagConstraints();
        layout.insets = new Insets(1, 10, 10, 0);
        layout.fill = GridBagConstraints.HORIZONTAL;
        layout.gridx = 2;
        layout.gridy = 5;
        add(quitBut, layout);
    }

    @Override
    public void actionPerformed(ActionEvent event){         //User interaction detected

        JButton source = (JButton) event.getSource();       //Find which object the user interacted with

        if(source == ketBut){
            burger.setCondiment(true, false); // true for ketchup, false for mayo
            condPrice = .15;
        }

        if(source == mustBut){
            burger.setCondiment(false, false);
            condPrice = .10;
        }

        if(source == mayoBut){
            burger.setCondiment(false, true);
            condPrice = .51;
        }

        if(source == nextPage1){
            nextPage1.setVisible(false);
            ketBut.setVisible(false);
            mustBut.setVisible(false);
            mayoBut.setVisible(false);
            wheatBut.setVisible(true);
            whiteBut.setVisible(true);
            sourDoughBut.setVisible(true);
            lastPage1.setEnabled(true);
            nextPage2.setVisible(true);
            pack();                         //resizes the window
        }

        if(source == wheatBut){
            burger.setBread(true, false); //true for wheat, false for sourDough
            breadPrice = 5.00;
        }

        if(source == whiteBut){
            burger.setBread(false, false);
            breadPrice = 4.50;
        }

        if(source == sourDoughBut){
            burger.setBread(false, true);
            breadPrice = 7.25;
        }

        if(source == lastPage1){
            nextPage2.setVisible(false);
            lastPage1.setEnabled(false);
            sourDoughBut.setVisible(false);
            whiteBut.setVisible(false);
            wheatBut.setVisible(false);
            ketBut.setVisible(true);
            mustBut.setVisible(true);
            mayoBut.setVisible(true);
            nextPage1.setVisible(true);
            pack();
        }

        if(source == nextPage2){
            if(breadPrice != -1. || condPrice != -1.){          //if the values have changed from default,
                if(breadPrice == -1){
                    finalPrice = condPrice + 4.5;               //calculate the price
                }

                else if(condPrice == -1){
                    finalPrice = breadPrice + .1;
                }
                
                else{
                    finalPrice = breadPrice + condPrice;
                }
            }
            nextPage2.setEnabled(false);
            lastPage1.setVisible(false);
            sourDoughBut.setVisible(false);
            whiteBut.setVisible(false);
            wheatBut.setVisible(false);
            lastPage2.setVisible(true);
            price.setText("Price: $" + finalPrice);
            price.setVisible(true);
            burger.setVisible(false);
            
        }

        if(source == lastPage2){
            nextPage2.setEnabled(true);
            lastPage1.setVisible(true);
            sourDoughBut.setVisible(true);
            whiteBut.setVisible(true);
            wheatBut.setVisible(true);
            lastPage2.setVisible(false);
            price.setVisible(false);
            burger.setVisible(true);
            
        }

        if(source == quitBut){
            dispose();                              //quits the program
        }
    }
    public static void main(String[] args){
        //Construct the Jframe
        burgerMenu menFrame = new burgerMenu();

        //Configure when to exit the program
        menFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //resizes window
        menFrame.pack();

        //makes the window visible
        menFrame.setVisible(true);
    }    
}
