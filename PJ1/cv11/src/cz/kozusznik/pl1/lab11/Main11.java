package cz.kozusznik.pl1.lab11;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.nio.charset.Charset;
import java.util.Scanner;
import java.util.zip.GZIPOutputStream;
import java.util.zip.ZipInputStream;

public class Main11 {
	private final static int BUFFER_SIZE = 1024*1024;
	public static void main(String[] args) throws IOException{
		
		String inputFile = "res/Faust-Goethe.txt";
		
		/*fileOutput(inputFile);
		writerOutput(inputFile);
		writerOutputDeflated(inputFile);
		loadBufferedReader(inputFile);
		getWords(inputFile);
		System.out.println("Aritmetický průměr: " + getAverage("res/doubles.txt"));
		saveData();
		readData();*/
		
		zipToGZIP();
		
		
	}

	public static void fileOutput (String inputFile) throws IOException {
		String outputFile = "res/Faust-Goethe2.txt";
		try (InputStream in = new FileInputStream (inputFile);
			OutputStream out = new FileOutputStream (outputFile)) {
			int temp;
			byte[] buffer = new byte [BUFFER_SIZE];
			while ((temp = in.read(buffer)) != -1) {
				out.write(buffer,0,temp);
			}
		}
	}
	
	public static void writerOutput (String inputFile) throws IOException {
		String outputFile = "res/Faust-Goethe3.txt";
		try (Reader in = new FileReader (inputFile);
			 Writer out = new FileWriter (outputFile)) {
			int temp;
			while ((temp = in.read()) != -1) {
				temp = Character.toUpperCase(temp);
				out.write(temp);
				}
			}
	}
	
	public static void writerOutputDeflated (String inputFile) throws IOException {
		String outputFile = "res/Faust-Goethe3.gz";
		
		try (Reader in = new FileReader (inputFile);
			 Writer out = new PrintWriter (new OutputStreamWriter (new GZIPOutputStream(new FileOutputStream(outputFile)),"UTF-8"))) {
			int temp;
			while ((temp = in.read()) != -1) {
				temp = Character.toUpperCase(temp);
				out.write(temp);
				}
			}
	}
	
	public static void loadBufferedReader (String inputFile) throws IOException {
		int i = 0;
		String outputFile = "res/Faust-Goethe4.txt";
		try (BufferedReader in = new BufferedReader (new FileReader(inputFile)) ;
			 BufferedWriter out = new BufferedWriter (new FileWriter(outputFile));
			 PrintWriter out2 = new PrintWriter (new FileWriter ("res/Faust-Goethe5.txt"))) {
			String line;
			while((line=in.readLine())!=null) {
				i++;
				out.write(i + line + "\r\n");
				out2.println(i + " " + line);
			}
		}
	}
	
	public static void getWords (String inputFile) throws IOException {
		String word;
		try (Scanner sc = new Scanner (new BufferedReader(new FileReader(inputFile)))) {
			while ( sc.hasNext()) {
				word = sc.next();
				System.out.println(word);
			}
		}
	}
	
	public static double getAverage (String inputFile) throws IOException {
		double sum = 0;
		int i = 0; 
		try (Scanner sc = new Scanner (new BufferedReader(new FileReader(inputFile)))) {
			while (sc.hasNext()) {
				sum += sc.nextDouble();
				i++;
			}
		}
		return sum/i;
	}
	
	static final double[] prices = { 19.99, 9.99, 15.99, 3.99, 4.99 };
	static final int[] units = { 12, 8, 13, 29, 50 };
	static final String[] descs = {
	  "Java T-shirt",
	  "Java Mug",
	  "Duke Juggling Dolls",
	  "Java Pin",
	  "Java Key Chain"
	};
	
	public static void saveData () throws IOException {
		int i = 0;
		try (DataOutputStream out =	new DataOutputStream (new FileOutputStream("res/data-output.txt"))) {
			for (double price : prices) {
			out.writeDouble(price);
			out.writeInt(units[i]);
			out.writeUTF(descs[i]);
			i++;
			}
		}
	}
	
	public static void readData () throws IOException {
		try (DataInputStream in =	new DataInputStream (new FileInputStream("res/data-output.txt"))) {
			while (in.available() > 0) {
				System.out.println(in.readDouble() + " " +in.readInt() + " " + in.readUTF());
			}
		}
	}
	
	public static void zipToGZIP() throws IOException {
		try(ZipInputStream inZIP = new ZipInputStream (new FileInputStream("res/Faust-Goethe.txt.zip"));
			BufferedReader in = new BufferedReader(new InputStreamReader(inZIP, Charset.forName("utf-8")));
			PrintWriter outGZIP = new PrintWriter (new OutputStreamWriter 
					(new GZIPOutputStream(new FileOutputStream("res/Faust-Goethe-1250.txt.gz")),Charset.forName("windows-1250")))) {
			inZIP.getNextEntry();
			int row = 0;
			String line;
			while((line = in.readLine())!=null ) {
				outGZIP.printf("%d;%d;%s\r\n", row,line.length(),line);
				row++;		
			}
		}
	}
}
