package tema8;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Tema8 implements ActionListener  {
JTextField  Redak1;
JTextField  Redak2;
JTextField  Redak3;
Tema8() {
JFrame Pole1=new JFrame("1+1"); 
Pole1.getContentPane().setLayout(new FlowLayout());
Pole1.setSize(470,280);
Pole1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


JLabel poltext1=new JLabel("Enter the first day of:");
JLabel poltext2=new JLabel("Enter the second:");
JLabel poltext3=new JLabel("Result:");
Redak1=new  JTextField(40);
Redak2=new  JTextField(40);
Redak3=new  JTextField(40);
Redak1.setActionCommand("Inspection");
Redak2.setActionCommand("Addition");
Redak1.addActionListener(this);
Redak2.addActionListener(this);
Pole1.getContentPane().add(poltext1);
Pole1.getContentPane().add(Redak1);
Pole1.getContentPane().add(poltext2);
Pole1.getContentPane().add(Redak2);
Pole1.getContentPane().add(poltext3);
Pole1.getContentPane().add(Redak3);

JButton knopVvod=new JButton("Inspection");
JButton knopSbros=new JButton("Addition of a ternary system calculation");

knopVvod.addActionListener(this);
knopSbros.addActionListener(this);

Pole1.getContentPane().add((knopVvod));
Pole1.getContentPane().add((knopSbros)); 
Pole1.setVisible(true);
}
public void actionPerformed(ActionEvent sob){
 
	if (sob.getActionCommand().equals("Inspection"))
		
{

	 StringBuffer str=new StringBuffer(Redak3.getText());
		String s = Redak1.getText();
		String e1 = Redak2.getText();
		int d = Integer.valueOf(s);
		int dd = Integer.valueOf(e1);
		boolean isBinary=true;
        while (d != 0) 
        {
            if (d % 10 > 1) 
            {
                 isBinary=false;
  
            }
            d = d / 10;
        }
        while (dd != 0) 
        {
            if (dd % 10 > 1) 
            {
                 isBinary=false;
  
            }
            dd = dd / 10;
        }
		if (isBinary==false){
		
			Redak3.setText("You entered no binary numbers");
		}
		else 
		{
			Redak3.setText("You enter binary numbers");
		}
		
}

else {
	 StringBuffer str1=new StringBuffer(Redak3.getText());
	 String s1 = Redak1.getText();
		String e = Redak2.getText();
		
			int z=Integer.parseInt(s1,3);
			int z1=Integer.parseInt(e,3);
			
			int zz=z+z1;
		    String st = Double.toString(zz);
		    
			Redak3.setText(st);
		
}}

public static void main(String args[]){
    SwingUtilities.invokeLater(new Runnable(){
public  void run(){
  new Tema8();
}});}}
